/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:14 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/05 18:26:30 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack, int l)
{
	t_stack	*temp;

	if (l == 1)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	if (!stack || !stack->next)
		return (stack);
	temp = stack;
	stack = stack->next;
	temp->next = stack->next;
	temp->previous = stack;
	stack->next = temp;
	stack->previous = NULL;
	if (temp->next)
		temp->next->previous = temp;
	return (stack);
}

t_stack	*reverse_rotate(t_stack *stack, int l)
{
	t_stack	*start;
	t_stack	*tmp;

	if (l == 1)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	if (!stack || !stack->next)
		return (stack);
	start = stack;
	while (stack->next)
	{
		tmp = stack;
		stack = stack->next;
	}
	tmp->next = NULL;
	stack->next = start;
	start->previous = stack;
	stack->previous = NULL;
	return (stack);
}

t_stack	*rotate(t_stack *stack, int l)
{
	t_stack	*temp;
	t_stack	*start;

	if (l == 1)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	if (!stack || !stack->next)
		return (stack);
	start = stack;
	temp = stack->next;
	while (stack->next)
		stack = stack->next;
	stack->next = start;
	start->next = NULL;
	start->previous = stack;
	temp->previous = NULL;
	return (temp);
}

void	push(t_stack **sender, t_stack **receiver, int l)
{
	t_stack	*temp;

	if (l == 1)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	temp = *sender;
	*sender = (*sender)->next;
	if (*sender)
		(*sender)->previous = NULL;
	temp->next = *receiver;
	if (*receiver)
		(*receiver)->previous = temp;
	*receiver = temp;
}
