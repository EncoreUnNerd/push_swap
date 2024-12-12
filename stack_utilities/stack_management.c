/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:32:49 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/12 11:34:31 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_top_separely(t_stack **s1, t_stack **s2, t_stack *p, int e[2])
{
	*s1 = bring_top(p, *s1, e[0]);
	*s2 = bring_top(p->aim, *s2, e[1]);
}

int	check_doublons(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	t_stack	*j_j;

	if (!stack || !stack->next)
		return (0);
	i = stack;
	j = stack->next;
	j_j = j;
	while (i)
	{
		while (j_j)
		{
			if (j_j->data == i->data)
				return (1);
			j_j = j_j->next;
		}
		j = j->next;
		if (j == NULL)
			return (0);
		j_j = j;
		i = i->next;
	}
	return (0);
}
