/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:48:51 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/03 10:32:59 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #define BUFFER_SIZE 42

char	*read_file(char *data, int fd)
{
	char	*buffer;
	int		count;
	int		is_new_line;

	count = 1;
	is_new_line = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!is_new_line && count)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 1 && !data)
			return (free(buffer), NULL);
		else if (!count && data)
			break ;
		buffer[count] = '\0';
		data = ft_str_join(data, buffer);
		if (ft_str_search(data) != -1)
			is_new_line = 1;
	}
	free(buffer);
	return (data);
}

char	*get_line_from_data(char *data)
{
	int		line_index;
	char	*line;
	size_t	size;

	line_index = ft_str_search(data);
	if (line_index == -1)
	{
		size = ft_strlen(data);
		line = malloc((size + 1) * sizeof(char));
		strlcpy(line, data, size + 1);
	}
	else
	{
		line_index += 2;
		line = malloc((line_index) * sizeof(char));
		ft_strlcpy(line, data, line_index);
	}
	return (line);
}

char	*update_stock(char *data)
{
	int		i;
	char	*p;
	int		j;
	int		size;

	i = ft_str_search(data);
	j = 0;
	if (i == -1)
		return (free(data), NULL);
	size = (ft_strlen(data + (i + 1)));
	p = malloc((size + 1) * sizeof(char));
	if (!p)
		return (0);
	i++;
	while (data[i])
	{
		p[j] = data[i];
		j++;
		i++;
	}
	p[j] = '\0';
	free(data);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = read_file(data, fd);
	if (!data || !*data)
	{
		if (data)
			free(data);
		return (NULL);
	}
	line = get_line_from_data(data);
	data = update_stock(data);
	return (line);
}

// int main()
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *line;
// 	line = get_next_line(fd);

// 	while(line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// }