/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:31:07 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/03 18:40:58 by mhenin           ###   ########.fr       */
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
	if (where_in_stack(position, stack) > (stack_len(stack) / 2))
		return ((stack_len(stack) - where_in_stack(position, stack)) + 1);
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

t_stack	*find_nearest(t_stack *position, t_stack *stack)
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

t_stack	*to_push(t_stack *a, t_stack *b)
{
	t_stack	*res;
	t_stack	*go_top;

	res = NULL;
	go_top = a;
	while (a)
	{
		a->aim = find_nearest(a, b);
		a->cost = len_to_top(a, go_top) + len_to_top(a->aim, b);
		a = a->next;
	}
	while (go_top)
	{
		if (res == NULL || res->cost > go_top->cost)
			res = go_top;
		go_top = res;
	}
	return (res);
}

/* A FAIRE :
- mettre a jour les truc dans swap_utils pour qu'il mettent bien le previous
- une fois qu'on a celui a push le mettre en haut de la stack et de meme pour son aim
- puis push
*/

// void	sorting(t_stack *a, t_stack *b)
// {
// 	int	i;

// 	i = 0;
// 	while (stack_len(a) > 3)
// 	{
// 		if (stack_len(b) < 2)
// 			push(&a, &b);
// 		else
// 		{
			 
// 		}
// 	}
// }

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
	}
	while (a)
	{
		ft_printf("%i", a->data);
		if (a->next == NULL)
			break ;
		else
			a = a->next;
	}
	ft_printf("\n");
	while (a)
	{
		ft_printf("%i", a->data);
		if (a->previous != NULL)
			a = a->previous;
		else
			break ;
	}
	a = swap(a);
	ft_printf("\n\n");
	while (a)
	{
		ft_printf("%i", a->data);
		if (a->next == NULL)
			break ;
		else
			a = a->next;
	}
	ft_printf("\n");
	while (a)
	{
		ft_printf("%i", a->data);
		if (a->previous != NULL)
			a = a->previous;
		else
			break ;
	}
	// ft_printf("%i", stack_len(a));
}
