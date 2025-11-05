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

#include "ft_printf.h"

void	if_cond(const char *s, size_t i, va_list args, int count)
{
	if (s[i] == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		count++;
	}
	else if (s[i] == 'd')
		count += ft_putnbr_fd((int)va_arg(args, int), 1);
	else if (s[i] == 's')
		count += ft_putstr_fd((char *)va_arg(args, char *), 1);
	else if (s[i] == 'u')
		return ;
	else if (s[i] == 'i')
		count += ft_putnbr_fd((int)va_arg(args, int), 1);
	else if (s[i] == 'x')
		count += ft_putnbr_base((int)va_arg(args, int), "0123456789abcdef");
	else if (s[i] == 'X')
		count += ft_putnbr_base((int)va_arg(args, int), "0123456789ABCDEF");
	else if (s[i] == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
	}
	else if (s[i] == 'p')
		count += ft_putvoid((void *)va_arg(args, void *));
}

int	ft_printf(const char *s, ...)
{
	int count;
	va_list	args;
	size_t	i;

	va_start(args, s);
	i = 0;
	while (!s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if_cond(s, i, args, count);
		}
		else
		{
			ft_putchar_fd(*s, 1);
			count++;
		}
		i++;
	}
	return (count);
	va_end(args);
}
