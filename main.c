/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:40:02 by anchikri          #+#    #+#             */
/*   Updated: 2024/08/15 17:46:12 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

void	test_ft_lstnew(void)
{
	int		content;
	t_lst	*node;

	content = 42;
	node = ft_lstnew(&content);
	if (node && node->content == &content && node->next == NULL
		&& node->prev == NULL)
		printf("ft_lstnew: OK\n");
	else
		printf("ft_lstnew: FAIL\n");
	free(node);
}

void	test_ft_lstadd_back(void)
{
	t_lst_ctx	*ctx;
	char		*content1;
	char		*content2;

	ctx = ft_ctx_init();
	content1 = ft_strdup("Hello");
	content2 = ft_strdup("World");
	ft_lstadd_back(ctx, ft_lstnew(content1));
	ft_lstadd_back(ctx, ft_lstnew(content2));
	if (ctx->size == 2 && ctx->tail->content == content2
		&& ctx->head->content == content1)
		printf("ft_lstadd_back: OK\n");
	else
		printf("ft_lstadd_back: FAIL\n");
	ft_ctx_destroy(ctx);
}

void	test_ft_lstadd_front(void)
{
	t_lst_ctx	*ctx;
	char		*content1;
	char		*content2;

	ctx = ft_ctx_init();
	content1 = ft_strdup("Hello");
	content2 = ft_strdup("World");
	ft_lstadd_front(ctx, ft_lstnew(content1));
	ft_lstadd_front(ctx, ft_lstnew(content2));
	if (ctx->size == 2 && ctx->tail->content == content1
		&& ctx->head->content == content2)
		printf("ft_lstadd_front: OK\n");
	else
		printf("ft_lstadd_front: FAIL\n");
	ft_ctx_destroy(ctx);
}

void	test_ft_lstsize(void)
{
	t_lst_ctx	*ctx;
	char		*content1;
	char		*content2;

	ctx = ft_ctx_init();
	content1 = ft_strdup("Hello");
	content2 = ft_strdup("World");
	ft_lstadd_back(ctx, ft_lstnew(content1));
	ft_lstadd_back(ctx, ft_lstnew(content2));
	if (ft_lstsize(ctx) == 2)
		printf("ft_lstsize: OK\n");
	else
		printf("ft_lstsize: FAIL\n");
	ft_ctx_destroy(ctx);
}

void	*ft_strdup1(void *content)
{
	return (ft_strdup((char *)content));
}

void	test_ft_lstmap(void)
{
	t_lst_ctx	*ctx;
	t_lst_ctx	*new_ctx;
	char		*content1;
	char		*content2;

	ctx = ft_ctx_init();
	content1 = ft_strdup("Hello");
	content2 = ft_strdup("World");
	ft_lstadd_back(ctx, ft_lstnew(content1));
	ft_lstadd_back(ctx, ft_lstnew(content2));
	new_ctx = ft_lstmap(ctx, ft_strdup1, &free);
	if (new_ctx != NULL)
	{
		if (new_ctx->size == 2 \
			&& strcmp((char *)new_ctx->tail->content, "World") == 0 \
			&& strcmp((char *)new_ctx->head->content, "Hello") == 0)
			printf("ft_lstmap: OK\n");
		else
			printf("ft_lstmap: FAIL\n");
	}
	else
		printf("ft_lstmap: FAIL\n");
	ft_ctx_destroy(ctx);
	ft_ctx_destroy(new_ctx);
}

void	test_ft_lstlast(void)
{
	t_lst_ctx	*ctx;
	char		*content1;
	char		*content2;

	ctx = ft_ctx_init();
	content1 = ft_strdup("Hello");
	content2 = ft_strdup("World");
	ft_lstadd_back(ctx, ft_lstnew(content1));
	ft_lstadd_back(ctx, ft_lstnew(content2));
	if (ft_lstlast(ctx)->content == content2)
		printf("ft_lstlast: OK\n");
	else
		printf("ft_lstlast: FAIL\n");
	ft_ctx_destroy(ctx);
}

void	test_ft_lstclear(void)
{
	t_lst_ctx	*ctx;
	char		*content1;
	char		*content2;

	ctx = ft_ctx_init();
	content1 = ft_strdup("Hello");
	content2 = ft_strdup("World");
	ft_lstadd_back(ctx, ft_lstnew(content1));
	ft_lstadd_back(ctx, ft_lstnew(content2));
	ft_lstclear(ctx, &free);
	if (ctx->size == 0 && ctx->head == NULL && ctx->tail == NULL)
		printf("ft_lstclear: OK\n");
	else
		printf("ft_lstclear: FAIL\n");
	ft_ctx_destroy(ctx);
}

int	main(void)
{
	test_ft_lstnew();
	test_ft_lstadd_back();
	test_ft_lstadd_front();
	test_ft_lstsize();
	test_ft_lstmap();
	test_ft_lstlast();
	test_ft_lstclear();
	return (0);
}
