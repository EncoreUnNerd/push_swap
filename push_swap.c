/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:31:07 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/04 14:26:47 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_all_nodes(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

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
	if (where_in_stack(position, stack) > (stack_len(stack) / 2))
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

t_stack	*find_nearest_l(t_stack *position, t_stack *stack)
{
	t_stack *res;
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
	t_stack *res;
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

t_stack	*to_push_l(t_stack *stack_s, t_stack *stack_r)
{
	t_stack	*res;
	t_stack	*go_top;

	res = NULL;
	go_top = stack_s;
	while (stack_s)
	{
		stack_s->aim = find_nearest_l(stack_s, stack_r);
		stack_s->cost = len_to_top(stack_s, go_top) + len_to_top(stack_s->aim, stack_r);
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
		stack_s->cost = len_to_top(stack_s, go_top) + len_to_top(stack_s->aim, stack_r);
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

t_stack	*bring_top(t_stack *position, t_stack *stack)
{
	int	i;
	int e;

	i = 0;
	if (where_in_stack(position, stack) > (stack_len(stack) / 2))
	{
		e = len_to_top(position, stack);
		while (i < e)
		{
			stack = reverse_rotate(stack);
			i++;
		}
	}
	else
	{
		e = len_to_top(position, stack);
		while (i < e)
		{
			stack = rotate(stack);
			i++;
		}
	}
	return(stack);
}

t_stack	*bring_to_bottom(t_stack *position, t_stack *stack)
{
	while (where_in_stack(position, stack) != stack_len(stack) - 1)
		stack = reverse_rotate(stack);
	return (stack);
}

int is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->previous == NULL || stack->previous->data < stack->data)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

void	sorting(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	while (stack_len(a) > 3)
	{
		if (stack_len(b) < 2)
			push(&a, &b);
		else
		{
			tmp = to_push_l(a, b);
			a = bring_top(tmp, a);
			b = bring_top(tmp->aim, b);
			push(&a, &b);
		}
	}
	tmp = biggest_in_stack(a);
	if (where_in_stack(tmp, a) != stack_len(a) - 1)
		a = bring_to_bottom(tmp, a);
	if (!is_sorted(a))
		a = swap(a);
	while (b)
	{
		tmp = to_push_b(b, a);
		b = bring_top(tmp, b);
		a = bring_top(tmp->aim, a);
		push(&b, &a);
	}
	if (!is_sorted(a))
		a = bring_top(smallest_in_stack(a), a);
	while (a)
	{
		ft_printf("%i ", a->data);
		if (a->next == NULL)
			break ;
		else
			a = a->next;
	}
	free_all_nodes(a);
}

int	main(int ac, char **av)
{
	int 	i;
	t_stack *a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	(void)b;
	i = 1;
	if (ac <= 1 || check_args_validity(ac, av) == 0)
		ft_printf("ERROR INVALID ARGS");
	else
	{
		while (i <= ac - 1)
		{
			a = add_front(a, ft_atoi(av[i]));
			i++;
		}
		sorting(a, b);
	}
}
