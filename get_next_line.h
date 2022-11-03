/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:58:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/03 10:41:51 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <libc.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t len);
char	*ft_str_join(char *s1, char *s2);
int		ft_str_search(char *data);
char	*ft_strdup(char *string);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *src);

#endif