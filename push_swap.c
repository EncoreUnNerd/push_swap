/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:31:07 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/12 14:37:31 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top(t_stack **s1, t_stack **s2, t_stack *p, int e[2])
{
	if (down_or_up(p, *s1) && down_or_up(p->aim, *s2))
	{
		while (check_if_on_top(p, *s1) == 0 && \
				check_if_on_top(p->aim, *s2) == 0)
			reverse_rotate_rotate(s1, s2);
		if (check_if_on_top(p->aim, *s2))
			*s1 = bring_top(p, *s1, e[0]);
		else
			*s2 = bring_top(p->aim, *s2, e[1]);
	}
	else if (down_or_up(p, *s1) == 0 && down_or_up(p->aim, *s2) == 0)
	{
		while (check_if_on_top(p, *s1) == 0 && \
				check_if_on_top(p->aim, *s2) == 0)
		{
			rotate_rotate(s1, s2);
		}
		if (!check_if_on_top(p, *s1))
			*s1 = bring_top(p, *s1, e[0]);
		else
			*s2 = bring_top(p->aim, *s2, e[1]);
	}
	else
		move_top_separely(s1, s2, p, e);
}

void	push_back(t_stack **b, t_stack **a, t_stack *tmp)
{
	while (*b)
	{
		tmp = to_push_b(*b, *a);
		move_top(b, a, tmp, (int []){0, 1});
		push(b, a, 1);
	}
}

void	sorting(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	while (stack_len(a) > 3)
	{
		if (stack_len(b) < 2)
			push(&a, &b, 0);
		else
		{
			tmp = to_push_l(a, b);
			move_top(&a, &b, tmp, (int []){1, 0});
			push(&a, &b, 0);
		}
	}
	tmp = biggest_in_stack(a);
	if (where_in_stack(tmp, a) != stack_len(a) - 1)
		a = bring_to_bottom(tmp, a, 1);
	if (!is_sorted(a))
		a = swap(a, 1);
	push_back(&b, &a, tmp);
	if (!is_sorted(a))
		a = bring_top(smallest_in_stack(a), a, 1);
	free_all_nodes(a);
}

void	add_nodes(int ac, char **av, t_stack **a)
{
	int		i;
	t_stack	*b;

	i = 1;
	while (i <= ac - 1)
	{
		b = add_back(*a, ft_atoi(av[i]));
		if (b == NULL)
		{
			free_all_nodes(*a);
			ft_printf("ERROR ALLOCATING NODES");
			exit(-1);
		}
		*a = b;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	else if (check_args_validity(ac, av) == 0)
		ft_printf("ERROR");
	else
	{
		add_nodes(ac, av, &a);
		if (check_doublons(a))
		{
			ft_printf("ERROR");
			free_all_nodes(a);
		}
		else if (is_sorted(a))
			free_all_nodes(a);
		else
			sorting(a, b);
	}
	return (0);
}
