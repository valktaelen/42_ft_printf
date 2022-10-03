/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:02:23 by aartiges          #+#    #+#             */
/*   Updated: 2021/11/15 18:30:25 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	str_len(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

static void	free_multiple(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}

char	*join_free(char *s1, char *s2)
{
	char	*ret;
	int		len_s1;
	int		len_s2;
	int		i;

	len_s1 = str_len(s1);
	len_s2 = str_len(s2);
	ret = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		ret[i] = s1[i];
		++i;
	}
	while (i < len_s1 + len_s2)
	{
		ret[i] = s2[i - len_s1];
		++i;
	}
	ret[i] = '\0';
	free_multiple(s1, s2);
	return (ret);
}

int	in_array(char target, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (target == set[i])
			return (i);
		++i;
	}
	return (-1);
}

char	*unique_str(char c)
{
	char	*arg;

	arg = malloc(2 * sizeof(char));
	if (!arg)
		return (NULL);
	arg[0] = c;
	arg[1] = '\0';
	return (arg);
}
