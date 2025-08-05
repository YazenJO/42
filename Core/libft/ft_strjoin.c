/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:02:04 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 15:22:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		j++;
		i++;
	}
	join[i] = '\0';
	return (join);
}

/*
#include <stdio.h>

int	main(void)
{
	char *result;

	printf("=== ft_strjoin Test Cases ===\n");

	// Test 1: Normal case
	result = ft_strjoin("Hello, ", "World!");
	printf("Test 1: ft_strjoin(\"Hello, \", \"World!\")\n");
	printf("Result: \"%s\" | Expected: \"Hello, World!\"\n\n",
		result ? result : "NULL");
	if (result) free(result);

	// Test 2: First string empty
	result = ft_strjoin("", "World!");
	printf("Test 2: ft_strjoin(\"\", \"World!\")\n");
	printf("Result: \"%s\" | Expected: \"World!\"\n\n",
		result ? result : "NULL");
	if (result) free(result);

	// Test 3: Second string empty
	result = ft_strjoin("Hello", "");
	printf("Test 3: ft_strjoin(\"Hello\", \"\")\n");
	printf("Result: \"%s\" | Expected: \"Hello\"\n\n",
		result ? result : "NULL");
	if (result) free(result);

	// Test 4: Both strings empty
	result = ft_strjoin("", "");
	printf("Test 4: ft_strjoin(\"\", \"\")\n");
	printf("Result: \"%s\" | Expected: \"\"\n\n", result ? result : "NULL");
	if (result) free(result);

	// Test 5: NULL first parameter (WILL CRASH!)
	printf("Test 5: ft_strjoin(NULL, \"World!\") - Expected: NULL or crash\n");
		result = ft_strjoin(NULL, "World!");  // Uncomment to see crash
		printf("Result: %s\n\n", result ? result : "NULL");

	// Test 6: NULL second parameter (WILL CRASH!)
	printf("Test 6: ft_strjoin(\"Hello\", NULL) - Expected: NULL or crash\n");
		result = ft_strjoin("Hello", NULL);  // Uncomment to see crash
		printf("Result: %s\n\n", result ? result : "NULL");

	// Test 7: Both NULL (WILL CRASH!)
	printf("Test 7: ft_strjoin(NULL, NULL) - Expected: NULL or crash\n");
		result = ft_strjoin(NULL, NULL);  // Uncomment to see crash
	printf("Result: %s\n\n", result ? result : "NULL");

	return (0);
}*/