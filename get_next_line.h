/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:13:33 by mstrantz          #+#    #+#             */
/*   Updated: 2023/02/22 12:00:43 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

# ifdef GNL_V1

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_eof_rest(char **temp, char **rest);

# else

typedef struct s_buffer
{
	char	chars[BUFFER_SIZE];
	ssize_t	w_head;
	ssize_t	r_head;

} t_buffer;

typedef struct s_line
{
	char			*chars;
	unsigned long	w_head;
	size_t			allocated;

} t_line;
# endif
#endif
