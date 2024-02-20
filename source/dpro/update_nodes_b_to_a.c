/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes_b_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:07:08 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/18 19:07:12 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// sets the target node from b to a
// setea el nodo target de (b) a (a)
static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	t_stack_node	*current_a;
	int				best_match;

	while (b)
	{
		best_match = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (b->nbr < current_a->nbr && current_a->nbr < best_match)
			{
				best_match = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == INT_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

// updates the node's info to do the pushing back
// actualiza los datos necesaris para poder mover los nodos de (b) a (a)
void	update_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
