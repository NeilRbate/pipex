/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:28:44 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/09 13:43:39 by jbarbate         ###   ########.fr       */
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

typedef struct s_data
{
	pid_t	*pid;
	int		input;
	int		output;
	int		pipe_fd[2];
	int		nb_pipe;
	int		nb_cmd;
	int		argc;
	char	**path;
	char	*pathcmd;
	char	**argv;
	char	**env;
	char	**cmd;
}				t_data;

int		ft_openread(char *file);
int		ft_openwrite(char *file);
int		ft_openwritehd(char *file);
int		ft_pipex(t_data *data);
int		ft_heredoc(t_data *data, char *limiter);
void	ft_freesplit(char **split);
void	ft_freedata(t_data *data);
char	**ft_splitpath(char **env);
#endif
