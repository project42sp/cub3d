/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_invalid_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 01:21:59 by buehara           #+#    #+#             */
/*   Updated: 2026/10/12 01:22:06 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	invalid_name(char *filename)
{
	int		index;
	char	**name_parts;
	int		err;

	err = SUCESS;
	name_parts = ft_split(filename, '.');
	if (!name_parts)
		err = FAILED;
	index = 0;
	while (name_parts[index + 1] != NULL)
		index++;
	if (ft_strncmp(name_parts[index], "cub", 4))
		err = FAILED;
	ft_split_free(name_parts, index);
	if (err)
		printf("%s\n", "Error: Unexpected file format.");
	else
		printf("%s\n", "Cub3D: File format Accepted.");
	return (err);
}
