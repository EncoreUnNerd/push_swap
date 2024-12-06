/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:28:45 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/06 13:34:02 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	where_in_stack(t_stack *position, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->data != position->data)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	len_to_top(t_stack *position, t_stack *stack)
{
	if (down_or_up(position, stack) == 1)
		return (stack_len(stack) - where_in_stack(position, stack));
	else
		return (where_in_stack(position, stack));
}

t_stack	*biggest_in_stack(t_stack *stack)
{
	t_stack	*res;

	res = NULL;
	while (stack)
	{
		if (res == NULL || res->data < stack->data)
			res = stack;
		stack = stack->next;
	}
	return (res);
}

t_stack	*smallest_in_stack(t_stack *stack)
{
	t_stack	*res;

	res = NULL;
	while (stack)
	{
		if (res == NULL || res->data > stack->data)
			res = stack;
		stack = stack->next;
	}
	return (res);
}

int	stack_len(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}
