/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:14 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/03 18:39:12 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack)
{
	t_stack *temp;


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

t_stack	*rotate(t_stack *stack)
{
	t_stack	*start;
	t_stack	*tmp;

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
	return (stack);
}

t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack	*temp;
	t_stack *start;

	if (!stack || !stack->next)
		return (stack);
	start = stack;
	temp = stack->next;
	while (stack->next)
	{
		stack = stack->next;
	}
	stack->next = start;
	start->next = NULL;
	return (temp);
}

void	push(t_stack **sender, t_stack **receiver)
{
	t_stack	*temp;

	temp = *sender;
	*sender = (*sender)->next;
	temp->next = *receiver;
	*receiver = temp;
}