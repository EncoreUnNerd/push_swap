/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_stack_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:43:06 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/12 11:34:19 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_swap(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	*a = swap_r(*a);
	*b = swap_r(*b);
}

void	rotate_rotate(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	*a = rotate_r(*a);
	*b = rotate_r(*b);
}

void	reverse_rotate_rotate(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	*a = reverse_rotate_r(*a);
	*b = reverse_rotate_r(*b);
}

t_stack	*bring_to_bottom(t_stack *position, t_stack *stack, int l)
{
	if (down_or_up(position, stack) == 0)
	{
		while (where_in_stack(position, stack) != stack_len(stack) - 1)
			stack = reverse_rotate(stack, l);
	}
	else
	{
		while (where_in_stack(position, stack) != stack_len(stack) - 1)
			stack = rotate(stack, l);
	}
	return (stack);
}

t_stack	*bring_top(t_stack *position, t_stack *stack, int l)
{
	int	i;
	int	e;

	i = 0;
	if (down_or_up(position, stack) == 1)
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
	return (stack);
}
