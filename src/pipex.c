/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:34:40 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/02 15:23:46 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exectwo(int *fd, char **cmd1, char **cmd2, char **path, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		wait_status;
	int		p_fd[2];

	pipe(p_fd);
	if (p_fd == -1)
		return (perror("pipe"));
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork"));
	if (pid1 == 0)
	{
		close(p_fd(1));
		dup2(p_fd[0], fd[0]);
		close(p_fd[0]);
		execve(path, cmd1, env);
		perror("execve");
		return;
	}
	else
	{
		close(p_fd(0));
		dup2(p_fd[1], fd)
	}
}

void	ft_twocmd(int *fd, char **argv, char **path, char **env)
{
	char	**cmd1;
	char	**cmd2;

	cmd1 = ft_split(argv[0], 32);
	if (!cmd1)
	{
		ft_putendl_fd("ERROR: Split fail", 2);
		return (close(fd[0]), close(fd[1]));
	}
	cmd2 = ft_split(argv[1], 32);
	if (!cmd2)
	{
		ft_putendl_fd("ERROR: Split fail", 2);
		return (ft_freesplit(cmd1), close(fd[0]), close(fd[1]));
	}
	ft_exectwo(fd, cmd1, cmd2, path, env);
	return (ft_freesplit(cmd1), ft_freesplit(cmd2));
}

void	ft_pipex(int *fd, char** argv, char **path, char **env)
{
	int		size;
	int		i;
	int		out;

	i = 0;
	size = 0;
	while (argv[size] != NULL)
		size++;
	size -= 1;
	if (size == 2)
		ft_twocmd(fd, argv, path);
	else
	{
		out = fd[1];
		while (i < size - 2)
		{
			/*ft_execmd(fd, argv + i, path);*/
			i++;
		}
		fd[1] = out;
		ft_twocmd(fd, argv, path);
	}
}
