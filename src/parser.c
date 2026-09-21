/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 22:31:59 by buehara           #+#    #+#             */
/*   Updated: 2026/09/12 22:32:01 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int	invalid_name(char *filename)
{
	int		index;
	char	**name_parts;
	int		err;

	name_parts = ft_split(filename, '.');
	if (!name_parts)
		return (FAILED);
	index = 0;
	while (name_parts[index + 1] != NULL)
		index++;
	err = SUCESS;
	if (ft_strncmp(name_parts[index], "cub", 4))
		err = FAILED;
	ft_split_free(name_parts, index);
	return (err);
}

t_scene	*parser(char *argv)
{
	if (invalid_name(argv))
	{
		ft_printf("%s\n", &"Error");
		return (NULL);
	}
	ft_printf("I'm here!");
	return (NULL);
}
