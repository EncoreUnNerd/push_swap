/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:43:06 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/04 16:34:54 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_swap(t_stack **a, t_stack **b)
{
	*a = swap(*a, 1);
	*b = swap(*b, 2);
}

void	rotate_rotate(t_stack **a, t_stack **b)
{
	*a = rotate(*a, 1);
	*b = rotate(*b, 2);
}

void	reverse_rotate_rotate(t_stack **a, t_stack **b)
{
	*a = reverse_rotate(*a, 1);
	*b = reverse_rotate(*b, 2);
}

t_stack	*bring_to_bottom(t_stack *position, t_stack *stack, int l)
{
	while (where_in_stack(position, stack) != stack_len(stack) - 1)
		stack = reverse_rotate(stack, l);
	return (stack);
}

t_stack	*bring_top(t_stack *position, t_stack *stack, int l)
{
	int	i;
	int e;

	i = 0;
	if (where_in_stack(position, stack) > (stack_len(stack) / 2))
	{
		e = len_to_top(position, stack);
		while (i < e)
		{
			stack = reverse_rotate(stack, l);
			i++;
		}
	}
	else
	{
		e = len_to_top(position, stack);
		while (i < e)
		{
			stack = rotate(stack, l);
			i++;
		}
	}
	return(stack);
}

int	stack_len(t_stack *a)
{
	int i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}