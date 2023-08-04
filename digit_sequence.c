//
// Created by kosenko on 02.08.23.
//

#include "digit_sequence.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
digit_sequence create_digit_sequence(){
    digit_sequence result;
    result.digits= calloc(1, sizeof(char ));
    result.allocated_size=1;
    result.size=0;
    result.minus=0;
    return result;
}

void free_digit_sequence(digit_sequence sequence){
    free(sequence.digits);
}

void digit_sequence_double_size(digit_sequence *sequence){
    unsigned char* temp=sequence->digits;
    sequence->allocated_size*=2;
    sequence->digits= calloc(sequence->allocated_size, sizeof(char ));
    for(uint i=sequence->size; i--;){
        sequence->digits[i]=temp[i];
    }
    free(temp);
}

void digit_sequence_replace(digit_sequence sequence, uint index, unsigned char value){
    if(index>=sequence.size){
        errno=ERANGE;//TODO replace
        return;
    }
    sequence.digits[index]=value;
}

void digit_sequence_append(digit_sequence* sequence, unsigned char value){
    if(sequence->size==sequence->allocated_size){
        digit_sequence_double_size(sequence);
    }
    sequence->digits[sequence->size]=value;
    sequence->size++;
    //print_digit_sequence(*sequence);
}

void print_digit_sequence(digit_sequence sequence){
    printf("\nsequence: ");
    if(sequence.minus){
        printf("- ");
    }
    while(sequence.size--){
        printf("%d ", sequence.digits[sequence.size]);
    }
    printf("\n");
}

unsigned char mod_positive(int number, int base){
    int mod=number%base;
    return mod<0?mod-base:mod;
}

digit_sequence number_to_sequence(int number, int base){

    digit_sequence result = create_digit_sequence();

    if(number<0&&base>0){
        result.minus=1;
        number= abs(number);
    }
    if(number==0){
        digit_sequence_append(&result,0);
    }
    else {
        while (number){
            unsigned char remainder = mod_positive(number, base);//number % base;
            digit_sequence_append(&result,remainder);
            number-=remainder;
            number/=base;
            //printf("remainder %d, num left %d", remainder, number);
        }
    }
    return result;
}