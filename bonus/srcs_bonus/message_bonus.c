/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:09:50 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/02 13:37:08 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	err_msg(t_data *data, char *err)
{
	if (write(2, err, ft_strlen(err)) == -1)
		free_and_exit(data, EXIT_FAILURE);
	if (write(2, "\n", 1) == -1)
		free_and_exit(data, EXIT_FAILURE);
	free_and_exit(data, EXIT_FAILURE);
}

void	win_msg(t_data *data)
{
	if (write(1, "You won! :)\n", 13) == -1)
		free_and_exit(data, EXIT_FAILURE);
	free_and_exit(data, EXIT_SUCCESS);
}

void	lose_msg(t_data *data)
{
	if (write(1, "You lost! :(\n", 13) == -1)
		free_and_exit(data, EXIT_FAILURE);
	free_and_exit(data, EXIT_SUCCESS);
}
