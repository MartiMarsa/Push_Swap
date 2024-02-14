/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:04:31 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/11 12:04:35 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// funcion que alterna el primer con el segundo nodo del stack
static void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *stack;
	second = first->next;
	if (!*stack || !(*stack)->next)
		return ;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
}

void	sa(t_stack_node	**a)
{
	swap(a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
