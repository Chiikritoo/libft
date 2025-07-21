#include <math.h>
#include "../../include/libft.h"

double ft_ceil(double x)
{
    if (isnan(x))
        return (NAN);
    if (isinf(x))
        return (x);
    double i = (double)(long long)x;
    if (x > 0 && x != i)
        return (i + 1.0);
    return (i);
}

float ft_ceilf(float x)
{
    if (isnan(x))
        return (NAN);
    if (isinf(x))
        return (x);
    float i = (float)(long long)x;
    if (x > 0 && x != i)
        return (i + 1.0f);
    return (i);
}

double safe_ceil(t_libft *libft, double x)
{
    t_libft *safe_libft;

    if (!libft)
    {
        safe_libft = safe_libft_init();
        SET_ERROR(safe_libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
            "libft is NULL");
        PRINT_ERROR(safe_libft->error_ctx);
        libft_destroy(safe_libft);
        return (0.0);
    }
    return (ft_ceil(x));
}

float safe_ceilf(t_libft *libft, float x)
{
    t_libft *safe_libft;

    if (!libft)
    {
        safe_libft = safe_libft_init();
        SET_ERROR(safe_libft->error_ctx, ERROR_INVALID_PARAM, EINVAL,
            "libft is NULL");
        PRINT_ERROR(safe_libft->error_ctx);
        libft_destroy(safe_libft);
        return (0.0f);
    }
    return (ft_ceilf(x));
} 
