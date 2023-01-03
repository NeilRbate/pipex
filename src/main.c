/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:30:32 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/03 12:54:45 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc < 5)
		return (ft_putendl_fd("ERROR: Too few args", 2), -1);
	data = malloc(sizeof(s_data));
	if (!data)
		return (ft_putendl_fd("ERROR: Malloc fail", 1), -1);
	data->path = ft_splitpath(env);
	if (!data->path)
		return (free(data), ft_putendl_fd("ERROR: Split PATH fail", 2), -2);
	if (ft_strcmp(argv[1], "here_doc") == 0 && ft_strlen(argv[1]) == 8)
	{
		ft_putendl_fd("test here_doc", 1);
		return (0);
		//goto parti here_doc
	}
	else
	{
		data->input = ft_openread(argv[1]);
		data->output = ft_openwrite(argv[argc-1]);
		if (data->output == -1)
			return (close(data->input), -1);
		data->nb_cmd = argc - 3;
		data->argv = data->argv+2
		ft_pipex(data);
	}
	ft_freesplit(data->path);
	return (0);
}

