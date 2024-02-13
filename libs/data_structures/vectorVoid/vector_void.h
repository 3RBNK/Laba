//
// Created by Kirill on 13.02.2024.
//

#ifndef CODE_VECTOR_VOID_H
#define CODE_VECTOR_VOID_H


#include <limits.h>

typedef struct vectorVoid {
    void* data;
    size_t size;
    size_t capacity;
    size_t base_type_size;
} vectorVoid;


vectorVoid createVectorV(size_t n, size_t base_type_size);


void reserveV(vectorVoid *v, size_t new_capacity);


void shrinkToFitV(vectorVoid *v);


void clearV(vectorVoid *v);


void deleteVectorV(vectorVoid *v);


bool isEmptyV(vectorVoid v);


bool isFullV(vectorVoid v);


void getVectorValueV(vectorVoid *v, size_t index, void *destination);


void setVectorValueV(vectorVoid *v, size_t index, void *source);


void popBackV(vectorVoid *v);


void pushBackV(vectorVoid *v, void *source);

#endif //CODE_VECTOR_VOID_H
