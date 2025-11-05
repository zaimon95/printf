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
#include <stdio.h>
int	main(void)
{
	int		count_ft;
	int		count_std;

	// Test 1 : base décimale
	printf("=== Test base décimale ===\n");
	count_ft = ft_putnbr_base(42, "0123456789");
	printf(" | (ft_putnbr_base count = %d)\n", count_ft);
	count_std = printf("%d", 42);
	printf(" | (printf count = %d)\n\n", count_std);

	// Test 2 : nombre négatif
	printf("=== Test négatif ===\n");
	count_ft = ft_putnbr_base(-12345, "0123456789");
	printf(" | (ft_putnbr_base count = %d)\n", count_ft);
	count_std = printf("%d", -12345);
	printf(" | (printf count = %d)\n\n", count_std);

	// Test 3 : base binaire
	printf("=== Test base binaire ===\n");
	count_ft = ft_putnbr_base(42, "01");
	printf(" | (ft_putnbr_base count = %d)\n", count_ft);
	printf("\n\n");

	// Test 4 : base hexadécimale
	printf("=== Test base hexadécimale ===\n");
	count_ft = ft_putnbr_base(255, "0123456789abcdef");
	printf(" | (ft_putnbr_base count = %d)\n", count_ft);
	count_std = printf("%x", 255);
	printf(" | (printf count = %d)\n\n", count_std);

	// Test 6 : base invalide
	printf("=== Test base invalide ===\n");
	count_ft = ft_putnbr_base(42, "0"); // base trop courte
	printf(" | (ft_putnbr_base count = %d)\n\n", count_ft);

	return (0);
}
