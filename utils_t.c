/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:59:16 by ialgac            #+#    #+#             */
/*   Updated: 2022/12/04 15:50:05 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *s)
{
	ft_putstr(s);
	exit(0);
}

char	*ft_itob(int x)
{
	char	*bin;
	char	b[2];
	int		i;

	b[0] = '0';
	b[1] = '1';
	bin = malloc(9);
	i = 1;
	while (i <= 8)
	{
		bin[8 - i] = b[x % 2];
		x = x / 2;
		i = i + 1;
	}
	bin[8] = 0;
	return (bin);
}
