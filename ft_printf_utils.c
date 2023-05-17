/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:08:28 by davidga2          #+#    #+#             */
/*   Updated: 2023/05/17 20:28:00 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
	return (c);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0 && n != -2147483648)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 0)
	{
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
		else if (n <= 9)
			ft_putchar_fd(n + '0', fd);
	}
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

// bool int is_ptr = 1/0;
void	ft_putnbr_base_or_ptr_fd(size_t n, char *base_str, int is_ptr, int fd)
{
	size_t	base;
	int		remainder;
	char	debug_char;
	char	debug_slot;

	if (is_ptr == 1)
		ft_putstr_fd("0x", 1);
	base = ft_strlen(base_str);
	remainder = n % base;
	if (n >= base)
	{
		ft_putnbr_base_or_ptr_fd(n / base, base_str, 0, fd);
		debug_char = ft_putchar_fd(base_str[remainder], fd);
	}
	else
		debug_char = ft_putchar_fd(base_str[remainder], fd);
	debug_slot = base_str[remainder];
}
