#ifndef __INVENTORY_H_
#define __INVENTORY_H_

#include "helper.h"

// Structure for inventory
typedef struct inventory{
    book **books;
    int curr_book_id;
    int books_num;
    int total_books;
} inventory;
// Initializes inventory
inventory inventory_init();
// Adds book to inventory
book *add_book_to_inventory(inventory *inven, char name[], char author[]);
// Reads book from user and adds to inventory
int inventory_read_and_add(inventory *inven);
// Adds book to inventory and file
book *add_book(inventory *inven, char name[], char author[], char *file_name);
// Prints books in inventory
void inventory_vomit(inventory *inven);
// Frees memory of inventory and books in it
int inventory_murder(inventory *inven);

#endif