/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:07:02 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/03 12:53:04 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <libc.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t len);
char	*ft_str_join(char *s1, char *s2);
int		ft_str_search(char *data);
char	*ft_strdup(char *string);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *src);

#endif