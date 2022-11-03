/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:48:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/03 10:40:42 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_str_search(char *data)
{
	int	index;

	index = 0;
	while (data && data[index])
	{
		if (data[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

size_t	ft_strlen(const char *src)
{
	size_t	index;

	index = 0;
	while (src[index])
		index++;
	return (index);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(src);
	if (len == 0)
		return (size);
	while (src[i] && i < len - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}

char	*ft_strdup(char *string)
{
	size_t	size;
	char	*p;

	if (!string)
		return (NULL);
	size = ft_strlen(string);
	p = malloc(size + 1 * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, string, size + 1);
	return (p);
}

char	*ft_str_join(char *s1, char *s2)
{
	char	*p;
	int		index0;
	int		index1;

	index0 = 0;
	index1 = 0;
	if (!s1)
		s1 = ft_strdup("");
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s1[index0])
	{
		p[index0] = s1[index0];
		index0++;
	}
	while (s2[index1])
	{
		p[index0] = s2[index1];
		index0++;
		index1++;
	}
	p[index0] = '\0';
	free(s1);
	return (p);
}
