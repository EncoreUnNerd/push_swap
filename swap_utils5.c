/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:48:29 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/06 12:54:45 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack, int l)
{
	if (l == 1)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	return (swap_r(stack));
}

t_stack	*reverse_rotate(t_stack *stack, int l)
{
	if (l == 1)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	return (reverse_rotate_r(stack));
}

t_stack	*rotate(t_stack *stack, int l)
{
	if (l == 1)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	return (rotate_r(stack));
}

int	check_if_on_top(t_stack *position, t_stack *stack)
{
	if (position->data == stack->data)
		return (1);
	return (0);
}

int	down_or_up(t_stack *position, t_stack *stack)
{
	if (where_in_stack(position, stack) > (stack_len(stack) / 2))
		return (1);
	return (0);
}
