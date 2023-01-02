/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:30:32 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/02 14:11:14 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	char	**path;

	if (argc < 5)
		return (ft_putendl_fd("ERROR: Too few args", 2), -1);
	path = ft_splitpath(env);
	if (!path)
		return (ft_putendl_fd("ERROR: Split PATH fail", 2), -2);
	if (ft_strcmp(argv[1], "here_doc") == 0 && ft_strlen(argv[1]) == 8)
	{
		ft_putendl_fd("test here_doc", 1);
		return (0);
		//goto parti here_doc
	}
	else
	{
		fd[0] = ft_openread(argv[1]);
		fd[1] = ft_openwrite(argv[argc-1]);
		if (fd[1] == -1)
			return (close(fd[0]), -1);
		ft_pipex(fd, argv + 2, path, env);
	}
	ft_freesplit(path);
	return (0);
}

