/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:34:40 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/10 08:39:45 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_extractcmd(t_data *data)
{
	data->cmd = ft_split(data->argv[0], ' ');
	if (!data->cmd)
		return (perror("malloc"));
	data->argv = data->argv + 1;
}

int	ft_extractpath(t_data *data)
{
	int			i;
	char		*stock;

	i = 1;
	while (data->path[i])
	{
		data->pathcmd = ft_strjoin(data->path[i], "/");
		stock = data->pathcmd;
		data->pathcmd = ft_strjoin(data->pathcmd, data->cmd[0]);
		free(stock);
		if (data->pathcmd == NULL)
			return (perror("malloc"), -1);
		if (access(data->pathcmd, F_OK) == 0)
			return (0);
		else
			free(data->pathcmd);
		i++;
	}
	data->pathcmd = NULL;
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(data->cmd[0], 2);
	return (127);
}

int	ft_child(t_data *data)
{
	if (data->nb_cmd == data->nb_pipe -1)
	{
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		if (dup2(data->input, 0) == -1)
			return (perror("dup2"), -1);
		if (dup2(data->output, 1) == -1)
			return (perror("dup2"), -1);
	}
	else
	{
		close(data->pipe_fd[0]);
		if (dup2(data->input, 0) == -1)
			return (perror("dup2"), -1);
		if (dup2(data->pipe_fd[1], 1) == -1)
			return (perror("dup2"), -1);
	}
	if (data->pathcmd != NULL)
	{
		data->cmd[0] = data->pathcmd;
		execve(data->pathcmd, data->cmd, data->env);
		return (perror("execve"), 126);
	}
	exit(EXIT_FAILURE);
	return (0);
}

int	ft_exec(t_data *data)
{
	if (pipe(data->pipe_fd) == -1)
		return (ft_freedata(data), perror("pipe"), 1);
	data->pid[data->nb_cmd] = fork();
	if (data->pid[data->nb_cmd] == -1)
		return (ft_freedata(data), perror("fork"), 1);
	if (data->pid[data->nb_cmd] == 0)
		ft_child(data);
	else
	{
		close(data->pipe_fd[1]);
		close(data->input);
		data->input = dup(data->pipe_fd[0]);
		close(data->pipe_fd[0]);
		if (data->input == -1)
			return (perror("dup"), 1);
	}
	return (0);
}

int	ft_pipex(t_data *data)
{
	int	ret;

	ret = 0;
	data->nb_cmd = 0;
	data->pid = malloc(sizeof(int) * data->nb_pipe);
	if (!data->pid)
		return (perror("malloc"), 1);
	while (data->nb_cmd < data->nb_pipe)
	{
		ft_extractcmd(data);
		ret = ft_extractpath(data);
		ret = ft_exec(data);
		if (ret != 0)
			return (free(data->pathcmd), ft_freesplit(data->cmd), ret);
		if (data->pathcmd != NULL)
			free(data->pathcmd);
		data->nb_cmd++;
		ft_freesplit(data->cmd);
	}
	close(data->output);
	return (ret);
}
