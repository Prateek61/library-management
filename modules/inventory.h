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
typedef struct info{
    int curr_book_id;
    int total_books;
    int curr_inventory_id;
    int total_inventory;
} info;

/**************************************************************************************************/

// Adds book
void book_add(book *new_book);
// Reads and adds book to file
int book_read_and_add();
// Prints books given vector of book ids
void books_print(int_vec *vec);
// Prints all books
void books_print_all();
// Finds book
void book_find();

/**************************************************************************************************/
// Structure for inventory
typedef struct inventory{
    int id;
    int book_id;
    int amount;
    int borrowed;
} inventory;
// Initializes inventory
inventory inventory_init(int id, int book_id, int amount, int borrowed);

/**************************************************************************/
// Adds inventory
void inventory_add(inventory *new_inven);
// Reads and add inventory to file
int inventory_read_and_add();
// Reads and remove books in inventory from file
int inventory_read_and_remove();
// Prints inventory given vector of inventory ids
void inventory_print(int_vec *vec);
// Prints all inventory
void inventory_print_all(); 
// Finds inventory
void inventory_find();
// Lends book
void inventory_lend();
// Returns book
void inventory_return();

#endif