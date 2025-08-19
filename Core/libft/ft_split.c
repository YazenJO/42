/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:51:50 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 17:13:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **result, size_t count)
{
	while (count--)
		free(result[count]);
	free(result);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	fill_result(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			result[j] = ft_substr(s, start, i - start);
			if (!result[j])
				return (free_split(result, j), 0);
			j++;
		}
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	if (!fill_result(result, s, c))
		return (NULL);
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char **result;
	size_t i;

	printf("=== ft_split Test Cases ===\n");

	// Test 1: Normal case
	printf("Test 1: ft_split(\"Hello World Test\", ' ')\n");
	result = ft_split("Hello World Test", ' ');
	printf("Expected: [\"Hello\", \"World\", \"Test\"]\nResult: ");
	if (result)
	{
		i = 0;
		printf("[");
		while (result[i])
		{
			printf("\"%s\"", result[i]);
			if (result[i + 1])
				printf(", ");
			free(result[i]);
			i++;
		}
		printf("]\n\n");
		free(result);
	}
	else
		printf("NULL\n\n");

	// Test 2: Multiple delimiters
	printf("Test 2: ft_split(\"  Hello   World  \", ' ')\n");
	result = ft_split("  Hello   World  ", ' ');
	printf("Expected: [\"Hello\", \"World\"]\nResult: ");
	if (result)
	{
		i = 0;
		printf("[");
		while (result[i])
		{
			printf("\"%s\"", result[i]);
			if (result[i + 1])
				printf(", ");
			free(result[i]);
			i++;
		}
		printf("]\n\n");
		free(result);
	}
	else
		printf("NULL\n\n");

	// Test 3: Empty string
	printf("Test 3: ft_split(\"\", ' ')\n");
	result = ft_split("", ' ');
	printf("Expected: []\nResult: ");
	if (result)
	{
		printf("[");
		i = 0;
		while (result[i])
		{
			printf("\"%s\"", result[i]);
			if (result[i + 1])
				printf(", ");
			free(result[i]);
			i++;
		}
		printf("]\n\n");
		free(result);
	}
	else
		printf("NULL\n\n");

	// Test 4: Only delimiters
	printf("Test 4: ft_split(\"   \", ' ')\n");
	result = ft_split("   ", ' ');
	printf("Expected: []\nResult: ");
	if (result)
	{
		printf("[");
		i = 0;
		while (result[i])
		{
			printf("\"%s\"", result[i]);
			if (result[i + 1])
				printf(", ");
			free(result[i]);
			i++;
		}
		printf("]\n\n");
		free(result);
	}
	else
		printf("NULL\n\n");

	// Test 5: Single word
	printf("Test 5: ft_split(\"Hello\", ' ')\n");
	result = ft_split("Hello", ' ');
	printf("Expected: [\"Hello\"]\nResult: ");
	if (result)
	{
		i = 0;
		printf("[");
		while (result[i])
		{
			printf("\"%s\"", result[i]);
			if (result[i + 1])
				printf(", ");
			free(result[i]);
			i++;
		}
		printf("]\n\n");
		free(result);
	}
	else
		printf("NULL\n\n");

	// Test 6: Single character strings
	printf("Test 6: ft_split(\"a,b,c\", ',')\n");
	result = ft_split("a,b,c", ',');
	printf("Expected: [\"a\", \"b\", \"c\"]\nResult: ");
	if (result)
	{
		i = 0;
		printf("[");
		while (result[i])
		{
			printf("\"%s\"", result[i]);
			if (result[i + 1])
				printf(", ");
			free(result[i]);
			i++;
		}
		printf("]\n\n");
		free(result);
	}
	else
		printf("NULL\n\n");

	// Test 7: NULL input
	printf("Test 7: ft_split(NULL, ' ') - Expected: NULL\n");
	result = ft_split(NULL, ' ');
	printf("Result: %s\n\n", result ? "NOT NULL (ERROR!)" : "NULL");

	return (0);
}*/