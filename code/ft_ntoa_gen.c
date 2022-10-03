/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:27:38 by aartiges          #+#    #+#             */
/*   Updated: 2021/11/15 18:02:07 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_nb_base(unsigned long nb, unsigned long order_base)
{
	unsigned long	div;
	int				len;

	len = 1;
	div = (unsigned long)(nb / order_base);
	while (div > 0)
	{
		++len;
		div = (unsigned long)(div / order_base);
	}
	return (len);
}

char	*ft_ntoa_gen(unsigned long nb, char *base, int negative)
{
	char			*ret;
	int				order_base;
	int				len;
	unsigned long	div;

	if (!base)
		return (NULL);
	order_base = ft_strlen(base);
	if (order_base < 2)
		return (NULL);
	len = len_nb_base(nb, order_base) + (negative && 1);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	div = (unsigned long)nb;
	ret[len] = '\0';
	while (len > (negative && 1))
	{
		ret[--len] = base[div % order_base];
		div = div / order_base;
	}
	if (negative)
		ret[0] = '-';
	return (ret);
}
