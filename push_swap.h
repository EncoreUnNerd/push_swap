/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:31:03 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/04 14:47:38 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int		data;
	int		cost;
	struct s_stack *aim;
	struct s_stack *next;
	struct s_stack *previous;
}	t_stack;

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	push(t_stack **sender, t_stack **receiver, int l);
t_stack	*reverse_rotate(t_stack *stack, int l);
t_stack	*rotate(t_stack *stack, int l);
t_stack	*swap(t_stack *stack, int l);
t_stack	*add_front(t_stack *stack, int data);
int		check_args_validity(int number, char **value);
int		stack_len(t_stack *a);

#endif