/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtsuchid <gtsuchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:08:34 by gtsuchid          #+#    #+#             */
/*   Updated: 2024/05/02 00:51:29 by gtsuchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cpy(char const *s1, char const *s2, char *result)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result = cpy(s1, s2, result);
	return (result);
}
// #include<stdio.h>
// int main()
// {
//     char const *s1 = "Hello";
//     char const *s2 = " World";
//     char *result;
//     // ケース1: 通常の結合
//     result = ft_strjoin(s1, s2);
//     if (result != NULL) {
//         printf("Joined string: '%s'\n", result);
//         free(result);
//     } else {
//         printf("Memory allocation failed.\n");
//     }
//     // ケース2: s1 が空の文字列
//     result = ft_strjoin("", s2);
//     if (result != NULL) {
//         printf("Joined string (empty s1): '%s'\n", result);
//         free(result);
//     } else {
//         printf("Memory allocation failed.\n");
//     }
//     // ケース3: s2 が空の文字列
//     result = ft_strjoin(s1, "");
//     if (result != NULL) {
//         printf("Joined string (empty s2): '%s'\n", result);
//         free(result);
//     } else {
//         printf("Memory allocation failed.\n");
//     }
//     // ケース4: 両方の文字列が空
//     result = ft_strjoin("", "");
//     if (result != NULL) {
//         printf("Joined string (both empty): '%s'\n", result);
//         free(result);
//     } else {
//         printf("Memory allocation failed.\n");
//     }
//     result = ft_strjoin(NULL, s2);
//     return 0;
// }
