/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:53:46 by sla-gran          #+#    #+#             */
/*   Updated: 2025/11/04 10:53:46 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(void const *p)
{
	unsigned long	adr;
	char const		*base;
	char			res[9];
	int				i;
	int				count;

	adr = (unsigned long) p;
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	count = 2;
	res[i] = base[(adr % 16)];
	write(1, "0x", 2);
	while (i < 9)
	{
		write(1, &res[i], 1);
		i++;
		count++;
	}
	return (count);
}
/*
#include <stdio.h>
int main (void)
{
   char const *p = "hello";
 
   printf ("%p\n", (void *) p);
   ft_putvoid (p);
 
   return 0;
}*/
