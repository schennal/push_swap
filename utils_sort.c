/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:13:03 by schennal          #+#    #+#             */
/*   Updated: 2023/05/31 23:07:37 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_num_to_top(t_stack *stack, char c, int number)
{
	int	index;

	index = find_index(stack, number);
	if (index == -1)
		return ;
	if (index <= stack->size / 2)
	{
		while (stack->stack[0] != number)
			do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != number)
			do_reverse_rotate(stack, c);
	}
}

static void	back_to_a(t_stack *stack_a, t_stack *stack_b, \
	int first, int second)
{
	insert_num_to_top(stack_b, 'b', first);
	do_pa(stack_a, stack_b);
	insert_num_to_top(stack_b, 'b', second);
	do_pa(stack_a, stack_b);
}

void	push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	first;
	int	second;
	int	first_index;
	int	second_index;

	while (stack_b->size)
	{
		first = largest_number(stack_b);
		second = next_largest_int(stack_b, first);
		first_index = find_index(stack_b, first);
		second_index = find_index(stack_b, second);
		if (first_index > stack_b->size / 2)
			first_index = stack_b->size - first_index;
		if (second_index > stack_b->size / 2)
			second_index = stack_b->size - second_index;
		if (first_index < second_index)
			back_to_a(stack_a, stack_b, first, second);
		else
			back_to_a(stack_a, stack_b, second, first);
		if (stack_a->stack[0] > stack_a->stack[1])
			do_swap(stack_a, 'a');
	}
}
