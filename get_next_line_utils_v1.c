/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:13:27 by mstrantz          #+#    #+#             */
/*   Updated: 2021/07/16 18:41:05 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	substr = (char *) malloc(len + 1);
	if (substr == NULL || s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr[0] = 0;
		return (substr);
	}
	i = 0;
	while (i < len && s[start])
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*s1_cpy;

	len = ft_strlen(s1) + 1;
	s1_cpy = (char *) malloc(len * sizeof(char));
	if (s1_cpy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s1_cpy[i] = s1[i];
		i++;
	}
	return (s1_cpy);
}

char	*ft_eof_rest(char **temp, char **rest)
{
	*temp = *rest;
	*rest = NULL;
	return (*temp);
}
