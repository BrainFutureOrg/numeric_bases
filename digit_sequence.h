//
// Created by kosenko on 02.08.23.
//

#ifndef NUMERIC_BASES__DIGIT_SEQUENCE_H
#define NUMERIC_BASES__DIGIT_SEQUENCE_H
#include <stdlib.h>
typedef struct {
    unsigned char * digits;
    unsigned int allocated_size, size;
    char minus;
}digit_sequence;

void print_digit_sequence(digit_sequence sequence);

digit_sequence number_to_sequence(int number, int base);

void free_digit_sequence(digit_sequence sequence);

#endif //NUMERIC_BASES__DIGIT_SEQUENCE_H
