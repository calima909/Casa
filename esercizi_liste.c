/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esercizi_liste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin42>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:09:46 by fchiocci          #+#    #+#             */
/*   Updated: 2022/11/06 12:44:05 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct s_list{
    char *content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
    t_list *new;
    new = (t_list*) malloc (sizeof(t_list));
    if (!new)
        return(NULL);
    new->content = content;
    new->next = NULL;
    return(new);
}

t_list ft_lstadd_front(t_list **lst, t_list *new)
{
    new = ft_lstnew(new);
    new->next = *lst;
    *lst = new;
}

int ft_lstsize(t_list *lst)
{
    int i;
    
    i = 0;

    if (lst == NULL)
        return(0);    
    while (lst->next != NULL)
    {
        i++;
        lst = lst->next;
    }
    if (lst->next == NULL)
        i++;
    return(i);
}

t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return(NULL);
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    return(lst);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;
    new = ft_lstnew(new);

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*(lst));
			tmp->next = new;
            new->next = NULL;
		}
	}
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst)
        return (NULL);
    del(lst->content);
    free(lst);
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    if (!lst)
        return (NULL);
    while (*lst)
    {
        del(lst->content);
        *lst = lst->next;
        free(lst);
    }
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

int main()
{
    t_list *head;
    t_list *size;
    t_list *last;

    head = NULL;
    head = ft_lstnew("filippo");
    
    //printf("%s\n\n", head->content);
        
    ft_lstadd_front(&head, (t_list*)"marco");
    ft_lstadd_front(&head, (t_list*)"gianni");
    ft_lstadd_back(&head, (t_list*)"lorenzo");
    ft_lstadd_back(&head, (t_list*)"giovanni");
    size = head;
    while(head != NULL)    
    {
        printf("%s\n", head->content);
        head = head->next;
    }
    last = ft_lstlast(&head);
    printf("La lst_size e' %d\n", ft_lstsize(size));

    printf("Il lst_last e' %s\n", last->content);
}
