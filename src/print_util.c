/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:49:55 by kkarakus          #+#    #+#             */
/*   Updated: 2024/09/11 12:49:56 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	dprint(int fd, const char *s)
{
	write(fd, s, ft_strlen(s));
}

void	dprintln(int fd, const char *s)
{
	dprint(fd, s);
	dprint(fd, ENDL);
}

void	eprint(const char *str)
{
	dprint(STDERR_FILENO, str);
}

void	eprintln(const char *str)
{
	dprintln(STDERR_FILENO, str);
}
