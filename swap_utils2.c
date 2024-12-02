/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:43:06 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/03 17:02:42 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_swap(t_stack **a, t_stack **b)
{
	*a = swap(*a);
	*b = swap(*b);
}

void	rotate_rotate(t_stack **a, t_stack **b)
{
	*a = rotate(*a);
	*b = rotate(*b);
}

void	reverse_rotate_rotate(t_stack **a, t_stack **b)
{
	*a = reverse_rotate(*a);
	*b = reverse_rotate(*b);
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