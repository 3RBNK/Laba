//
// Created by Kirill on 12.02.2024.
//

#ifndef CODE_VECTOR_H
#define CODE_VECTOR_H


#include <stdio.h>
#include <malloc.h>


typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;


vector createVector(size_t n);


void reverse(vector *v, size_t newCapacity);


void clear(vector *v);


void shrinkToFit(vector *v);


void deleteVector(vector *v);


#endif //CODE_VECTOR_H
