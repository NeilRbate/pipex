/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:59:42 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/10 09:07:56 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_openread(char *file)
{
	int	fd;
	int	empty_fd[2];

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_putendl_fd("ERROR: Try to open a directory", 2);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(file);
		pipe(empty_fd);
		close(empty_fd[1]);
		return (empty_fd[0]);
	}
	return (fd);
}

int	ft_openwrite(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_putendl_fd("ERROR: Try to open a directory", 2);
		return (-1);
	}
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(file);
		return (-1);
	}
	return (fd);
}

void	ft_freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_freedata(t_data *data)
{
	if (data->path != NULL)
		ft_freesplit(data->path);
	if (data->pathcmd != NULL)
		free(data->pathcmd);
	if (data->cmd != NULL)
		ft_freesplit(data->cmd);
	if (data->pid != NULL)
		free(data->pid);
}

char	**ft_splitpath(char **env)
{
	char	**ret;
	int		i;

	i = 0;
	while ((env[i][0] != 'P' || env[i][1] != 'A' || env[i][2] != 'T' ||
			env[i][3] != 'H' || env[i][4] != '=') && env[i])
		i++;
	ret = ft_split(env[i] + 5, ':');
	if (!ret)
		return (NULL);
	return (ret);
}
