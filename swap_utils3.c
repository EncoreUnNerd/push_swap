/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:25:38 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/05 18:31:52 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*to_push_l(t_stack *stack_s, t_stack *stack_r)
{
	t_stack	*res;
	t_stack	*go_top;

	res = NULL;
	go_top = stack_s;
	while (stack_s)
	{
		stack_s->aim = find_nearest_l(stack_s, stack_r);
		stack_s->cost = len_to_top(stack_s, go_top) \
						+ len_to_top(stack_s->aim, stack_r);
		stack_s = stack_s->next;
	}
	while (go_top)
	{
		if (res == NULL || res->cost > go_top->cost)
			res = go_top;
		go_top = go_top->next;
	}
	return (res);
}

t_stack	*to_push_b(t_stack *stack_s, t_stack *stack_r)
{
	t_stack	*res;
	t_stack	*go_top;

	res = NULL;
	go_top = stack_s;
	while (stack_s)
	{
		stack_s->aim = find_nearest_b(stack_s, stack_r);
		stack_s->cost = len_to_top(stack_s, go_top) \
						+ len_to_top(stack_s->aim, stack_r);
		stack_s = stack_s->next;
	}
	while (go_top)
	{
		if (res == NULL || res->cost > go_top->cost)
			res = go_top;
		go_top = go_top->next;
	}
	return (res);
}

t_stack	*find_nearest_l(t_stack *position, t_stack *stack)
{
	t_stack	*res;
	t_stack	*go_top;

	res = NULL;
	go_top = stack;
	while (stack)
	{
		if (stack->data < position->data)
		{
			if (res == NULL || stack->data > res->data)
				res = stack;
		}
		stack = stack->next;
	}
	if (res == NULL)
		res = biggest_in_stack(go_top);
	return (res);
}

t_stack	*find_nearest_b(t_stack *position, t_stack *stack)
{
	t_stack	*res;
	t_stack	*go_top;

	res = NULL;
	go_top = stack;
	while (stack)
	{
		if (stack->data > position->data)
		{
			if (res == NULL || stack->data < res->data)
				res = stack;
		}
		stack = stack->next;
	}
	if (res == NULL)
		res = smallest_in_stack(go_top);
	return (res);
}

void	free_all_nodes(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
