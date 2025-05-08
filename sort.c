/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:36:48 by schennal          #+#    #+#             */
/*   Updated: 2023/05/30 18:37:21 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if ((stack->stack[0] > stack->stack[1]) && (stack->stack[0] \
	< stack->stack[2]) && (stack->stack[1] < stack->stack[2]))
		do_swap(stack, 'a');
	else if ((stack->stack[0] > stack->stack[1]) && (stack->stack[1] \
	> stack->stack[2]) && (stack->stack[0] > stack->stack[2]))
	{
		do_swap(stack, 'a');
		do_reverse_rotate(stack, 'a');
	}
	else if ((stack->stack[0] > stack->stack[1]) && (stack->stack[0] \
	> stack->stack[2]) && (stack->stack[1] < stack->stack[2]))
		do_rotate(stack, 'a');
	else if ((stack->stack[0] < stack->stack[1]) && (stack->stack[0] \
	< stack->stack[2]) && (stack->stack[1] > stack->stack[2]))
	{
		do_swap(stack, 'a');
		do_rotate(stack, 'a');
	}
	else if ((stack->stack[0] < stack->stack[1]) && (stack->stack[0] \
	> stack->stack[2]) && (stack->stack[1] > stack->stack[2]))
		do_reverse_rotate(stack, 'a');
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->size == 2)
	{
		if (is_sorted(stack_a))
			return ;
		if (stack_a->stack[0] > stack_a->stack[1])
			do_rotate(stack_a, 'a');
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_four_and_five(stack_a, stack_b);
	else if (stack_a->size <= 120)
		chunk_sort(stack_a, stack_b, 18);
	else
		chunk_sort(stack_a, stack_b, 50);
}
