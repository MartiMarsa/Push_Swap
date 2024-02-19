/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:23:55 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/17 16:24:04 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// sets the cheapest node
// setea el nodo de menor coste de mover
static void	set_cheapest(t_stack_node *stack)
{
	long			cheapest;
	t_stack_node	*cheapest_node;

	cheapest_node = NULL;
	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

// analyses push costs
// analiza el coste de los movimientos 
static void	cost_analysis(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median)
			a->push_cost = a->index;
		else
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

// sets the target node a to b
// setea el nodo target de (a) a (b)
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	t_stack_node	*current_b;
	long			best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (a->nbr > current_b->nbr && current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

// sets the current position above or under the median
// setea la posicion del nodo actual para saber
// si esta por arriba o a bajo de la mitad del stack 
void	current_index(t_stack_node *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		index++;
	}
}

// Update the information of the nodes to enable optimal pushing
// actualiza los datos de los nodos para poder hacer el push de menor coste
void	update_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}
