//
// Created by Kirill on 12.02.2024.
//


#include <stdio.h>
#include <malloc.h>
#include <assert.h>


#include "vector.h"



vector createVector(size_t n) {
    // выделяем память под массив
    int *data = malloc(sizeof(int) * n);

    // если malloc не смог выделить место в буфере, то он возвращает NULL
    // если он смог выделить память, то возвращает структуру vector
    // иначе ошибку
    if (data != NULL)
        return (vector) {data,0,n};
    else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}


void reverse(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    }

    int *data = realloc(v->data, sizeof(int) * newCapacity);

    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    if (v->size > newCapacity) {
        v->data = data;
        v->size = newCapacity;
        v->capacity = newCapacity;
    } else if (v->size < newCapacity) {
        v->data = data;
        v->capacity = newCapacity;
    }
}


void clear(vector *v) {
    v->size = 0;
}


void shrinkToFit(vector *v) {
    v->capacity = v->size;
}


void deleteVector(vector *v) {
    free(v->data);

    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

