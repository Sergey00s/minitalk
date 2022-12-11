/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:00:33 by ialgac            #+#    #+#             */
/*   Updated: 2022/03/07 18:00:35 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int ac, char **av)
{
	int	spid;
	int	i;

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
