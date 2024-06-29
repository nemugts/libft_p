/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtsuchid <gtsuchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:50:30 by gtsuchid          #+#    #+#             */
/*   Updated: 2024/05/02 04:23:04 by gtsuchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_wordcount(const char *s, char c)
{
	int	count;

	count = 0;
	if (s[ft_strlen(s) - 1] != c || s[0] == '\0')
		count++;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		if (*s)
			count++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static int	assign_words(char const *s, char c, char **array, int i)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	array[i] = (char *)malloc(sizeof(char) * (len + 1));
	if (!array[i])
	{
		while (i > -1)
			free (array[i--]);
		free (array);
		return (0);
	}
	ft_strncpy(array[i], s, len);
	return (1);
}

char	**ft_split(const char *s, char c)
{
	int		wordcount;
	char	**array;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	wordcount = ft_wordcount(s, c);
	array = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!array)
		return (NULL);
	if (s[0] == '\0')
		array[0] = NULL;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && assign_words(s, c, array, i++) == 0)
			return (NULL);
		while (*s && *s != c)
			s++;
	}
	array[i] = NULL;
	return (array);
}
// int main()
// {
//     ft_split("", ',');
// }
