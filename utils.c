/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:17 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/03 17:55:50 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *create_node(int data)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->cost = -1;
	node->aim = NULL;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

t_stack	*add_front(t_stack *stack, int data)
{
	t_stack	*new;

	new = create_node(data);
	if (!new)
		return (NULL);
	new->next = stack;
	if (stack)
		stack->previous = new;
	return (new);
}

int	verif_atoi(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+' || \
		(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
	}
	else
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	check_args_validity(int number, char **value)
{
	int i;

	i = 1;
	while (i <= number - 1)
	{
		if (verif_atoi(value[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}