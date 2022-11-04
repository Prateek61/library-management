#ifndef __HELPER_H_
#define __HELPER_H_

// Structure for integer vector
typedef struct int_vec{
    int *vec;
    int size;
    int mem_size;
} int_vec;

// Initializes integer vector
int_vec int_vec_init();
// Adds element to back of integer vector
void int_vec_push_back(int_vec *vec, int value);
// Remones element at back of integer vector
void int_vec_pop_back(int_vec *vec);
// Adds element to a index of integer vector
void int_vec_insert(int_vec *vec, int index, int value);
// Removes element from integer vector with index
void int_vec_remove(int_vec *vec, int index);
// Gets element of a index of integer vector
int int_vec_get(int_vec *vec, int index);
// Sets element in a index of integer vector
void int_vec_set(int_vec *vec, int index, int value);
// Returns size of integer vector
int int_vec_size(int_vec *vec);
// Returns the first instance of a value in integer vector (returns -1 if not found)
int int_vec_find(int_vec *vec, int value);
// Sorts the integer vector (flag 0 for ascending and 1 for descending)
void int_vec_sort(int_vec *vec, int flag); //todo
// Prints the vector
void int_vec_print(int_vec *vec);
// Destroys the vector
void int_vec_destroy(int_vec *vec);


// Structure for date
typedef struct date{
    int year;
    int month;
    int day;
} date;
// Initializes date
date date_init(int year, int month, int day);

#endif