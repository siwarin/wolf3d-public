/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:18:10 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/02 15:21:56 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	move2(t_sdl *sdl)
{
	if (sdl->md == 1)
	{
		if (sdl->map[(int)(sdl->play.x - sdl->play.dirx * sdl->play.speed)]
			[(int)(sdl->play.y)] == 0)
			sdl->play.x -= sdl->play.dirx * sdl->play.speed;
		if (sdl->map[(int)(sdl->play.x)]
				[(int)(sdl->play.y - sdl->play.diry * sdl->play.speed)] == 0)
			sdl->play.y -= sdl->play.diry * sdl->play.speed;
	}
	if (sdl->mu == 1)
	{
		if (sdl->map[(int)(sdl->play.x + sdl->play.dirx * sdl->play.speed)]
				[(int)(sdl->play.y)] == 0)
			sdl->play.x += sdl->play.dirx * sdl->play.speed;
		if (sdl->map[(int)(sdl->play.x)]
				[(int)(sdl->play.y + sdl->play.diry * sdl->play.speed)] == 0)
			sdl->play.y += sdl->play.diry * sdl->play.speed;
	}
	turn(sdl);
}

int		move(t_sdl *sdl)
{
	if (sdl->ml == 1)
	{
		if (sdl->map[(int)(sdl->play.x - sdl->planex * sdl->play.speed)]
				[(int)(sdl->play.y)] == 0)
			sdl->play.x -= sdl->planex * sdl->play.speed;
		if (sdl->map[(int)(sdl->play.x)]
				[(int)(sdl->play.y - sdl->planey * sdl->play.speed)] == 0)
			sdl->play.y -= sdl->planey * sdl->play.speed;
	}
	if (sdl->mr == 1)
	{
		if (sdl->map[(int)(sdl->play.x + sdl->planex * sdl->play.speed)]
				[(int)(sdl->play.y)] == 0)
			sdl->play.x += sdl->planex * sdl->play.speed;
		if (sdl->map[(int)(sdl->play.x)]
				[(int)(sdl->play.y + sdl->planey * sdl->play.speed)] == 0)
			sdl->play.y += sdl->planey * sdl->play.speed;
	}
	clear_image(sdl);
	mlx_clear_window(sdl->ren, sdl->win);
	move2(sdl);
	draw(sdl);
	return (0);
}

void	turn(t_sdl *sdl)
{
	double op;
	double od;

	if (sdl->rl == 1)
	{
		od = sdl->play.dirx;
		sdl->play.dirx = sdl->play.dirx * cos(sdl->play.rot)
			- sdl->play.diry * sin(sdl->play.rot);
		sdl->play.diry = od * sin(sdl->play.rot) + sdl->play.diry
			* cos(sdl->play.rot);
		op = sdl->planex;
		sdl->planex = sdl->planex * cos(sdl->play.rot) - sdl->planey
			* sin(sdl->play.rot);
		sdl->planey = op * sin(sdl->play.rot) + sdl->planey
			* cos(sdl->play.rot);
	}
	turn2(sdl);
}

int		keyrelease(int key, t_sdl *sdl)
{
	if (key == 13 || key == 126)
		sdl->mu = 0;
	else if (key == 1 || key == 125)
		sdl->md = 0;
	else if (key == 2)
		sdl->mr = 0;
	else if (key == 0)
		sdl->ml = 0;
	else if (key == 123)
		sdl->rl = 0;
	else if (key == 124)
		sdl->rr = 0;
	else if (key == 257 || key == 258)
		sdl->play.speed = 0.05;
	else if (key == 261 || key == 262)
		sdl->play.rot = 0.1;
	return (0);
}

int		keyboard(int key, t_sdl *sdl)
{
	if (key == 53)
		hook_keydown(sdl);
	else if (key == 15)
		wolfinit(sdl);
	else if (key == 13 || key == 126)
		sdl->mu = 1;
	else if (key == 1 || key == 125)
		sdl->md = 1;
	else if (key == 2)
		sdl->mr = 1;
	else if (key == 0)
		sdl->ml = 1;
	else if (key == 123)
		sdl->rl = 1;
	else if (key == 124)
		sdl->rr = 1;
	else if (key == 257 || key == 258)
		sdl->play.speed = 0.1;
	else if (key == 261 || key == 262)
		sdl->play.rot = 0.005;
	keyboard2(key, sdl);
	return (1);
}
