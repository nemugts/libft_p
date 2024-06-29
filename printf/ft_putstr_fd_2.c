/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtsuchid <gtsuchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:23:07 by gtsuchid          #+#    #+#             */
/*   Updated: 2024/05/19 23:23:08 by gtsuchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_2(char *s, int fd)
{
	int	len;

	if (s == NULL)
		return (-1);
	len = ft_strlen(s);
	return (write(fd, s, len));
}
