/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:46:48 by kkarakus          #+#    #+#             */
/*   Updated: 2024/09/11 12:46:51 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static bool	data_is_build_in(const char *str)
{
	if (!str)
		return (false);
	if (ft_strncmp(str, "echo", 5) == 0)
		return (true);
	else if (ft_strncmp(str, "cd", 3) == 0)
		return (true);
	else if (ft_strncmp(str, "pwd", 4) == 0)
		return (true);
	else if (ft_strncmp(str, "export", 7) == 0)
		return (true);
	else if (ft_strncmp(str, "unset", 6) == 0)
		return (true);
	else if (ft_strncmp(str, "env", 4) == 0)
		return (true);
	else if (ft_strncmp(str, "exit", 5) == 0)
		return (true);
	return (false);
}

bool	token_is_built_in(t_token *token)
{
	if (!token || token->type != CMD)
		return (false);
	return (data_is_build_in(token->data));
}
