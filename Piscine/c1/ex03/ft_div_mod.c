/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:32:38 by yazen             #+#    #+#             */
/*   Updated: 2025/05/21 12:25:12 by yazen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

    

void 	ft_div_mod(int a,int b,int *div,int *mod){
	*div=a/b;
	*mod=a%b;
}
int 	main(void){
	int a, b;
    int result_div; // Variable to store the division result
    int result_mod; // Variable to store the remainder

    // --- Test Case 1 ---
    a = 10;
    b = 3;
    // Call ft_div_mod, passing the addresses of result_div and result_mod
    // so the function can modify them directly via pointers.
    ft_div_mod(a, b, &result_div, &result_mod);

    // Print the results to verify
    printf("Test Case 1: a = %d, b = %d\n", a, b);
    printf("Division result (stored in div): %d\n", result_div); // Expected: 3
    printf("Remainder (stored in mod): %d\n", result_mod);      // Expected: 1
    printf("---\n");

    // --- Test Case 2 ---
    a = 25;
    b = 5;
    ft_div_mod(a, b, &result_div, &result_mod);

    printf("Test Case 2: a = %d, b = %d\n", a, b);
    printf("Division result (stored in div): %d\n", result_div); // Expected: 5
    printf("Remainder (stored in mod): %d\n", result_mod);      // Expected: 0
    printf("---\n");

    // --- Test Case 3 (with negative numbers) ---
    // Note: Integer division/modulo with negative numbers can be tricky
    // and depends on the C standard (C89 vs C99/C11).
    // gcc usually follows C99/C11 rules where a/b truncates towards zero
    // and a % b has the same sign as a.
    a = -17;
    b = 4;
    ft_div_mod(a, b, &result_div, &result_mod);

    printf("Test Case 3: a = %d, b = %d\n", a, b);
    printf("Division result (stored in div): %d\n", result_div); // Expected: -4 (for C99/C11)
    printf("Remainder (stored in mod): %d\n", result_mod);      // Expected: -1 (for C99/C11)
    printf("---\n");

    // --- Test Case 4 (b is 1) ---
    a = 99;
    b = 1;
     ft_div_mod(a, b, &result_div, &result_mod);

    printf("Test Case 4: a = %d, b = %d\n", a, b);
    printf("Division result (stored in div): %d\n", result_div); // Expected: 99
    printf("Remainder (stored in mod): %d\n", result_mod);      // Expected: 0
    printf("---\n");


    // --- Test Case 5 (a is 0) ---
    a = 0;
    b = 7;
     ft_div_mod(a, b, &result_div, &result_mod);

    printf("Test Case 5: a = %d, b = %d\n", a, b);
    printf("Division result (stored in div): %d\n", result_div); // Expected: 0
    printf("Remainder (stored in mod): %d\n", result_mod);      // Expected: 0
    printf("---\n");

    // Note: Division by zero (b = 0) is undefined behavior and will likely
    // cause your program to crash. Avoid testing with b=0 unless you have
    // requirements on how to handle it (which the source does not specify).

    return 0; // Indicate successful execution




}
