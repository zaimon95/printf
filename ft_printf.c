/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:32:05 by sla-gran          #+#    #+#             */
/*   Updated: 2025/10/31 10:32:05 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	va_list args;
	size_t	i;

	va_start(args, s);
	i = 0;
	while (!s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if_cond(s, i, args);
		}
		else
			ft_putchar_fd(*p, 1);
		i++;
	}
	va_end(args);
}

void	if_cond(const char *s, size_t  i, va_list args)
{
	if (s[i] == 'c')
		ft_putchar_fd((char)va_arg(args, char), 1);
		else if (s[i] == 'd')
			ft_putnbr_fd((int)va_arg(args, int), 1);
		else if (s[i] == 's')
			ft_putstr_fd((char *)va_arg(args, char*), 1);
		else if (s[i] == 'u')
			break; //unsigned int
		else if (s[i] == 'i')	
			ft_putnbr_fd((int)va_arg(args, int), 1);
		else if (s[i] == 'x')
			break; //hexadecimal => putnbr_base atoi_base a faire
		else if (s[i] == 'X')
			break; //hexadecimal => putnbr_base ou atoi_base a faire
		else if (s[i] == '%')
			ft_putchar_fd('%', 1);
		else if (s[i] == 'p')
			break; //print pointeur void
}
