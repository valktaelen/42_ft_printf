/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:48:12 by aartiges          #+#    #+#             */
/*   Updated: 2021/11/15 21:15:37 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_part(char *s, char c)
{
	size_t	len;

	len = -1;
	if (c == 'c' && s)
	{
		len = 1;
		write(1, s, 1);
	}
	else if (s)
	{
		len = str_len(s);
		write(1, s, len);
	}
	if (s)
		free(s);
	return (len);
}

static int	ft_arg(va_list param, char *origin)
{
	char	*arg;
	size_t	i;

	i = 0;
	if (origin[i] == '%')
		arg = unique_str('%');
	else if (origin[i] == 'd' || origin[i] == 'i')
		arg = integer_str(param);
	else if (origin[i] == 'p')
		arg = u_l_str(param, HEX_MIN);
	else if (origin[i] == 'x')
		arg = u_i_str(param, HEX_MIN);
	else if (origin[i] == 'X')
		arg = u_i_str(param, HEX_MAJ);
	else if (origin[i] == 'c')
		arg = unique_str((char)va_arg(param, int));
	else if (origin[i] == 's')
		arg = str_convert(param);
	else if (origin[i] == 'u')
		arg = u_i_str(param, DECIMAL);
	else
		arg = join_free(unique_str('%'), unique_str(origin[i]));
	if (origin[i] == 'p')
		arg = join_free(join_free(unique_str('0'), unique_str('x')), arg);
	return (write_part(arg, origin[i]));
}

static int	ft_result(va_list param, char *origin)
{
	int		tmp;
	int		start;
	int		i;
	int		tmp2;

	i = 0;
	start = 0;
	tmp = 0;
	while (origin[i])
	{
		if (origin[i] == '%')
		{
			tmp += write_part(ft_substr(origin, start, i - start), 'x');
			tmp2 = ft_arg(param, origin + i + 1);
			if (tmp2 == -1)
				return (-1);
			tmp += tmp2;
			++i;
			start = i + 1;
		}
		++i;
	}
	tmp += write_part(ft_strdup(origin + start), 'x');
	return (tmp);
}

int	ft_printf(const char *format, ...)
{
	va_list	param;
	int		result;

	if (!format)
		return (-1);
	va_start(param, format);
	result = ft_result(param, (char *)format);
	va_end(param);
	return (result);
}
