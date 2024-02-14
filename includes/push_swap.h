/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:07:40 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/09 15:07:43 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//HANDLE ERRORS

int	error_syntax(char *str);
int	error_duplicate(t_stack_node *a, int n);
int	ft_isdigit(char *str);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a);

//STACK INITIATION

void	init_stack_a(t_stack_node **a, char **argv);
int	main(int argc, char **argv);
char	**ft_split(const char *s, char c);

//NODES INITIATION

void	update_nodes_a(t_stack_node *a, t_stack_node *b);
void	current_index(t_stack_node *stack);
void	update_nodes_b(t_stack_node *a, t_stack_node *b);

//STACK UTILS

bool	stack_sorted(t_stack_node *stack);
int	ft_putstr_fd(char *s, int fd);
int	stack_len(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);

// COMMANDS

void	pa(t_stack_node **b, t_stack_node **a);
void	pb(t_stack_node **a, t_stack_node **b);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);
void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
								t_stack_node *cheapest);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void	sa(t_stack_node	**a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);

//ALGORITHMS 

void	sort_three(t_stack_node	**a);
void	sort_stack(t_stack_node **a, t_stack_node **b);

#endif