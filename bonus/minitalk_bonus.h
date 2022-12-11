/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialgac <ialgac@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:07:36 by ialgac            #+#    #+#             */
/*   Updated: 2022/03/07 18:07:38 by ialgac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putchar(char x);
void	ft_putstr(char *str);
void	ft_putnbr(int x);
char	*ft_itob(int c);
int		ft_atoi(char *str);
void	ft_error(char *s);

#endif
