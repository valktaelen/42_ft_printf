/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:15:10 by aartiges          #+#    #+#             */
/*   Updated: 2021/11/15 21:16:41 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*integer_str(va_list param)
{
	char	*arg;
	int		tmp;

	tmp = va_arg(param, int);
	if (tmp < 0)
		arg = ft_ntoa_gen((unsigned long)tmp * -1, DECIMAL, 1);
	else
		arg = ft_ntoa_gen((unsigned long)tmp, DECIMAL, 0);
	return (arg);
}

char	*u_l_str(va_list param, char *base)
{
	unsigned long	tmp;

	tmp = va_arg(param, unsigned long);
	return (ft_ntoa_gen(tmp, base, 0));
}

char	*u_i_str(va_list param, char *base)
{
	unsigned long	tmp;

	tmp = va_arg(param, unsigned int);
	return (ft_ntoa_gen(tmp, base, 0));
}
