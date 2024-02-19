/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:19:00 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/09 16:19:02 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// string to long type
// convierte de string a long
static long	ft_atol(const char *s)
{
	long	nbr;
	int		sign;

	sign = 1;
	nbr = 0;
	while (*s < 32)
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
		nbr = nbr * 10 + (*s++ - '0');
	return (nbr * sign);
}

// appends a node to the stack
// añade un nodo al stack
static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = false;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

// stack initialization
// inicializa el stack
void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

// returns the cheapest node so far.
// devuelve el nodo que tiene el nodo de menos hasta el momento.
t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
