/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:34:40 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/05 08:24:43 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_extractcmd(t_data *data)
{
	char	**cmd;

	cmd = ft_split(data->argv[0], ' ');
	if (!cmd)
		return (perror("malloc"));
	data->argv = data->argv + 1;
	data->cmd = cmd;
}

void	ft_extractpath(t_data *data)
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
			return (perror("malloc"));
		if (access(data->pathcmd, F_OK) == 0)
			return ;
		else
			free(data->pathcmd);
		i++;
	}
	ft_putstr_fd(data->argv[0], 2);
	ft_putendl_fd(": command not found", 2);
	return ;
}

void	ft_child(t_data *data)
{
	if (data->nb_cmd == data->nb_pipe -1)
	{
		dup2(data->input, 0);
		dup2(data->output, 1);
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
	}
	else
	{
		close(data->pipe_fd[0]);
		dup2(data->input, 0);
		dup2(data->pipe_fd[1], 1);
	}
	data->cmd[0] = data->pathcmd;
	if (execve(data->pathcmd, data->cmd, data->env) == -1)
		return (perror("execve"));
}

void	ft_exec(t_data *data)
{
	ft_extractcmd(data);
	ft_extractpath(data);
	if (pipe(data->pipe_fd) == -1)
		return (ft_freedata(data), perror("pipe"), exit(EXIT_FAILURE));
	data->pid = fork();
	if (data->pid == -1)
		return (ft_freedata(data), perror("fork"), exit(EXIT_FAILURE));
	if (data->pid == 0)
		ft_child(data);	
	else
	{
		close(data->pipe_fd[1]);
		close(data->input);
		data->input = dup(data->pipe_fd[0]);
		waitpid(data->pid, NULL, 0);
	}
}

void	ft_pipex(t_data *data)
{
	data->nb_cmd = 0;
	while (data->nb_cmd < data->nb_pipe)
	{
		ft_exec(data);
		data->nb_cmd++;
	}
}
