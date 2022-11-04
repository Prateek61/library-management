#ifndef __INVENTORY_H_
#define __INVENTORY_H_

#include "helper.h"

// Structure for book
typedef struct book{
    int id;
    char name[30];
    char author[30];
} book;
// Initializes book
book book_init(int id, char name[], char author[]);
// Initializes book pointer
book *book_init_ptr(int id, char name[], char author[]);

/**************************************************************************************************/

// Structure for books info
typedef struct books_info{
    int curr_book_id;
    int total_books;
} books_info;

/**************************************************************************************************/

// Adds book
void book_add(book *new_book);
// Reads and adds book to file
int book_read_and_add();
// Prints books given vector of book ids
void books_print(int_vec *vec);
// Prints all books
void books_print_all();

#endif