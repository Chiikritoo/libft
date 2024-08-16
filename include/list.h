/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:35:15 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/16 02:20:27 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "include.h"

typedef struct s_lst_ctx	t_lst_ctx;
typedef struct s_lst		t_lst;

struct s_lst_ctx
{
	t_lst	*head;
	t_lst	*tail;
	size_t	size;
};

struct s_lst
{
	void	*content;
	t_lst	*next;
	t_lst	*prev;
};

void		ft_ctx_destroy(t_lst_ctx *ctx);
t_lst_ctx	*ft_ctx_init(void);
void		ft_lstadd_back(t_lst_ctx *ctx, t_lst *new);
void		ft_lstadd_front(t_lst_ctx *ctx, t_lst *new);
void		ft_lstclear(t_lst_ctx *ctx, void (*del)(void *));
void		ft_lstdelone(t_lst_ctx *ctx, t_lst *lst, void (*del)(void *));
void		ft_lstiter(t_lst_ctx *ctx, void (*f)(void *));
t_lst		*ft_lstlast(t_lst_ctx *ctx);
t_lst_ctx	*ft_lstmap(t_lst_ctx *ctx, void *(*f)(void *), void (*del)(void *));
t_lst		*ft_lstnew(void *content);
int			ft_lstsize(t_lst_ctx *ctx);

#endif
