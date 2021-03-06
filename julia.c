/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:03:42 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/26 10:26:30 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_dw *dw)
{
	dw->x1 = -1;
	dw->x2 = 1;
	dw->y1 = -1.2;
	dw->y2 = 1.2;
	dw->i_max = 250;
	dw->c_r = dw->x / dw->zoom + dw->x1;
	dw->c_i = dw->y / dw->zoom + dw->y1;
	dw->z_r = 0;
	dw->z_i = 0;
	dw->i = 0;
	dw->image_x = WIDTH;
	dw->image_y = LENGTH;
	dw->color = 0xFFFFFF;
	dw->zoom_x = dw->image_x / (dw->x2 - dw->x1);
	dw->zoom_y = dw->image_y / (dw->y2 - dw->y1);
	dw->c_r = 0.284;
	dw->c_i = 0.0122;
}

void	julia_init2(t_dw *dw)
{
	dw->z_r = dw->x / dw->zoom_x + dw->x1;
	dw->z_i = dw->y / dw->zoom_y + dw->y1;
	dw->i = 0;
}

void	julia(t_dw *dw)
{
	dw->x = 0;
	while (dw->x < dw->image_x)
	{
		dw->y = 0;
		while (dw->y < dw->image_y)
		{
			julia_init2(dw);
			while (dw->z_r * dw->z_r + dw->z_i * dw->z_i < 4 &&
					dw->i < dw->i_max)
			{
				dw->tmp = dw->z_r;
				dw->z_r = dw->z_r * dw->z_r - dw->z_i * dw->z_i + dw->c_r;
				dw->z_i = 2 * dw->z_i * dw->tmp + dw->c_i;
				dw->i++;
			}
			if (dw->i == dw->i_max)
				pixel_put(dw->x, dw->y, dw->color, dw);
			else
				pixel_put(dw->x, dw->y, dw->color * dw->i / dw->i_max, dw);
			dw->y++;
		}
		dw->x++;
	}
}
