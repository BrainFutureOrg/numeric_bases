#include <stdio.h>
#include "digit_sequence.h"

int main()
{
    //printf("%d\n", -5%-2);

    int number, base;

    printf("Enter a number in the decimal number system: ");
    scanf("%d", &number);

    printf("Enter the base of the number system (for example, 2, 8, 16): ");
    scanf("%d", &base);

    digit_sequence sequence= number_to_sequence(number, base);
    print_digit_sequence(sequence);

    free_digit_sequence(sequence);

    return 0;
}

