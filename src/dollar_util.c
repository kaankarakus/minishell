/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:47:47 by kkarakus          #+#    #+#             */
/*   Updated: 2024/09/11 12:47:49 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	is_valid_dollar(char *data, int i)
{
	return (data[i] == '$' && (is_alpha(data[i + 1]) || data[i + 1] == '_'
			|| is_digit(data[i + 1]) || data[i + 1] == '?'));
}

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool	is_alnum_underscore(char c)
{
	return (is_digit(c) || is_alpha(c) || c == '_');
}
