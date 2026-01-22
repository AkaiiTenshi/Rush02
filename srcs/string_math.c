/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:51:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/22 17:39:03 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*divide_by_power_of_10(char *number, char *divisor)
{
	int	num_len;
	int	div_len;
	int	result_len;

	if (!number || !divisor || !is_power_of_ten(divisor))
		return (NULL);
	num_len = ft_strlen(number);
	div_len = ft_strlen(divisor);
	result_len = num_len - (div_len - 1);
	if (result_len <= 0)
		return (ft_strdup("0"));
	return (ft_substr(number, 0, result_len));
}

char	*modulo_by_power_of_10(char *number, char *divisor)
{
	int		num_len;
	int		div_len;
	int		remainder_len;
	char	*result;
	char	*trimmed;

	if (!number || !divisor || !is_power_of_ten(divisor))
		return (NULL);
	num_len = ft_strlen(number);
	div_len = ft_strlen(divisor);
	remainder_len = div_len - 1;
	if (num_len <= remainder_len)
		return (ft_strdup(number));
	result = ft_substr(number, num_len - remainder_len, remainder_len);
	trimmed = trim_leading_zeros(result);
	free(result);
	return (trimmed);
}

static int	calc_digit_diff(char n1_digit, char n2_digit, int borrow,
		int *new_borrow)
{
	int	diff;

	diff = (n1_digit - '0') - borrow - (n2_digit - '0');
	if (diff < 0)
	{
		diff += 10;
		*new_borrow = 1;
	}
	else
		*new_borrow = 0;
	return (diff);
}

static char	*subtract_helper(char *result, int len1, char *n1, char *n2)
{
	int		i;
	int		borrow;
	char	n2_digit;

	borrow = 0;
	i = 0;
	while (i < len1)
	{
		n2_digit = '0';
		if (i < (int)ft_strlen(n2))
			n2_digit = n2[ft_strlen(n2) - 1 - i];
		result[len1 - 1 - i] = calc_digit_diff(n1[len1 - 1 - i], n2_digit,
				borrow, &borrow) + '0';
		i++;
	}
	result[len1] = '\0';
	return (result);
}

char	*subtract_strings(char *n1, char *n2)
{
	char	*result;
	char	*trimmed;
	int		len1;

	if (!n1 || !n2)
		return (NULL);
	if (compare_number_strings(n1, n2) < 0)
		return (ft_strdup("0"));
	if (compare_number_strings(n1, n2) == 0)
		return (ft_strdup("0"));
	len1 = ft_strlen(n1);
	result = malloc(len1 + 1);
	if (!result)
		return (NULL);
	result = subtract_helper(result, len1, n1, n2);
	trimmed = trim_leading_zeros(result);
	free(result);
	return (trimmed);
}
