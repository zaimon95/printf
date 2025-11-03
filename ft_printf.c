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

	va_start(args, s);
	while (!s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c')
				ft_putchar_fd((char)va_arg(args, char), 1);
			else if (s[i] == 'd')
				ft_putnbr_fd((int)va_arg(args, int), 1);
			else if (s[i] == 's')
				ft_putstr_fd((char *)va_arg(args, char*), 1);
			else if (s[i] == 'u')
				break;
			else if (s[i] == 'i')	
				ft_putnbr_fd((int)va_arg(args, int), 1);
			else if (s[i] == 'x')
				break;
			else if (s[i] == 'X')
				break;
			else if (s[i] == '%')
				ft_putchar_fd('%', 1);
			else if (s[i] == 'p')
				break;
		}
		else
		{
			ft_putchar_fd(*p, 1);
		}
		i++;
	}
	va_end(args);
}
