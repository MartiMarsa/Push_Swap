/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:28:19 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/09 17:28:22 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

// comprueba si son carácteres correctos
int	error_syntax(char *str)
{
	if (!str)
		return (1);
	if (*str != '-' && *str != '+' && (*str < '0' || *str > '9'))
		return (1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str  > '9')
			return (1);
		str++;
	}
	return (0);
}


// comprueba si hay duplicados
int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

// libera  el stack si se han encontrado errores
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

// llama a la funcion para liberar y imprime por pantalla error
void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (!((*str > 47 && *str < 58) || *str == 43 || *str == 45))
			return (0);
		else
			str++;
	}
	return (1);
}

/*
int	main(int argc, char **argv)
{
	if (argc)
		printf("%i\n", error_syntax(argv[1]));
	return (0);	
}*/