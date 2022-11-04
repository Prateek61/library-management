#ifndef __FILEIO_H_
#define __FILEIO_H_

#include "helper.h"
#include "inventory.h"

// Adds book to file
int book_add_to_file(book *book_ptr);
// Queries book by id
book books_query_id(int book_id); //todo (impliment binary search instead)
// Queries book by author and/or name
book books_query(char *name, char *author); //todo
// Gets all book ids from file
int_vec books_get_all(); //todo (make better)

// Gets books info from file
books_info books_info_get();
// Updates book info that one book was added
int books_info_update_add();

#endif