/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:32:44 by shassoun          #+#    #+#             */
/*   Updated: 2023/12/09 16:04:47 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr_unsigned(int nb);
int	ft_putnbr_hexa(unsigned long nb, char c);
int	ft_putnbr(long n);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(char *s, ...);

#endif
