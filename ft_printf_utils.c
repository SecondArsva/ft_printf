/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:08:28 by davidga2          #+#    #+#             */
/*   Updated: 2023/05/20 14:56:12 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(char c, int *ctr)
{
	int	write_return;

	write_return = write (1, &c, 1);
	(*ctr)++;
}

void	ft_putstr_count(char *s, int *ctr)
{
	size_t	i;

	if (!s)
	{
		*ctr += write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_count(s[i], ctr);
		i++;
	}
}

void	ft_putnbr_count(int n, int *ctr)
{
	if (n == -2147483648)
		ft_putstr_count("-2147483648", ctr);
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_count('-', ctr);
		n = n * -1;
	}
	if (n >= 0)
	{
		if (n >= 10)
		{
			ft_putnbr_count(n / 10, ctr);
			ft_putchar_count(n % 10 + '0', ctr);
		}
		else if (n <= 9)
			ft_putchar_count(n + '0', ctr);
	}
}

void	ft_putnbr_base(size_t n, char *base_str, int is_ptr, int *ctr)
{
	size_t	base;
	int		remainder;

	base = 0;
	while (base_str[base] != '\0')
		base++;
	remainder = n % base;
	if (is_ptr == 1)
		ft_putstr_count("0x", ctr);
	if (n >= base)
	{
		ft_putnbr_base(n / base, base_str, 0, ctr);
		ft_putchar_count(base_str[remainder], ctr);
	}
	else
		ft_putchar_count(base_str[remainder], ctr);
}
