/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:36:56 by sla-gran          #+#    #+#             */
/*   Updated: 2025/10/31 10:36:56 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_putnbr_base(int nbr, char *base);
int	ft_putvoid(void const *p);

#endif
