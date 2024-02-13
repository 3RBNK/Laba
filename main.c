#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vectorVoid/vector_void.h"


void printVector(vector v) {
    printf("capacity: %lld\n", v.capacity);
    for (size_t i = 0; i < v.size; i++)
        printf("%d ", v.data[i]);
    printf("\n");
}


// тест на работоспособность функции create
void test_create_vector_1() {
    vector v = createVector(10);

    assert(v.data != NULL && v.size == 0 && v.capacity == 10);

    deleteVector(&v);
}


void test_create_vector_2_zero_length() {
    vector v = createVector(0);

    assert(v.size == 0 && v.capacity == 0);

    deleteVector(&v);
}


void test_create_vector() {
    test_create_vector_1();
    test_create_vector_2_zero_length();
}


// тест на добавление в конец элемента
void test_push_back_1_empty_vector() {
    vector v = createVector(10);

    pushBack(&v, 10);

    assert(v.data[0] == 10 && v.size == 1);

    deleteVector(&v);
}


void test_push_back_2_full_vector() {
    vector v = createVector(1);

    pushBack(&v, 10);
    pushBack(&v, 35);

    assert(v.data[0] == 10 && v.data[1] == 35 && v.size == 2 && v.capacity == 2);

    deleteVector(&v);
}


void test_push_back_3_zero_length_vector() {
    vector v = createVector(0);

    pushBack(&v, 7);


    assert(v.data[0] == 7 && v.size == 1 && v.capacity == 1);

    deleteVector(&v);
}


void test_push_back() {
    test_push_back_1_empty_vector();
    test_push_back_2_full_vector();
    test_push_back_3_zero_length_vector();
}


// тест на удаление последнего элемента
void test_pop_back_1_not_empty_vector() {
    vector v = createVector(0);
    pushBack(&v, 2);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}


void test_pop_back() {
    test_pop_back_1_not_empty_vector();
}


// тест на получение адреса i-го элемента вектора
void test_at_vector_1_not_empty_vector() {
    vector v = createVector(5);

    pushBack(&v, 10);
    pushBack(&v, 3);
    pushBack(&v, 9);

    int* ptr = atVector(&v, 1);

    assert(v.data[1] == *ptr);

    deleteVector(&v);
}


void test_at_vector_2_request_to_last_element() {
    vector v = createVector(4);

    pushBack(&v, 7);
    pushBack(&v, 8);
    pushBack(&v, 3);
    pushBack(&v, 12);

    int* ptr = atVector(&v, 3);

    assert(v.data[3] == *ptr);

    deleteVector(&v);
}


void test_at_vector() {
    test_at_vector_1_not_empty_vector();
    test_at_vector_2_request_to_last_element();
}


// тест на получение адреса последнего элемента вектора
void test_back_1_not_empty_vector() {
    vector v = createVector(5);

    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);

    int* ptr = back(&v);

    assert(&v.data[2] == ptr);

    deleteVector(&v);
}


void test_back_2_one_element_in_vector() {
    vector v = createVector(1);

    pushBack(&v, 2);

    int* ptr = back(&v);

    assert(&v.data[0] == ptr);

    deleteVector(&v);
}


void test_back() {
    test_back_1_not_empty_vector();
    test_back_2_one_element_in_vector();
}


// тест на получение адреса первого элемента вектора
void test_front_1_not_empty_vector() {
    vector v = createVector(5);

    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);

    int* ptr = front(&v);

    assert(&v.data[0] == ptr);

    deleteVector(&v);
}


void test_front_2_one_element_in_vector() {
    vector v = createVector(1);

    pushBack(&v, 2);

    int* ptr = front(&v);

    assert(&v.data[0] == ptr);

    deleteVector(&v);
}


void test_front() {
    test_front_1_not_empty_vector();
    test_front_2_one_element_in_vector();
}


void test_vector() {
    test_create_vector();
    test_push_back();
    test_pop_back();
    test_at_vector();
    test_back();
    test_front();
}



int main() {
    test_vector();

    vectorVoid v;

    return 0;
}
