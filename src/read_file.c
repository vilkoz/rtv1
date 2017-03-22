/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:57:56 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/22 20:57:08 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		count_obj(t_scene *s, t_list *lst)
{
	t_list		*tmp;
	char		*l;
	int			num_o;
	int			num_ls;

	tmp = lst;
	num_o = 0;
	num_ls = 0;
	while (tmp)
	{
		l = (char *)tmp->content;
		if (ft_strlen(l) == 0 || ft_strlen(l) == 1)
		{
			ft_putstr("empty line in file!\n");
			exit(1);
		}
		if ((l[0] == 's' || l[0] == 'p' || l[0] == 'y' || l[0] == 'o') &&
			l[1] == ' ')
			num_o++;
		if (l[0] == 'l' && l[1] == ' ')
			num_ls++;
		tmp = tmp->next;
	}
	s->obj_num = num_o;
	s->ls_num = num_ls;
}

void		read_sphere(t_scene *s, char **arr)
{
	int			i;
	t_sphere	sp;

	i = -1;
	sp.center.x = 0;
	sp.center.y = 0;
	sp.center.z = 0;
	sp.radius = 10;
	sp.color = 0xff50ff;
	while (arr[++i] == NULL)
	{
		(i == 1) ? sp.center.x = ft_atoi(arr[i]) : 23;
		(i == 2) ? sp.center.y = ft_atoi(arr[i]) : 23;
		(i == 3) ? sp.center.z = ft_atoi(arr[i]) : 23;
		(i == 4) ? sp.radius = ft_atoi(arr[i]) : 23;
		(i == 5) ? sp.color = ft_atoi_base(ft_strchr(arr[i], 'x'), 16) : 23;
	}
	s->objects[s->cur_o] = new_sphere(new_p3d(sp.center.x, sp.center.y,
		sp.center.z), sp.radius, sp.color);
}

void		read_lines(t_scene *s, t_list *lst)
{
	t_list		*tmp;
	char		*l;

	tmp = lst;
	while (tmp)
	{
		l = (char *)tmp->content;
		if (l[0] == 's')
			read_sphere(s, ft_strsplit(l, ' '));
		tmp = tmp->next;
	}
}

t_scene		*read_file(char *name)
{
	int			fd;
	t_scene		*s;
	t_cam		cam;
	char		*line;
	t_list		*lst;

	lst = NULL;
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		perror(name);
		exit(1);
	}
	cam = new_cam(new_p3d(200, 700, 0), normalize(new_v3d(0, -1, 0)));
	s = new_scene(0, NULL, new_p3d(255, 1000, -300), cam);
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstadd(&lst, ft_lstnew((void*)line, ft_strlen(line) * sizeof(char)));
		free(line);
	}
	if (s->objects == NULL)
	{
		ft_putstr("no objects in file\n");
		exit(1);
	}
	return (s);
}
