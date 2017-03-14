/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:11:37 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/14 19:00:21 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RTV1_H
# define _RTV1_H
# define RAD (0.0175433)
# define SIGN(x) ((x < 0) ? -1 : 1)
# define FALSE 0
# define TRUE 1
# define SWAP(a, b) do{(a) ^= (b); (b) ^= (a); (a) ^= (b);} while(0);
# define SWAP_D(a, b) do{double tmp = (a); (a) = (b); (b) = (tmp);} while(0);

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>

/*
** struct for key events
*/

typedef struct		s_k
{
	int				gopa;
}					t_k;

typedef struct		s_p2d
{
	double			x;
	double			y;
}					t_p2d;

typedef struct		s_p3d
{
	double			x;
	double			y;
	double			z;
}					t_p3d;

typedef struct		s_v3d
{
	double			x;
	double			y;
	double			z;
}					t_v3d;

/*
** Object3D
*/

typedef struct		s_o3d
{
	void			*data;
	int				(*intersect)(const void * data,
						const t_p3d ray_start,
						const t_v3d ray,
						t_p3d *inter_p);
	int				(*get_color)(void *data,
								t_p3d inter_p);
}					t_o3d;

typedef struct		s_lin
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
	int				error;
	int				error2;
	t_p2d			*p1;
	t_p2d			*p2;
}					t_lin;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_lst
{
	int				y;
	char			*line;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_e
{
	void			*mlx;
	void			*win;
	void			*img;
	int				h;
	int				w;
}					t_e;

/*
** OBJECTS:
** sphere
*/

typedef struct		s_sphere
{
	t_p3d			center;
	double			radius;
	int				color;
}					t_sphere;

t_e					*ft_mlx_init(void);
void				ft_img_px_put(t_e *e, int x, int y, int rgb);
void				ft_mlx_events(t_e *e);
int					loop_hook(t_e *e);
int					key_press(int key, t_e *e);
int					key_release(int key, t_e *e);
int					mouse_hook(int key, int x, int y, t_e *e);
int					move_hook(int x, int y, t_e *e);
double				dot_product(t_v3d v1, t_v3d v2);
t_v3d				new_v3d(double x, double y, double z);
t_p3d				new_p3d(double x, double y, double z);
t_o3d				*new_sphere(t_p3d center, double radius, int color);
int					intersect_sphere(const void *data, const t_p3d ray_start,
						const t_v3d ray, t_p3d *inter_p);

#endif
