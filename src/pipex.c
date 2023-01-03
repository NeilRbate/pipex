/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:34:40 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/03 12:54:48 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_extractcmd(t_data *data)
{
	char	**cmd;

	cmd = ft_split(data->argv[0], 32);
	if (!cmd)
		return (perror("malloc"));
	data->argv = data->argv + 1;
	data->cmd1 = cmd;
	cmd = ft_split(data->argv[0], 32);
	if (!cmd)
		return (perror("malloc"));
	data->argv = data->argv + 1;
	data->cmd2 = cmd;
}

char	**ft_extractpath(t_data *data, char *cmd)
{
	int		i;
	char	*pathcmd;

	i = 1;
	while (data->path[i])
	{
		pathcmd = ft_strjoin(data->path[i], cmd);
		if (pathcmd == NULL)
			return (perror("malloc"));
		if (acces(pathcmd, F_OK) == 0)
			return (pathcmd);
		else
			free(data->pathcmd1)
		i++;
	}
	return (NULL);
}

void	ft_child(t_data *data)
{
	
}

void	ft_twocmd(t_data *data)
{
	pipe(data->pipe_fd);
	if (data->pipe_fd == -1)
		return;
	ft_extractcmd(data);
	data->pid = fork();
	if (data->pid == -1)
		return (ft_freedata(data), perror("fork"), exit(EXIT_FAILURE));
	if (pid == 0)
	{
		//child

	}
	else
	{
		//parent
	}



}

void	ft_pipex(t_data *data)
{
	int	out;

	out = data->output;
	if (data->nb_cmd == 2)
		ft_twocmd(data);
	else
	{
		while (data->nb_cmd > 2)
		{
			ft_twocmd(data);
			data->nb_cmd--;
		}
		data->output = out;
	}
}
