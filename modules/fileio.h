#ifndef __FILEIO_H_
#define __FILEIO_H_

#include "helper.h"
#include "inventory.h"

// Adds book to file
int book_add_to_file(book *book_ptr);
// Queries book by id
book books_query_id(int book_id); //todo (impliment binary search instead)
// Queries book by author and/or name
int_vec books_query(char *name, char *author);
// Gets ids of all books
int_vec books_get_all(); //todo (make better)

/**************************************************************************************************/

// Gets books info from file
info info_get();
// Updates info that one book was added
int info_update_book_add();
// Updates info that one inventory row was added
int info_update_inventory_add();
// Updates info that one inventory row was removed
int info_update_inventory_remove();

/**************************************************************************************************/
// Adds inventory to file
int inventory_add_to_file(inventory *inven);
// Queries inventory by id
inventory inventory_query_id(int inven_id); // todo (inplement binary search instead)
// Queries inventory by book_id
inventory inventory_query_book_id(int book_id); // (make better)
// Gets all inventory id from file
int_vec inventory_get_all(); // (make better)
// Updates inventory
int inventory_update(inventory *inven);

#endif