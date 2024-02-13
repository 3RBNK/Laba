//
// Created by Kirill on 12.02.2024.
//

#ifndef CODE_VECTOR_H
#define CODE_VECTOR_H


#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;


// возвращает структуру вектор размера n
vector createVector(size_t n);


// изменяет количество памяти вектора v на newCapacity
void reserve(vector *v, size_t newCapacity);


// очищает вектор v от элементов
void clear(vector *v);


// очищает память выделенную под неиспользуемые элементы вектора v
void shrinkToFit(vector *v);


// освобождает память выделенную под вектор v
void deleteVector(vector *v);


// возвращает true, если vector v пуст
// иначе false
bool isEmpty(vector v);


// возвращает true, если vector v полон
// иначе false
bool isFull(vector v);


// возращает i-й элемент вектора v
int getVectorValue(vector v, size_t i);


// добавляет в конец вектора v элемент x
void pushBack(vector *v, int x);


// удаляет последний элемент вектора v
void popBack(vector *v);


// возвращает указатель на index-ый элемент вектора v
int* atVector(vector *v, size_t index);


// возвращает указатель на последний элемент вектора v
int* back(vector *v);


// возвращает указатель на первый элемент вектора v
int* front(vector *v);


#endif //CODE_VECTOR_H
