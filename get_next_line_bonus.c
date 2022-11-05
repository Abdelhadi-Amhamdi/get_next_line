/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:05:39 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/04 15:42:08 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// #define BUFFER_SIZE 42

char	*free_all(char *data, char *buffer)
{
	free(data);
	free(buffer);
	return (NULL);
}

char	*read_file(int fd, char *data)
{
	char	*buffer;
	int		is_nl;
	int		count;

	is_nl = 0;
	count = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!is_nl && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0 && !data)
			return (free(buffer), NULL);
		else if (count == 0 && data[0] != '\0')
			break ;
		else if (count == -1 && data)
			return (data = free_all(data, buffer));
		buffer[count] = '\0';
		data = ft_join(data, buffer);
		if (ft_search(data) != -1)
			is_nl = 1;
	}
	return (free(buffer), data);
}

char	*get_line_from_data(const char *data)
{
	char	*line;
	int		nl_index;

	nl_index = ft_search(data);
	if (nl_index != -1)
	{
		line = malloc(nl_index + 2 * sizeof(char));
		if (!line)
			return (NULL);
		strlcpy(line, data, nl_index + 2);
	}
	else
		line = ft_strdup(data);
	return (line);
}

char	*update_data(const char *data)
{
	char	*new_data;
	int		nl_index;
	int		size;

	nl_index = ft_search(data);
	if (nl_index != -1)
	{
		size = strlen(data + nl_index + 1);
		new_data = malloc(size + 1 * sizeof(char));
		if (!new_data)
			return (NULL);
		strlcpy(new_data, data + (nl_index + 1), size + 1);
	}
	else
		new_data = NULL;
	free((char *)data);
	return (new_data);
}

char	*get_next_line(int fd)
{
	static char	*data[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data[fd] = read_file(fd, data[fd]);
	if (!data[fd] || !*data[fd])
	{
		if (data[fd])
			free(data[fd]);
		return (NULL);
	}
	line = get_line_from_data(data[fd]);
	data[fd] = update_data(data[fd]);
	return (line);
}

// int main()
// {
//     int fd1 = open("file1.txt" , O_RDONLY);
//     int fd3 =  open("file3.txt" , O_RDONLY);
//     close(fd1);
//     int fd2 = open("file1.txt" , O_RDONLY);
//     printf("|%d|" , fd2);
//     printf("%s" , get_next_line(fd1));
//     printf("%s" , get_next_line(fd2));
//     printf("%s" , get_next_line(fd3));
//     printf("%s" , get_next_line(fd2));
// }