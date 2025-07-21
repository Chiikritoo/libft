/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:34:39 by anchikri          #+#    #+#             */
/*   Updated: 2025/07/21 16:33:34 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../include/libft.h"

double ft_floor(double x)
{
    if (isnan(x))
        return (NAN);
    if (isinf(x))
        return (x);
    double i = (double)(long long)x;
    if (x < 0 && x != i)
        return i - 1.0;
    return i;
}

float ft_floorf(float x)
{
    if (isnan(x))
        return NAN;
    if (isinf(x))
        return x;
    float i = (float)(long long)x;
    if (x < 0 && x != i)
        return i - 1.0f;
    return i;
}

double safe_floor(t_libft *libft, double x)
{
    t_libft *safe_libft;
    if (!libft)
    {
        safe_libft = safe_libft_init();
        SET_ERROR(safe_libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
            "libft is NULL");
        PRINT_ERROR(safe_libft->error_ctx);
        libft_destroy(safe_libft);
        return 0.0;
    }
    return ft_floor(x);
}

float safe_floorf(t_libft *libft, float x)
{
    t_libft *safe_libft;
    if (!libft)
    {
        safe_libft = safe_libft_init();
        SET_ERROR(safe_libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
            "libft is NULL");
        PRINT_ERROR(safe_libft->error_ctx);
        libft_destroy(safe_libft);
        return 0.0f;
    }
    return ft_floorf(x);
} 
