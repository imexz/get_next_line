/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:54:16 by mstrantz          #+#    #+#             */
/*   Updated: 2023/02/22 12:22:03 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_separate_rest(char ***rest, int i)
{
	char	*ret;
	char	*temp;

	ret = ft_substr(**rest, 0, i + 1);
	temp = ft_strdup((**rest) + i + 1);
	free (**rest);
	**rest = temp;
	if ((*rest)[0] == '\0')
	{
		free (temp);
		**rest = NULL;
	}
	return (ret);
}

static char	*ft_adjust_rest(char *buff, char **rest, ssize_t num)
{
	char	*temp;
	char	*ret;
	int		i;

	if (*rest == NULL)
		*rest = ft_strdup(buff);
	else if (num != 0)
	{
		temp = ft_strdup(*rest);
		free (*rest);
		*rest = ft_strjoin(temp, buff);
		free (temp);
	}
	i = 0;
	while ((*rest)[i] != '\n' && (*rest)[i] != '\0')
		i++;
	if ((*rest)[i] == '\n')
	{
		ret = ft_separate_rest(&rest, i);
		if (ret)
			return (ret);
	}
	return (NULL);
}

static char	*ft_check_nl(char **rest)
{
	int		i;
	char	*ret;
	char	*temp;

	i = 0;
	while ((*rest)[i] != '\n' && (*rest)[i] != '\0')
		i++;
	if ((*rest)[0] == '\0')
	{
		free (*rest);
		*rest = NULL;
	}
	else if ((*rest)[i] == '\n')
	{
		ret = ft_substr(*rest, 0, i + 1);
		temp = ft_strdup((*rest) + i + 1);
		free (*rest);
		*rest = temp;
		return (ret);
	}
	return (NULL);
}

static int	ft_read(int fd, char *buff, char **rest)
{
	int	num;

	if (BUFFER_SIZE < 1)
		return (-1);
	num = read(fd, buff, BUFFER_SIZE);
	if (num == -1)
		return (num);
	(buff)[num] = '\0';
	if ((buff)[0] == '\0' && *rest == NULL)
		num = -1;
	return (num);
}

char	*get_next_line(int fd)
{
	static char		*rest[10240];
	char			buff[BUFFER_SIZE + 1];
	char			*temp;
	ssize_t			num;

	num = 1;
	while (num > 0)
	{
		if (rest[fd])
		{
			temp = ft_check_nl(&rest[fd]);
			if (temp)
				return (temp);
		}
		num = ft_read(fd, buff, &rest[fd]);
		if (num == -1 || fd < 0)
			return (NULL);
		temp = ft_adjust_rest(buff, &rest[fd], num);
		if (temp)
			return (temp);
		if (num == 0 && rest[fd])
			return (ft_eof_rest(&temp, &rest[fd]));
	}
	return (NULL);
}
