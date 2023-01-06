/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:30:32 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/06 15:35:22 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_initdata(t_data *data, int heredoc)
{
	data->path = ft_splitpath(data->env);
	if (!data->path)
		return (ft_putendl_fd("ERROR: Split PATH fail", 2), 1);
	if (heredoc == 1)
	{
		data->input = ft_openread(data->argv[1]);
		if (data->input < 0)
			return (ft_freesplit(data->path), -1);
	}
	data->output = ft_openwrite(data->argv[data->argc - 1]);
	if (data->output < 0)
		return (ft_freesplit(data->path), close(data->input), -1);
	data->nb_pipe = data->argc - 3;
	data->argv = data->argv + 2;
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	int		ret;

	if (argc < 5)
		return (127);
	data = malloc(sizeof(*data));
	if (!data)
		return (ft_putendl_fd("ERROR: Malloc fail", 1), 1);
	data->argv = argv;
	data->env = env;
	data->argc = argc;
	if (ft_strcmp(argv[1], "here_doc") == 0 && ft_strlen(argv[1]) == 8)
	{
		ft_putendl_fd("here doc", 1);
		if (ft_initdata(data, 0) < 0)
			return (free(data), 1);
		data->input = ft_heredoc(data, argv[2]);
		ret = ft_pipex(data);
		if (ret != 0)
			return (ft_freesplit(data->path), free(data), ret);
	}
	else
	{
		if (ft_initdata(data, 1) < 0)
			return (free(data), 1);
		ret = ft_pipex(data);
		if (ret != 0)
			return (ft_freesplit(data->path), free(data), ret);
	}
	return (ft_freesplit(data->path), free(data), ret);
}
