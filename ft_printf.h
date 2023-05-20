/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:17:53 by davidga2          #+#    #+#             */
/*   Updated: 2023/05/20 14:56:10 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);

size_t	ft_strlen(const char *str);
void	ft_putchar_count(char c, int *ctr);
void	ft_putstr_count(char *s, int *ctr);
void	ft_putnbr_count(int n, int *ctr);
void	ft_putunbr(size_t n, int *ctr);
void	ft_putnbr_base(size_t n, char *base_str, int is_ptr, int *ctr);

#endif
