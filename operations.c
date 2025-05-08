/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:42:28 by schennal          #+#    #+#             */
/*   Updated: 2023/05/23 22:06:49 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_b->size == 0)
		return ;
	stack_a->size += 1;
	stack_b->size -= 1;
	temp = stack_b->stack[0];
	ft_memmove(stack_b->stack, stack_b->stack + 1, stack_b->size * sizeof(int));
	ft_memmove(stack_a->stack + 1, stack_a->stack, stack_a->size * sizeof(int));
	stack_a->stack[0] = temp;
	write(1, "pa\n", 3);
}

void	do_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_a->size == 0)
		return ;
	stack_b->size += 1;
	stack_a->size -= 1;
	temp = stack_a->stack[0];
	ft_memmove(stack_b->stack + 1, stack_b->stack, stack_b->size * sizeof(int));
	ft_memmove(stack_a->stack, stack_a->stack + 1, stack_a->size * sizeof(int));
	stack_b->stack[0] = temp;
	write(1, "pb\n", 3);
}

void	do_rotate(t_stack *stack, char c)
{
	int	temp;

	if (stack->size == 0)
		return ;
	temp = stack->stack[0];
	ft_memmove(stack->stack, stack->stack + 1, stack->size * sizeof(int));
	stack->stack[stack->size - 1] = temp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	do_reverse_rotate(t_stack *stack, char c)
{
	int	temp;

	if (stack->size == 0)
		return ;
	temp = stack->stack[stack->size - 1];
	ft_memmove(stack->stack + 1, stack->stack, stack->size * sizeof(int));
	stack->stack[0] = temp;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	do_swap(t_stack *stack, char c)
{
	int	temp;

	if (stack->size == 0)
		return ;
	temp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}
