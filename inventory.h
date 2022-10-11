#ifndef __INVENTORY_H_
#define __INVENTORY_H_

#include "helper.h"

// Structure for inventory
typedef struct inventory{
    book **books;
    int curr_book_id;
    int books_num;
} inventory;
// Initializes inventory
inventory inventory_init();
// Adds book to inventory
int add_book(inventory *inven, char name[], char author[]);
// Reads book from user and adds to inventory
int read_and_add_book(inventory *inven);
// Frees memory of inventory and books in it
int inventory_murder(inventory *inven);

#endif