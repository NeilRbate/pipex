/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:30:32 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/09 14:49:07 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_waitpid(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->nb_cmd)
	{
		waitpid(data->pid[i], NULL, 0);
		i++;
	}
	free(data->pid);
}

void	ft_initdata(t_data *data, char **argv, char **env, int heredoc)
{
	data->argv = argv;
	data->env = env;
	data->path = ft_splitpath(data->env);
	if (!data->path)
		return (ft_putendl_fd("ERROR: Split PATH fail", 2), free(data),
			exit(1));
	if (heredoc == 1)
	{
		data->input = ft_openread(data->argv[1]);
		data->output = ft_openwrite(data->argv[data->argc - 1]);
	}
	else
		data->output = ft_openwritehd(data->argv[data->argc - 1]);
	if (data->output < 0)
		return (ft_freesplit(data->path), close(data->input),
			free(data), exit(0));
	data->nb_pipe = data->argc - 3;
	data->argv = data->argv + 2;
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
	data->argc = argc;
	if (ft_strcmp(argv[1], "here_doc") == 0 && ft_strlen(argv[1]) == 8)
	{
		ft_initdata(data, argv, env, 0);
		data->input = ft_heredoc(data, argv[2]);
		ret = ft_pipex(data);
		if (ret != 0)
			return (ft_freesplit(data->path), free(data), ret);
	}
	else
	{
		ft_initdata(data, argv, env, 1);
		ret = ft_pipex(data);
		if (ret != 0)
			return (ft_freesplit(data->path), free(data), ret);
	}
	return (ft_waitpid(data), ft_freesplit(data->path), free(data), ret);
}
