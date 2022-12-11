/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:05:59 by ialgac            #+#    #+#             */
/*   Updated: 2022/03/07 18:07:26 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_geldi = 0;

void	ft_send_char_to_server(unsigned char c, int spid)
{
	char	*bit;
	int		i;

	bit = ft_itob(c);
	i = -1;
	while (bit[++i])
	{
		if (bit[i] == '1')
		{
			if (kill(spid, SIGUSR1) == -1)
				ft_error("SIGUSR1 NOT SEND\n");
		}
		else if (bit[i] == '0')
		{
			if (kill(spid, SIGUSR2) == -1)
				ft_error("SIGUSR2 NOT SEND\n");
		}
		usleep (100);
	}
	free(bit);
}

void	sig_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)ucontext;
	(void)siginfo;
	if (signum == SIGUSR1 && !g_geldi)
	{
		ft_putstr("SUCCESFUL!");
		g_geldi = 1;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					spid;
	int					i;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	if (ac == 3)
	{
		spid = ft_atoi(av[1]);
		if (spid <= 0)
			ft_error("[ INVALID SERVER PID ]\n");
		i = -1;
		while (av[2][++i])
			ft_send_char_to_server(av[2][i], spid);
	}
	else
		ft_error("[ INVALID NUMBER OF ARGUMENTS ]\n");
	return (0);
}
