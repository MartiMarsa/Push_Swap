/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:55:19 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/11 12:55:20 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <assert.h>
#include <stdio.h>

// moves the first node to the last
// funcion que mueve el primer nodo del stack al ultimo
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack ||!(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}

// comprueba si el cheapest node y su target estan en el head
// de sendos stacks antes de ejecutar rr de forma iterativa
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}
