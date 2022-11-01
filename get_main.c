#define BUFFER_SIZE 1
#include "libc.h"

int ft_str_search(char *data)
{
	int index;

	index = 0;
	while (data && data[index])
	{
		if (data[index] == '\n')
			return index;
		index++;
	}
	return -1;
}

char *ft_str_join(char *s1, char *s2)
{
	char *p;
	int index0;
	int index1;

	index0 = 0;
	index1 = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	p = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	if (!p)
		return NULL;

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
	return p;
}

char *read_file(char *data, int fd)
{
	char *buffer;
	int length;
	int is_new_line;

	length = 1;
	is_new_line = 0;
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return 0;
	while (!is_new_line && length > 0)
	{
		length = read(fd, buffer, BUFFER_SIZE);
		if ((length <= 0 && !data) || (length <= 0 && !*data))
		{
			free(buffer);
			return 0;
		}
		data = ft_str_join(data, buffer);
		if (ft_str_search(data) != -1)
			is_new_line = 1;
	}
	free(buffer);
	return (data);
}

char *get_Line__update_Data(char *data)
{
	int index;
	int n_index;
	char *line;

	n_index = ft_str_search(data);
	index = 0;
	if (n_index == -1)
	{
		line = malloc((strlen(data) + 1) * sizeof(char));
		while (data[index])
		{
			line[index] = data[index];
			index++;
		}
		line[index] = '\0';
		free(data);
		data = 0;
	}
	else
	{
		line = malloc((n_index + 2) * sizeof(char));
		while (data[index] && index <= n_index)
		{
			line[index] = data[index];
			index++;
		}
		line[index] = '\0';
	}
	return line;
}

char *update_stock(char *data, int i)
{
	char *p;
	int j = 0;
	int size;

	size = (strlen(data + i) + 1);
	p = malloc(size * sizeof(char));
	if(!p)
		return 0;
	
	while(data[i])
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
	int n_index;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return 0;

	data = read_file(data, fd);
	if (!data || !*data)
		return 0;
	line = get_Line__update_Data(data);

	if (line)
	{
		n_index = ft_str_search(line);
		if (n_index == -1)
		{
			data = NULL;
		}
		else
			data = update_stock(data , n_index + 1);
	}
	return line;
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// printf("%s" , get_next_line(fd));
	// printf("%s" , get_next_line(fd));
	system("leaks  a.out");
}
