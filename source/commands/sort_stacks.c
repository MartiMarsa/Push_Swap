/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:39:10 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/10 16:39:14 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// ensures to have the minimum value node to the top 
// situa el nodo de menor valor en la 
// cabeza de la pila para terminar el sorting
static void	min_to_top(t_stack_node **a)
{
	t_stack_node	*smaller;

	smaller = find_min(*a);
	while ((*a)->nbr != smaller->nbr)
	{
		if (smaller->above_median)
			ra(a);
		else
			rra(a);
	}
}

//ensures to have the cheapest node (a) on top and the target node (b) on
//on top of each stack. AUX OF MOVE FUNCTIONS
// situa el cheapest_node en el head de a o 
//su target en el head de b de forma eficiente
static void	prep_4_push(t_stack_node **stack, t_stack_node *top_node,
								char stack_name)
{
	while (*stack != NULL && *stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

//ensures to have the cheapest node (a) on top and the target node (b) on
//on top of each stack.
//usa el nodo de menos coste y su target para colocarlos en el head de la pila.
//aprovecha para comprobar si puede usar rotaciones simultaneas
static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if ((!cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prep_4_push(a, cheapest_node, 'a');
	prep_4_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

// sets the b target on top to do the pushing back
// situa el b->target en la cabeza de la pila de a para proceder al pushback
static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_4_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

// coordinates the sorting
// funcion que orquesta el sorting del stack
void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		update_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		update_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_to_top(a);
}
