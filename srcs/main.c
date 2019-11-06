/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:01:26 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/18 10:44:36 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		hook_keydown(t_sdl *sdl)
{
	int		y;

	y = 0;
	mlx_destroy_image(sdl->ren, sdl->img);
	mlx_destroy_window(sdl->ren, sdl->win);
	while (y < sdl->y_max)
	{
		free(sdl->map[y]);
		++y;
	}
	free(sdl->map);
	sdl->map = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_init(t_sdl *sdl)
{
	if ((sdl->ren = mlx_init()) == NULL ||
		(sdl->win = mlx_new_window(sdl->ren, WIDTH, HEIGTH,
		"wolf")) == NULL || (sdl->img = mlx_new_image(sdl->ren,
		WIDTH, HEIGTH)) == NULL || (sdl->adr =
		(int *)mlx_get_data_addr(sdl->img,
		&sdl->bpp, &sdl->s_l, &sdl->endian)) == NULL)
	{
		if (sdl->win != NULL)
			mlx_destroy_window(sdl->ren, sdl->win);
		if (sdl->img != NULL)
			del_image(sdl);
		ft_memdel((void **)&sdl);
	}
	return ;
}

void	wolf(t_sdl *sdl)
{
	ft_init(sdl);
	sdl->i = 0;
	sdl->j = 0;
	sdl->o = 0;
	sdl->m = 0;
	mlx_hook(sdl->win, 2, (1L << 0), keyboard, sdl);
	mlx_hook(sdl->win, 3, (1L << 1), keyrelease, sdl);
	mlx_hook(sdl->win, 17, (1L << 17), hook_keydown, sdl);
	draw(sdl);
	mlx_loop_hook(sdl->ren, move, sdl);
	mlx_loop(sdl->ren);
}

int		main(int argc, char **argv)
{
	t_sdl	sdl;

	if (argc == 1)
	{
		ft_putendl_fd("./wolf3d <map> <coordinate x> <coordinate y>", 2);
		return (0);
	}
	else if (argc != 4)
	{
		ft_putendl_fd("I said : USAGE : ./wolf3d <map> <x> <y>", 2);
		return (0);
	}
	else
	{
		if (parsing(argv[1], argv[2], argv[3], &sdl) == -1)
		{
			ft_putendl_fd("Invalid map or coordinates.", 2);
			return (0);
		}
		wolf(&sdl);
		return (0);
	}
}
