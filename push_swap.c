/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:08:33 by schennal          #+#    #+#             */
/*   Updated: 2023/06/01 17:33:45 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long long n)
{
	long long	tmp;

	tmp = n;
	if (tmp < 0)
	{
		tmp = -tmp;
		ft_putchar('-');
	}
	if (tmp >= 10)
	{
		ft_putnbr(tmp / 10);
		ft_putnbr(tmp % 10);
	}
	else
		ft_putchar(tmp + '0');
}

void	ft_putstr(char const *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_print_int_array(int *array, int arr_size)
{
	int	i;

	i = 0;
	if (arr_size > 0)
		ft_putchar('[');
	while (i < arr_size)
	{
		if (i + 1 == arr_size)
		{
			ft_putnbr(array[i]);
			ft_putstr("]\n");
		}
		else
		{
			ft_putnbr(array[i]);
			ft_putstr(", ");
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**string;

	if (ac == 1)
		return (1);
	if (ac < 1)
		ft_error(NULL, NULL, NULL);
	check_ip(ac, av);
	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (1);
	string = create_array(ac, av, stack_a);
	stack_a->stack = valid_array(string, stack_a);
	stack_b = ft_calloc(1, sizeof(t_stack));
	stack_b->stack = ft_calloc(stack_a->size + 1, sizeof(int));
	if (!stack_b->stack)
		return (1);
	stack_b->size = 0;
	if (!stack_b)
		ft_error(string, stack_a, stack_a->stack);
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
