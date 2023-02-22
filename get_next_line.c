/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:56:02 by mstrantz          #+#    #+#             */
/*   Updated: 2023/02/22 12:22:22 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	t_line_init(t_line *line)
{
	int	ret;

	ret = 0;
	line->allocated = BUFFER_SIZE;
	line->w_head = 0;
	line->chars = (char *) calloc(line->allocated, sizeof(char));
	if (line->chars == NULL)
		ret = -1;
	return (ret);
}

static char	t_buffer_get_next_char(t_buffer *buffer, int fd)
{
	char	c;

	if (buffer->r_head >= buffer->w_head)
	{
		buffer->w_head = read(fd, buffer->chars, BUFFER_SIZE);
		buffer->r_head = 0;
	}
	if (buffer->w_head == 0)
		return (0);
	else if (buffer->w_head == -1)
		return (-1);
	c = buffer->chars[buffer->r_head];
	buffer->r_head++;
	return (c);
}

static void	gnl_memcpy(char *dst, const char *src, size_t n)
{
	while (n > 0)
	{
		dst[n - 1] = src[n - 1];
		n--;
	}
}

static int	t_line_append_char(t_line *line, char c)
{
	char	*new_chars;
	size_t	new_allocated;

	if (line->w_head >= line->allocated)
	{
		new_allocated = line->w_head + line->allocated;
		new_chars = (char *) calloc(new_allocated, sizeof(char));
		if (new_chars == NULL)
			return (-1);
		gnl_memcpy(new_chars, line->chars, line->w_head);
		free(line->chars);
		line->chars = new_chars;
		line->allocated = new_allocated;
	}
	line->chars[line->w_head] = c;
	line->w_head++;
	return (0);
}

static char	*handle_error(char *chars)
{
	free(chars);
	return (NULL);
}

static char	*t_line_get_string(t_line *line)
{
	char	*string;

	if (line->w_head <= 0)
		return (handle_error(line->chars));
	string = calloc(line->w_head + 1, sizeof(char));
	if (string == NULL)
		return (handle_error(line->chars));
	gnl_memcpy(string, line->chars, line->w_head);
	free(line->chars);
	return (string);
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	t_line			line;
	char			c;

	if (fd < 0 || t_line_init(&line) < 0)
		return NULL;
	while (1)
	{
		c = t_buffer_get_next_char(&buffer, fd);
		if (c < 0)
			return (handle_error(line.chars));
		if (c == 0)
			break;
		if (t_line_append_char(&line, c) < 0)
			return (handle_error(line.chars));
		if (c == '\n')
			break;
	}
	return (t_line_get_string(&line));
}
