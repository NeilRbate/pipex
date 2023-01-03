/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:28:44 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/03 12:54:41 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef	struct	s_data
{
	pid_t	pid;
	int		input;
	int		output;
	int		pipe_fd[2];
	int		nb_cmd;
	char	**path;
	char	*pathcmd1;
	char	*pathcmd2;
	char	**argv;
	char	**env;
	char	**cmd1;
	char	**cmd2;
}				t_data

int		ft_openread(char *file);
int		ft_openwrite(char *file);
void	ft_pipex(int fd[2], char** argv, char **env);
void	ft_freesplit(char **split);
void	ft_freedata(t_data *data);
char	**ft_splitpath(char **env);


#endif
