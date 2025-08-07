/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:23:02 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 22:46:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start + 1;
	trimmed = (char *)malloc(len);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, &s1[start], len);
	return (trimmed);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	printf("=== ft_strtrim Test Cases ===\n");
	// Test 1: Normal case - spaces
	result = ft_strtrim("   Hello, World!   ", " ");
	printf("Test 1: ft_strtrim(\"   Hello, World!   \", \" \")\n");
	printf("Result: '%s' | Expected: 'Hello, World!'\n\n",
		result ? result : "NULL");
	if (result) free(result);
	// Test 2: Different characters
	result = ft_strtrim("!!!Hello, World!!!", "!");
	printf("Test 2: ft_strtrim(\"!!!Hello, World!!!\", \"!\")\n");
	printf("Result: '%s' | Expected: 'Hello, World'\n\n",
		result ? result : "NULL");
	if (result) free(result);
	// Test 3: Empty string
	result = ft_strtrim("", " ");
	printf("Test 3: ft_strtrim(\"\", \" \")\n");
	printf("Result: '%s' | Expected: ''\n\n", result ? result : "NULL");
	if (result) free(result);
	// Test 4: String with only trim characters
	result = ft_strtrim("   ", " ");
	printf("Test 4: ft_strtrim(\"   \", \" \")\n");
	printf("Result: '%s' | Expected: ''\n\n", result ? result : "NULL");
	if (result) free(result);
	// Test 5: No characters to trim
	result = ft_strtrim("Hello", " ");
	printf("Test 5: ft_strtrim(\"Hello\", \" \")\n");
	printf("Result: '%s' | Expected: 'Hello'\n\n", result ? result : "NULL");
	if (result) free(result);
	// Test 6: Empty set (should return copy of original)
	result = ft_strtrim("  Hello  ", "");
	printf("Test 6: ft_strtrim(\"  Hello  \", \"\")\n");
	printf("Result: '%s' | Expected: '  Hello  '\n\n",
		result ? result : "NULL");
	if (result) free(result);
	// Test 7: Multiple character set
	result = ft_strtrim(" \t\nHello\t\n ", " \t\n");
	printf("Test 7: ft_strtrim(\" \\t\\nHello\\t\\n \", \" \\t\\n\")\n");
	printf("Result: '%s' | Expected: 'Hello'\n\n", result ? result : "NULL");
	if (result) free(result);
	// Test 8: Only trim from beginning
	result = ft_strtrim("   Hello", " ");
	printf("Test 8: ft_strtrim(\"   Hello\", \" \")\n");
	printf("Result: '%s' | Expected: 'Hello'\n\n", result ? result : "NULL");
	if (result) free(result);
	// Test 9: Only trim from end
	result = ft_strtrim("Hello   ", " ");
	printf("Test 9: ft_strtrim(\"Hello   \", \" \")\n");
	printf("Result: '%s' | Expected: 'Hello'\n\n", result ? result : "NULL");
	if (result) free(result);
	// Test 10: Single character string to be trimmed
	result = ft_strtrim(" ", " ");
	printf("Test 10: ft_strtrim(\" \", \" \")\n");
	printf("Result: '%s' | Expected: ''\n\n", result ? result : "NULL");
	if (result) free(result);
	// Test 11: NULL inputs (should not crash)
	printf("Test 11: ft_strtrim(NULL, \" \") - Expected: NULL\n");
	result = ft_strtrim(NULL, " ");
	printf("Result: %s\n\n", result ? result : "NULL");
	printf("Test 12: ft_strtrim(\"Hello\", NULL) - Expected: NULL\n");
	result = ft_strtrim("Hello", NULL);
	printf("Result: %s\n\n", result ? result : "NULL");
	return (0);
}
*/