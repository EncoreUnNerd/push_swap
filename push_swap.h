/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:31:03 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/02 16:44:01 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int		data;
	struct s_stack *aim;
	struct s_stack *next;
}	t_stack;

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	push(t_stack **sender, t_stack **receiver);
t_stack	*reverse_rotate(t_stack *stack);
t_stack	*rotate(t_stack *stack);
t_stack	*swap(t_stack *stack);

#endif