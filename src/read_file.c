/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:57:56 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/25 17:29:13 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		free_arr(char ***arr)
{
	int		i;

	i = -1;
	while ((*arr)[++i] != NULL)
		free((*arr)[i]);
	free(*arr);
	if (arr != NULL)
		*arr = NULL;
}

void		read_error(char *s, int type)
{
	if (type == 1)
		perror(s);
	else if (type == 2)
		ft_putstr_fd("structure of file is incorrect!\n", 2);
	else if (type == 3)
		ft_putstr_fd("no light source on scene\n", 2);
	exit(1);
}

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
		l = (char *)(tmp->content);
		if (ft_strlen(l) == 0 || ft_strlen(l) == 1)
			read_error(NULL, 2);
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

void		del_lst(void *content, size_t size)
{
	if (content != NULL)
		free(content);
	(void)size;
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
		read_error(name, 1);
	cam = new_cam(new_p3d(200, 700, 0), normalize(new_v3d(0, -1, 0)));
	s = new_scene(0, NULL, new_p3d(255, 1000, -300), cam);
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstadd(&lst, ft_lstnew((void*)line, ft_strlen(line) *
			sizeof(char) + 1));
		free(line);
	}
	count_obj(s, lst);
	read_lines(s, lst);
	ft_lstdel(&lst, del_lst);
	if (s->obj_num == 0)
		read_error(name, 2);
	if (s->ls_num == 0)
		read_error(name, 3);
	return (s);
}
