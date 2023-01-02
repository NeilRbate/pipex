/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:28:44 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/02 12:46:05 by jbarbate         ###   ########.fr       */
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

int		ft_openread(char *file);
int		ft_openwrite(char *file);
void	ft_pipex(int fd[2], char** argv, char **env);
void	ft_freesplit(char **split);
char	**ft_splitpath(char **env);


#endif
