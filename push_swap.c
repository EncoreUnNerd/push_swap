/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:31:07 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/05 18:35:18 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			a = bring_top(tmp, a, 1);
			b = bring_top(tmp->aim, b, 0);
			push(&a, &b, 0);
		}
	}
	tmp = biggest_in_stack(a);
	if (where_in_stack(tmp, a) != stack_len(a) - 1)
		a = bring_to_bottom(tmp, a, 1);
	if (!is_sorted(a))
		a = swap(a, 1);
	while (b)
	{
		tmp = to_push_b(b, a);
		b = bring_top(tmp, b, 0);
		a = bring_top(tmp->aim, a, 1);
		push(&b, &a, 1);
	}
	if (!is_sorted(a))
		a = bring_top(smallest_in_stack(a), a, 1);
	free_all_nodes(a);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	i = 1;
	if (ac <= 1 || check_args_validity(ac, av) == 0)
		ft_printf("ERROR INVALID ARGS");
	else
	{
		while (i <= ac - 1)
		{
			a = add_back(a, ft_atoi(av[i]));
			i++;
		}
		sorting(a, b);
	}
}
