/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 15:23:43 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 16:23:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_length;
	size_t	actual_len;
	char	*cpy;

	if (!s)
		return (NULL);
	str_length = ft_strlen(s);
	if (start >= str_length)
		return (ft_strdup(""));
	actual_len = str_length - start;
	if (len > actual_len)
		len = actual_len;
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = s[start + i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

// Test the code
/*#include <stdio.h>

int	main(void)
{
	char	*result;

	printf("=== ft_substr Test Cases ===\n");
	// Test 1: Basic substring extraction
	result = ft_substr("Hello, World!", 5, 7);
	printf("Test 1: ft_substr(\"Hello, World!\", 5, 7)\n");
	printf("Result: \"%s\" | Expected: \", World\"\n\n",
		result ? result : "NULL");
	if (result)
		free(result);
	// Test 2: Start index beyond string length
	result = ft_substr("Hello", 10, 5);
	printf("Test 2: ft_substr(\"Hello\", 10, 5)\n");
	printf("Result: \"%s\" | Expected: \"\"\n\n", result ? result : "NULL");
	if (result)
		free(result);
	// Test 3: Length exceeds remaining characters
	result = ft_substr("Hello", 2, 10);
	printf("Test 3: ft_substr(\"Hello\", 2, 10)\n");
	printf("Result: \"%s\" | Expected: \"llo\"\n\n", result ? result : "NULL");
	if (result)
		free(result);
	// Test 4: Empty string input
	result = ft_substr("", 0, 5);
	printf("Test 4: ft_substr(\"\", 0, 5)\n");
	printf("Result: \"%s\" | Expected: \"\"\n\n", result ? result : "NULL");
	if (result)
		free(result);
	// Test 5: Zero length requested
	result = ft_substr("Hello", 2, 0);
	printf("Test 5: ft_substr(\"Hello\", 2, 0)\n");
	printf("Result: \"%s\" | Expected: \"\"\n\n", result ? result : "NULL");
	if (result)
		free(result);
	// Test 6: Start at beginning, partial string
	result = ft_substr("Hello", 0, 3);
	printf("Test 6: ft_substr(\"Hello\", 0, 3)\n");
	printf("Result: \"%s\" | Expected: \"Hel\"\n\n", result ? result : "NULL");
	if (result)
		free(result);
	// Test 7: Extract entire string
	result = ft_substr("Hello", 0, 5);
	printf("Test 7: ft_substr(\"Hello\", 0, 5)\n");
	printf("Result: \"%s\" | Expected: \"Hello\"\n\n",
		result ? result : "NULL");
	if (result)
		free(result);
	// Test 8: Single character extraction
	result = ft_substr("Hello", 1, 1);
	printf("Test 8: ft_substr(\"Hello\", 1, 1)\n");
	printf("Result: \"%s\" | Expected: \"e\"\n\n", result ? result : "NULL");
	if (result)
		free(result);
	// Test 9: Start at last character
	result = ft_substr("Hello", 4, 1);
	printf("Test 9: ft_substr(\"Hello\", 4, 1)\n");
	printf("Result: \"%s\" | Expected: \"o\"\n\n", result ? result : "NULL");
	if (result)
		free(result);
	// Test 10: Very large length
	result = ft_substr("Hello", 1, 1000);
	printf("Test 10: ft_substr(\"Hello\", 1, 1000)\n");
	printf("Result: \"%s\" | Expected: \"ello\"\n\n", result ? result : "NULL");
	if (result)
		free(result);
	return (0);
}*/
