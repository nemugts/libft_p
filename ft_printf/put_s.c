/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtsuchid <gtsuchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:23:26 by gtsuchid          #+#    #+#             */
/*   Updated: 2024/05/19 23:23:26 by gtsuchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_s(char *c, unsigned int *len)
{
	char	*null_str;

	if (c == NULL)
	{
		null_str = "(null)";
		while (*null_str)
		{
			if (ft_putchar_fd_2(*null_str, 1) == -1)
				return (-1);
			(*len)++;
			null_str++;
		}
	}
	else
	{
		while (*c)
		{
			if (ft_putchar_fd_2(*c, 1) == -1)
				return (-1);
		(*len)++;
		c++;
		}
	}
	return (1);
}
