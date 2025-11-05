/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:34:34 by sla-gran          #+#    #+#             */
/*   Updated: 2025/11/04 10:34:34 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid(char *base)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i >= 2);
}

static int	handle_min_int(int nbr, char *base, size_t base_len)
{
	char	c;
	int		count;

	write(1, "-", 1);
	count = 1;
	count += ft_putnbr_base(-(nbr / (int)base_len), base);
	c = base[-(nbr % (int)base_len)];
	write(1, &c, 1);
	return (count + 1);
}

static int	handle_negative(int nbr, char *base)
{
	int	count;

	write(1, "-", 1);
	count = 1;
	count += ft_putnbr_base(-nbr, base);
	return (count);
}

int	ft_putnbr_base(int nbr, char *base)
{
	size_t	base_len;
	char	c;
	int		count;

	base_len = ft_strlen(base);
	count = 0;
	if (!is_valid(base))
		return (0);
	if (nbr == -2147483648)
		return (handle_min_int(nbr, base, base_len));
	if (nbr < 0)
		return (handle_negative(nbr, base));
	if ((size_t)nbr >= base_len)
		count += ft_putnbr_base(nbr / (int)base_len, base);
	c = base[nbr % (int)base_len];
	write(1, &c, 1);
	count += 1;
	return (count);
}
