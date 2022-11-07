/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:49:48 by fchiocci          #+#    #+#             */
/*   Updated: 2022/11/07 12:01:30 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    if(!lst)
        return(NULL);
    while(*lst != NULL)
    {
        del(lst->content);
        *lst = lst->next;
        free(lst);
    }
}
