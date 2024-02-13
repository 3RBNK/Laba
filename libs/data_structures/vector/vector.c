//
// Created by Kirill on 12.02.2024.
//


#include <stdio.h>
#include <malloc.h>

#include "vector.h"


vector createVector(size_t n) {
    int *data = malloc(sizeof(int) * n);

    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {data,0,n};
}


void reserve(vector *v, size_t newCapacity) {
    if (newCapacity != 0) {
        int *data = realloc(v->data, sizeof(int) * newCapacity);

        if (data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }

        v->data = data;
        v->capacity = newCapacity;

        if (v->size > newCapacity)
            v->size = newCapacity;

    } else {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    }
}


void clear(vector *v) {
    v->size = 0;
}


void shrinkToFit(vector *v) {
    reserve(v, v->size);
}


void deleteVector(vector *v) {
    free(v->data);

    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}


bool isEmpty(vector v) {
    return v.size == 0;
}


bool isFull(vector v) {
    return v.size == v.capacity;
}


int getVectorValue(vector v, size_t i) {
    return v.data[i];
}


void pushBack(vector *v, int x) {
    if (isFull(*v)) {
        size_t new_capacity;

        if (v->capacity == 0)
            new_capacity = 1;
        else
            new_capacity = v->capacity * 2;

        reserve(v, new_capacity);
    }

    v->data[v->size] = x;
    v->size++;
}


void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "Zero length");
        exit(1);
    }

    v->size--;
}


int* atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%lld] is not exists", index);
        exit(1);
    }

    return &v->data[index];
}


int* back(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "Zero length");
        exit(1);
    }

    return &v->data[v->size - 1];
}


int* front(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "Zero length");
        exit(1);
    }

    return &v->data[0];
}
