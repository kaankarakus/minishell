/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:50:01 by kkarakus          #+#    #+#             */
/*   Updated: 2024/09/11 12:50:02 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	run_pwd(t_cmd *cmd, t_state *state)
{
	char	cwd[PATH_MAX];

	if ((getcwd(cwd, sizeof(cwd)) == 0) || ft_strlen(cwd) == 0)
		return (FAILURE);
	dprintln(cmd->bout, cwd);
	state->status = 0;
	return (SUCCESS);
}
