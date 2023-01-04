/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:07:59 by apereira          #+#    #+#             */
/*   Updated: 2023/01/04 17:56:12 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_key	*game;

	if (!(argc == 2))
		return (0);
	game = malloc(sizeof(t_key));
	game_init(game);
	open_wdw(game);
	mlx_hook(game->wdw, 2, 1L << 0, key_press, &game);
	mlx_hook(game->wdw, 17, 1L << 17, destroy_wdw, &game);
	mlx_loop(game->mlx);
	mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
