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




#endif //CODE_VECTOR_VOID_H
