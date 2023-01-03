/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:34:40 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/03 15:18:22 by jbarbate         ###   ########.fr       */
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
	data->cmd = cmd;
}

char	**ft_extractpath(t_data *data)
{
	int		i;
	char		*pathcmd;

	i = 1;
	while (data->path[i])
	{
		pathcmd = ft_strjoin(data->path[i], cmd);
		if (pathcmd == NULL)
			return (perror("malloc"));
		if (acces(pathcmd, F_OK) == 0)
			return (pathcmd);
		else
			free(data->pathcmd)
		i++;
	}
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": command not found");
	return (NULL);
}

void	ft_child(t_data *data)
{
	if (data->nb_cmd == 0)
		dup2(data->input, 0);
	else
		dup2(data->pipe_fd[])
	close (data->pipe_fd[1]);
	dup2(data->pipe_fd[0], 1);
	if (execve(data->pathcmd, data->cmd[1], data->env) == -1)
		return (perror("execve"));
}

void	ft_exec(t_data *data)
{
	pipe(data->pipe_fd);
	if (data->pipe_fd == -1)
		return;
	ft_extractcmd(data);
	data->pid = fork();
	if (data->pid == -1)
		return (ft_freedata(data), perror("fork"), exit(EXIT_FAILURE));
	if (pid == 0)
		ft_child(data);	
	else
		waitpid(data->pid, NULL, 0);
}

void	ft_pipex(t_data *data)
{
	data->nb_cmd = 0;
	while (data->nb_cmd < data->nb_pipe)
	{
		ft_exec(data);
		data->nb_cmd++;
	}
	data->output = out;
}
