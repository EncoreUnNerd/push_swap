/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:31:07 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/02 16:37:08 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack *a;
	t_stack *b;
	t_stack *strt;

	b = NULL;
	a = add_front(NULL ,1);
	a = add_front(a ,2);
	a = add_front(a ,3);
	a = add_front(a ,4);
	a = add_front(a ,5);
	a = add_front(a ,6);
	a = add_front(a ,7);
	a = add_front(a ,8);
	a = add_front(a ,9);
	strt = a;
	while (a)
	{
		ft_printf("%d", a->data);
		a = a->next;
	}
	a = strt;
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	ft_printf("\n\n");
	while (b)
	{
		ft_printf("%d",b->data);
		b = b->next;
	}
	ft_printf("\n\n");
	while (a)
	{
		ft_printf("%d",a->data);
		a = a->next;
	}
	return (0);
}
