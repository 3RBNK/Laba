#include <stdint.h>
#include <assert.h>
#include <math.h>

#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vectorVoid/vector_void.h"


// тест для vector
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


// тест на добавление в конец вектора элемент
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




// тесты для void vector
// тест на создание вектора
void test_create_vector_void_1() {
    vectorVoid v = createVectorV(10, sizeof(float));

    assert(v.data != NULL && v.size == 0 && v.capacity == 10);

    deleteVectorV(&v);
}


void test_create_vector_void_2_zero_length() {
    vectorVoid v = createVectorV(0, sizeof(int));

    assert(v.data != NULL && v.size == 0 && v.capacity == 0);

    deleteVectorV(&v);
}


void test_create_vector_void() {
    test_create_vector_void_1();
    test_create_vector_void_2_zero_length();
}


// тест на добавление элемента в конец вектора
void test_push_back_1_empty_vector_void() {
    vectorVoid v = createVectorV(10, sizeof(int));

    int x = 10;
    pushBackV(&v, &x);

    int value;
    getVectorValueV(&v, 0, &value);

    assert(value == x && v.size == 1 && v.base_type_size == sizeof(int));

    deleteVectorV(&v);
}


void test_push_back_2_full_vector_void() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int x = 7;
    pushBackV(&v, &x);

    int value;
    getVectorValueV(&v, 0, &value);

    assert(value == x && v.size == 1 && v.base_type_size == sizeof(int));

    deleteVectorV(&v);
}


void test_push_back_3_not_empty_int_value_vector_void() {
    vectorVoid v = createVectorV(3, sizeof(int));

    int x[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++)
        pushBackV(&v, x + i);

    for (int i = 0; i < 3; i++) {
        int value;
        getVectorValueV(&v, i, &value);

        assert(value == x[i]);
    }
}


void test_push_back_4_not_empty_float_value_vector_void() {
    vectorVoid v = createVectorV(3, sizeof(float));

    float x[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++)
        pushBackV(&v, x + i);

    for (int i = 0; i < 3; i++) {
        float value;
        getVectorValueV(&v, i, &value);

        assert(fabs(value - x[i]) < 0.0001);
    }
}


void test_push_back_vector_void() {
    test_push_back_1_empty_vector_void();
    test_push_back_2_full_vector_void();
    test_push_back_3_not_empty_int_value_vector_void();
    test_push_back_4_not_empty_float_value_vector_void();
}


// тест на удаление последнего элемента
void test_pop_back_1_not_empty_vector_void() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int x = 2;
    pushBackV(&v, &x);

    assert(v.size == 1);
    popBackV(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVectorV(&v);
}


void test_pop_back_vector_void() {
    test_pop_back_1_not_empty_vector_void();
}


void test_vector_void() {
    test_create_vector_void();
    test_push_back_vector_void();
    test_pop_back_vector_void();
}


void test() {
    test_vector();
    test_vector_void();
}


int main() {
    test();

    return 0;
}
