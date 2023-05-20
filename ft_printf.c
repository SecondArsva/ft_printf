/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:55:00 by davidga2          #+#    #+#             */
/*   Updated: 2023/05/20 14:56:08 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format_type(const char *str, va_list args, int *ctr, size_t i)
{
	if (str[i] == 'c')
		ft_putchar_count(va_arg(args, int), ctr);
	else if (str[i] == 's')
		ft_putstr_count(va_arg(args, char *), ctr);
	else if (str[i] == 'p')
		ft_putnbr_base(va_arg(args, size_t), "0123456789abcdef", 1, ctr);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr_count(va_arg(args, int), ctr);
	else if (str[i] == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 0, ctr);
	else if (str[i] == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", 0, ctr);
	else if (str[i] == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", 0, ctr);
	else if (str[i] == '%')
		ft_putchar_count('%', ctr);
}

static void	ft_spec_format(const char *str, va_list args, int *ctr, size_t i)
{
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			ft_format_type(str, args, ctr, i);
			i++;
		}
		else
			ft_putchar_count(str[i++], ctr);
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	arguments;
	int		counter;
	size_t	i;

	if (!str)
		return (0);
	va_start(arguments, str);
	counter = 0;
	i = 0;
	ft_spec_format(str, arguments, &counter, i);
	va_end(arguments);
	return (counter);
}
/*
int	main(void)
{
	int				printf_return;
	int				ft_printf_return;
	char			c = '*';
	char			*s = "str";
	char			*p = &c;
	int				d = 0;
	int				i = 42;
	unsigned int	u = -50;
	unsigned int	xX = -42;

	ft_printf("%c\n", '0');
	
	// Contempla este caso: ft_printf("%"); alepinto.
	
	printf("----- printf() -----\n");
	printf_return = printf("%c %s %p %d %i %u %x %X %% \n",
			c, s, p, d, i, u, xX, xX);
	printf("\n");
	//printf("%i\n", printf_return);
	printf("--- My ft_printf ---\n");
	ft_printf_return = ft_printf("%c %s %p %d %i %u %x %X %% \n",
			c, s, p, d, i, u, xX, xX);
	//printf("%i\n", printf_return);
	//ft_printf("\n--- Value: %u\n\n", xX);
	//ft_printf("--- hexa: %x\n--- HEXA: %X\n", xX, xX);
	printf("\nprintf() return: %i\n", printf_return);	
	ft_printf("\nft_printf return: %i\n", ft_printf_return);

	printf("\n%i | %i\n", printf_return, ft_printf_return);
	return (0);
}*/
