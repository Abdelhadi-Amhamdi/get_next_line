
#include "get_next_line.h"

int ft_str_search(char *data)
{
    int index;

    index = 0;
    while(data && data[index])
    {
        if(data[index] == '\n')
            return index;
        index++;
    }
    return -1;
}

char *ft_strdup(char *string)
{
    char *p;
    int index;

    index  = 0;
    p = malloc((strlen(string) + 1) * sizeof(char));
    if(!p)
        return 0;
    while(string[index])
    {
        p[index] = string[index];
        index++;
    }
    p[index] = '\0';
    return p;
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