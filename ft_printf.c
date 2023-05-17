/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:55:00 by davidga2          #+#    #+#             */
/*   Updated: 2023/05/17 21:15:06 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
/*
int	ft_specifier_format()
{

}
*/
int ft_printf(char const *str, ...)
{
	//ssize_t	counter;
	size_t	i;
	va_list arguments;

	if (!str)
		return (0);
	va_start(arguments, str);
	i = 0;
	while (str[i] != '\0')
	{
		//counter++;
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar_fd(va_arg(arguments, int), 1);
			else if (str[i] == 's')
				ft_putstr_fd(va_arg(arguments, char *), 1);
			else if (str[i] == 'p')				
				ft_putnbr_base_or_ptr_fd(va_arg(arguments, size_t), "0123456789abcdef", 1, 1);
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr_fd(va_arg(arguments, int), 1);
			else if (str[i] == 'u')
				ft_putunbr_fd(va_arg(arguments, unsigned int), 1);
			else if (str[i] == 'x')
				ft_putnbr_base_or_ptr_fd(va_arg(arguments, unsigned int), "0123456789abcdef", 0, 1);
			else if (str[i] == 'X')
				ft_putnbr_base_or_ptr_fd(va_arg(arguments, unsigned int), "0123456789ABCDEF", 0, 1);
			else if (str[i] == '%')
				ft_putchar_fd('%', 1);
			i++;
		}
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	return (0);
}

int	main(void)
{
	int				printf_return;
	char			c = '*';
	char			*s = "str";
	char			*p = &c;
	int				d = 0;
	int				i = 42;
	unsigned int	u = -50;
	unsigned int	xX = -42;

	printf("----- printf() -----\n");
	printf_return = printf("%c %s %p %d %i %u %x %X %% \n",
			c, s, p, d, i, u, xX, xX);
	//printf("%i\n", printf_return);
	printf("--- My ft_printf ---\n");
	printf_return = ft_printf("%c %s %p %d %i %u %x %X %% \n",
			c, s, p, d, i, u, xX, xX);
	//printf("%i\n", printf_return);
	//ft_printf("\n--- Value: %u\n\n", xX);
	//ft_printf("--- hexa: %x\n--- HEXA: %X\n", xX, xX);
	
	return (0);
}
