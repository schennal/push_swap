/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:09:22 by schennal          #+#    #+#             */
/*   Updated: 2023/06/01 17:41:02 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_stack
{
	int				*stack;
	int				size;
	int				max_size;
	int				middle;
	struct s_stack	*next;
}				t_stack;

/*-----------check_ip------------*/
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		check_limits(char *str, char sign);
int		is_integer(char *str);
void	check_ip(int ac, char**av);

/*-----------check_sort------------*/
int		is_sorted(t_stack *stack);

/*-----------check_sort------------*/
int		find_index_smallest(t_stack *stack, int min);
int		find_next_smallest(t_stack *stack, int min);
void	chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size);

/*-----------create_array------------*/
char	**create_array(int argc, char **argv, t_stack *stack);
void	*ft_calloc(size_t count, size_t size);

/*-----------error------------*/
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_error(char **string, t_stack *stack, int *array);

/*-----------operations------------*/
void	do_pa(t_stack *stack_a, t_stack *stack_b);
void	do_pb(t_stack *stack_a, t_stack *stack_b);
void	do_rotate(t_stack *stack, char c);
void	do_reverse_rotate(t_stack *stack, char c);
void	do_swap(t_stack *stack, char c);

/*-----------sort_four_five------------*/
int		find_smallest(t_stack *stack);
void	smallest_to_top(t_stack *stack, char c);
void	sort_four_and_five(t_stack *stack_a, t_stack *stack_b);

/*-----------sort-----------*/
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack);

/*-----------utils_other------------*/
void	*ft_memmove(void *dst, const void *src, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

/*-----------utils_sort------------*/
int		next_largest_int(t_stack *stack, int max);
int		find_index(t_stack *stack, int number);
int		largest_number(t_stack *stack);
void	push_b_to_a(t_stack *stack_a, t_stack *stack_b);

/*-----------valid_array------------*/
long	ft_atoi(const char *str);
int		*valid_array(char	**string, t_stack *stack);

#endif