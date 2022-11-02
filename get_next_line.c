/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:48:51 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/02 13:48:05 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #define BUFFER_SIZE 42

char *read_file(char *data, int fd)
{
	char *buffer;
	int count;
	int is_new_line = 0;

	count = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return NULL;
	while (!is_new_line && count)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 1 && !data)
		{
			free(buffer);
			return 0;
		}
		else if (!count && data)
			break;
		buffer[count] = '\0';
		data = ft_str_join(data, buffer);
		if (ft_str_search(data) != -1)
			is_new_line = 1;
	}
	free(buffer);
	buffer = NULL;
	return data;
}

char *get_line_from_data(char *data)
{
	int line_index;
	char *line;
	size_t size;

	line_index = ft_str_search(data);
	if (line_index == -1)
	{
		size = strlen(data);
		line = malloc((size + 1) * sizeof(char));
		strlcpy(line, data, size + 1);
	}
	else
	{
		line_index += 2;
		line = malloc((line_index) * sizeof(char));
		strlcpy(line, data, line_index);
	}
	return line;
}

char *update_stock(char *data)
{
	int i;
	char *p;
	int j = 0;
	int size;

	i = ft_str_search(data);

	if (i == -1)
	{
		free(data);
		return NULL;
	}
	size = (strlen(data + (i + 1)));
	p = malloc((size + 1) * sizeof(char));
	if (!p)
		return 0;
	i++;
	while (data[i])
	{
		p[j] = data[i];
		j++;
		i++;
	}
	p[j] = '\0';
	free(data);
	return p;
}

char *get_next_line(int fd)
{
	static char *data;
	char *line;

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
// 	int fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }