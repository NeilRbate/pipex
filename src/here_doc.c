/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:17:55 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/09 13:42:04 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_openwritehd(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_putendl_fd("ERROR: Try to open a directory", 2);
		return (-1);
	}
	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
	{
		perror(file);
		return (-1);
	}
	return (fd);
}

void	ft_init(t_data *data)
{
	data->nb_pipe -= 1;
	data->argv = data->argv + 1;
}

int	ft_writepipe(t_data *data, char	*str)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (free(str), 1);
	write(fd[1], str, ft_strlen(str) + 1);
	close(fd[1]);
	data->input = fd[0];
	free(str);
	return (0);
}

int	ft_heredoc(t_data *data, char *limiter)
{
	char	*str;
	char	*line;
	size_t	size;

	ft_init(data);
	str = malloc(1);
	size = ft_strlen(limiter);
	if (!str)
		return (1);
	str[0] = '\0';
	while (1)
	{
		line = get_next_line(0);
		if (ft_strnstr(line, limiter, ft_strlen(limiter))
			&& size == ft_strlen(line) - 1)
		{
			free(line);
			break ;
		}
		str = ft_gstrjoin(str, line);
		free(line);
	}
	close(0);
	ft_writepipe(data, str);
	return (0);
}
