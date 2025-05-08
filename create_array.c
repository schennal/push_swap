/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:27:14 by schennal          #+#    #+#             */
/*   Updated: 2023/05/31 21:09:39 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_string(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

static int	stack_size(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] != ' ')
		j++;
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] && s[i + 1] != ' ')
			j++;
		i++;
	}
	return (j);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	i;

	if (size && (SIZE_MAX / size) < count)
		return (NULL);
	pointer = (void *) malloc(count * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		*(unsigned char *)(pointer + i) = 0;
		i++;
	}
	return (pointer);
}

char	**create_array(int ac, char **av, t_stack *stack)
{
	int		i;
	char	*s;
	char	**string;

	i = 1;
	s = ft_calloc(1, sizeof(char));
	if (!s)
		return (NULL);
	while (i < ac)
	{
		s = get_string(s, av[i]);
		if (i < ac - 1)
			s = get_string(s, " ");
		i++;
	}
	stack->size = stack_size(s);
	stack->max_size = stack_size(s);
	string = ft_split(s, ' ');
	free(s);
	return (string);
}
