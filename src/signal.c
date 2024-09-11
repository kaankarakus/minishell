/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:50:43 by kkarakus          #+#    #+#             */
/*   Updated: 2024/09/11 12:50:45 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ctrl_d(int sig)
{
	(void)sig;
	rl_on_new_line();
	write(1, "\033[K", 3);
	rl_redisplay();
	g_sig = 0;
}

void	ctrl_c(int sig)
{
	(void)sig;
	if (g_sig == IN_HEREDOC)
	{
		write(1, "\033[A", 3);
		ioctl(0, TIOCSTI, "\n");
	}
	else if (g_sig == IN_CMD)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		g_sig = AFTER_CMD;
	}
	else
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_sig = 1;
}

void	tcseta(void)
{
	struct termios	term1;

	if (tcgetattr(STDIN_FILENO, &term1) != 0)
		exit((perror("error"), -1));
	else
	{
		term1.c_cc[VQUIT] = _POSIX_VDISABLE;
		term1.c_lflag |= ECHOE | ICANON;
		if (tcsetattr(STDIN_FILENO, TCSANOW, &term1) != 0)
			exit((perror("error"), -1));
		if (tcgetattr(STDIN_FILENO, &term1) != 0)
			exit((perror("error"), -1));
	}
}

void	handle_signals(void)
{
	tcseta();
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, ctrl_d);
}
