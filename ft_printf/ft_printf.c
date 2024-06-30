/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtsuchid <gtsuchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:22:43 by gtsuchid          #+#    #+#             */
/*   Updated: 2024/05/19 23:22:46 by gtsuchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	analys(const char **format, va_list *args, unsigned int *len)
{
	if (**format == 'c')
		if (put_c((char)va_arg(*args, int), len) == -1)
			return (-1);
	if (**format == 's')
		if (put_s(va_arg(*args, char *), len) == -1)
			return (-1);
	if (**format == 'p')
		if (put_p(va_arg(*args, void *), len) == -1)
			return (-1);
	if (**format == 'd' || **format == 'i')
		if (put_di(va_arg(*args, int), len) == -1)
			return (-1);
	if (**format == 'u')
		if (put_u(va_arg(*args, unsigned int), len) == -1)
			return (-1);
	if (**format == 'x')
		if (put_x(va_arg(*args, unsigned int), len) == -1)
			return (-1);
	if (**format == 'X')
		if (put_x2(va_arg(*args, unsigned int), len) == -1)
			return (-1);
	if (**format == '%')
		if (put_per(len) == -1)
			return (-1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	len;
	va_list			args;

	len = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (analys(&format, &args, &len) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar_fd_2(*format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	va_end(args);
	return ((int)len);
}

// int	main(void)
// {
// 	int az = 1;
// 	int n = ft_printf("");
//     printf("%d\n", n);
// 	n = printf("");
//     printf("%d\n", n);
// 	int c = ft_printf("%c\n", 'k');
//     printf("%d\n", c);
// 	c = printf("%c\n", 'k');
//     printf("%d\n", c);
// 	char *a = NULL;
// 	int s = ft_printf("%s\n", a);
//     printf("%d\n", s);
// 	s = printf("%s\n", a);
//     printf("%d\n", s);
// 	int p = ft_printf("%p\n", &az);
// 	printf("%d\n", p);
//     p = printf("%p\n", &az);
// 	printf("%d\n", p);
// 	int d = ft_printf("%d\n", 12);
//     printf("%d\n", d);
// 	d = printf("%d\n", 12);
//     printf("%d\n", d);
// 	int u = ft_printf("%u\n", -12);
//     printf("%d\n", u);
// 	u = printf("%u\n", -12);
//     printf("%d\n", u);
// 	int x = ft_printf("%x\n", -12);
//     printf("%d\n", x);
// 	x = printf("%x\n", -12);
//     printf("%d\n", x);
// 	int per = ft_printf("%%\n");
//     printf("%d\n", per);
// 	per = printf("%%\n");
//     printf("%d\n", per);
// }
