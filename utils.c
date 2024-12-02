/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:17 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/02 16:37:57 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(int	data)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->aim = NULL;
	node->next = NULL;
	return (node);
}

t_stack	*add_front(t_stack *stack, int data)
{
	t_stack	*new;

	new = create_node(data);
	if (!new)
		return (NULL);
	new->next = stack;
	return (new);
}