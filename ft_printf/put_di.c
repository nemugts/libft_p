/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtsuchid <gtsuchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:23:15 by gtsuchid          #+#    #+#             */
/*   Updated: 2024/05/19 23:24:26 by gtsuchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_di(int c, unsigned int *len)
{
	char	*str;
	int		i;
	int		a;

	a = 0;
	str = ft_itoa((int)c);
	if (str == NULL)
		return (-1);
	i = ft_strlen(str);
	while (a != i)
	{
		if (ft_putchar_fd_2(str[a], 1) == -1)
		{
			free(str);
			return (-1);
		}
		a++;
		(*len)++;
	}
	free(str);
	return (1);
}
