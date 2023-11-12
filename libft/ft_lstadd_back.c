/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:37:10 by aabashee          #+#    #+#             */
/*   Updated: 2023/11/12 13:04:19 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;
	}
}

// int main() 
// {
//     t_list *list = NULL;

//     // Creating a few nodes
//     t_list *node1 = ft_lstnew("Node 1");
//     t_list *node2 = ft_lstnew("Node 2");
//     t_list *node3 = ft_lstnew("Node 3");

//     // Adding nodes to the end of the list
//     ft_lstadd_back(&list, node2);
//     // ft_lstadd_back(&list, node1);
//     // ft_lstadd_back(&list, node3);

//     // Printing the contents of the list
//     t_list *current = list;
//     while (current != NULL) {
//         printf("%s\n", (char*)current->content);
//         current = current->next;
//     }

//     // Clean up the list (free memory)
//     // You should have a function for this in your library, e.g., ft_lstclear(&list, free);

//     return 0;
// }
