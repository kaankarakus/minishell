/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:50:49 by kkarakus          #+#    #+#             */
/*   Updated: 2024/09/11 12:50:51 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	state_smash(t_state **state)
{
	if (!state || !*state)
		return ;
	free((*state)->prompt);
	(*state)->prompt = NULL;
	token_arr_smash(&(*state)->token_arr);
}

void	smash_prompt(t_state *state)
{
	if (state)
	{
		free(state->prompt);
		state->prompt = NULL;
	}
	if (state->token_arr)
		token_arr_smash(&state->token_arr);
}

void	state_smash_single(t_state **state)
{
	int	i;

	if (!state || !*state)
		return ;
	i = 0;
	while ((*state)->env && (*state)->env[i])
		free((*state)->env[i++]);
	free((*state)->env);
	(*state)->env = NULL;
	free((*state)->prompt);
	(*state)->prompt = NULL;
}

void	smash_paths(char **paths)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}
