/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:54:51 by ialgac            #+#    #+#             */
/*   Updated: 2022/03/07 17:58:50 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char x)
{
	write (1, &x, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_atoi(char *str)
{
	int	rtn;
	int	isneg;

	rtn = 0;
	isneg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		isneg -= (*str++ == '-') * 2;
	while (*str >= '0' && *str <= '9')
		rtn = *str++ - '0' + rtn * 10;
	return (rtn * isneg);
}

void	ft_putnbr(int x)
{
	if (x == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (x < 0)
		x = x * -1;
	if (x >= 10)
		ft_putnbr(x / 10);
	ft_putchar((x % 10) + 48);
}
