/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:17 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/05 18:28:49 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_node(int data)
{
	t_stack	*node;

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

t_stack	*add_back(t_stack *stack, int data)
{
	t_stack	*new;
	t_stack	*go_top;

	go_top = stack;
	new = create_node(data);
	if (!new)
		return (NULL);
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
		stack->next = new;
		new->previous = stack;
	}
	else
		go_top = new;
	return (go_top);
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
	int	i;

	i = 1;
	while (i <= number - 1)
	{
		if (verif_atoi(value[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
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
