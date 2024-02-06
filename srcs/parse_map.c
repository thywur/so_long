/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:15:11 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/25 16:38:05 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_ber_file(char *map_path)
{
	char	*extension;

	extension = ft_strrchr(map_path, '.');
	if (extension)
	{
		if (ft_strcmp(extension, ".ber") == 0)
			return (1);
	}
	return (0);
}

void	parse_map(t_data *data, char *map_path)
{
	int		map_fd;
	char	*temp;
	char	*line;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1 || !is_ber_file(map_path))
		err_msg(data, "Please specify a valid .ber file");
	temp = NULL;
	line = get_next_line(map_fd);
	while (line)
	{
		temp = ft_strjoin_free(temp, line);
		free(line);
		line = get_next_line(map_fd);
	}
	data->map = ft_split(temp, "\n");
	data->map_check = ft_split(temp, "\n");
	free(temp);
	free(line);
	close(map_fd);
}
