/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:07:57 by ialgac            #+#    #+#             */
/*   Updated: 2022/03/07 18:08:54 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_power(int x)
{
	int	rtn;

	if (x == 0)
		return (1);
	if (x < 0)
		return (0);
	rtn = 1;
	while (x)
	{
		rtn = rtn * 2;
		x--;
	}
	return (rtn);
}

void	sig_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	static int		p ;
	static int		ascii ;
	static int		cpid;
	static int		ocpid;

	(void)siginfo;
	(void)ucontext;
	cpid = siginfo->si_pid;
	if (cpid != ocpid && cpid != 0)
	{
		ocpid = cpid;
		p = 8;
		ascii = 0;
	}
	if (signum == SIGUSR1)
		ascii += ft_power(p - 1);
	p--;
	if (p == 0)
	{
		ft_putchar(ascii);
		p = 8;
		ascii = 0;
		if (kill(siginfo->si_pid, SIGUSR1))
			ft_putstr("SIGUSR1 gonderilemedi!");
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	pid = getpid();
	ft_putstr("PID -> ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
