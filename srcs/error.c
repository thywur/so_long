/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:09:50 by alermolo          #+#    #+#             */
/*   Updated: 2024/02/06 13:50:02 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(t_data *data, char *err)
{
	if (write(2, "Error\n", 6) == -1)
		free_and_exit(data, EXIT_FAILURE);
	if (write(2, err, ft_strlen(err)) == -1)
		free_and_exit(data, EXIT_FAILURE);
	if (write(2, "\n", 1) == -1)
		free_and_exit(data, EXIT_FAILURE);
	free_and_exit(data, EXIT_FAILURE);
}
