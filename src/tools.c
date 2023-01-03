/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:59:42 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/03 10:11:55 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_openread(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_putendl_fd("ERROR: Try to open a directory", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
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
		return(ft_putendl_fd("ERROR: Try to open a directory", 2), -1);
	}
	fd = open(file, O_WRONLY);
	if (fd == -1)
		return (perror("open"), -1);
	return (fd);
}

void	ft_freesplit(char **split)
{
	int	i;

	i = 0;
	while(split[i])
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
	close(data->input);
	close(data->output);
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
