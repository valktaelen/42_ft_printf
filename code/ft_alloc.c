/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:32:09 by aartiges          #+#    #+#             */
/*   Updated: 2021/11/15 21:13:50 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_dup(char *s1)
{
	size_t	len;
	char	*ret;

	len = str_len(s1);
	if (!s1)
		return (NULL);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	return (ft_memmove(ret, s1, len + 1));
}

char	*str_null(void)
{
	char	*ret;

	ret = malloc(7 * sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '(';
	ret[1] = 'n';
	ret[2] = 'u';
	ret[3] = 'l';
	ret[4] = 'l';
	ret[5] = ')';
	ret[6] = '\0';
	return (ret);
}

char	*str_convert(va_list param)
{
	char	*arg;

	arg = va_arg(param, char *);
	if (!arg)
		return (str_null());
	return (str_dup(arg));
}
