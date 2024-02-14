/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:29:27 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/09 16:29:30 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//funcion para mostrar por pantalla los movimientos o errores
int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while(s[len])
		len++;
	return(write(fd, s, len));
}

// encuentra el ultimo nodo del stack
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// devuelve la cantidad de nodos de un stack
int	stack_len(t_stack_node *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// encuentra el nodo que tiene el valor maximo
t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max;

	max = stack;
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (max->nbr < stack->next->nbr)
			max = stack->next;
		stack = stack->next;
	}
	return (max);
}

// encuentra el nodo que tiene el valor minimo
t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min;

	min = stack;
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (min->nbr > stack->next->nbr)
			min = stack->next;
		stack = stack->next;
	}
	return (min);
}
