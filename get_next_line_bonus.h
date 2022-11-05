/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:07:02 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/03 20:09:24 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <libc.h>

char	*ft_join(char *s1, const char *s2);
int		ft_search(const char *data);
char	*get_next_line(int fd);
char	*ft_strdup(const char *string);

#endif