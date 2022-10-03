/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:48:31 by aartiges          #+#    #+#             */
/*   Updated: 2022/10/03 22:19:22 by aartiges         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "libft/code/libft.h"

# define DECIMAL "0123456789"
# define HEX_MIN "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
char	*ft_ntoa_gen(unsigned long nb, char *base, int negative);

// utils

char	*unique_str(char c);
int		in_array(char target, char *set);
char	*join_free(char *s1, char *s2);
size_t	str_len(char *str);

// alloc

char	*str_dup(char *s1);
char	*str_convert(va_list param);

// convert

char	*integer_str(va_list param);
char	*u_l_str(va_list param, char *base);
char	*u_i_str(va_list param, char *base);

#endif
