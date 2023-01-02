/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:34:40 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/02 14:11:12 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exectwo(int *fd, char **cmd1, char **cmd2, char **path, char **env)
{
	int		pipe_fd[2];
	int		wait_status;
	pid_t	pid;
	
	if (pipe(pipe_fd) == -1)
		return (perror("pipe"));
	pid = fork();
	if (pid == -1)
		return (perror("fork"));

}

void	ft_twocmd(int *fd, char **argv, char **path, char **env)
{
	char	**cmd1;
	char	**cmd2;

	cmd1 = ft_split(argv[0], 32);
	if (!cmd1)
	{
		ft_putendl_fd("ERROR: Split fail", 2);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	cmd2 = ft_split(argv[1], 32);
	if (!cmd2)
	{
		ft_putendl_fd("ERROR: Split fail", 2);
		ft_freesplit(cmd1);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
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
