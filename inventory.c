#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"
#include "inventory.h"

inventory inventory_init()
{
    inventory hmm;
    hmm.books = NULL;
    hmm.curr_book_id = 1;
    hmm.books_num = 0;
    return hmm;
}

int add_book(inventory *inven, char name[], char author[])
{
    inven->books = realloc(inven->books, sizeof(book*));
    if(inven->books == NULL) return 1;

    inven->books[inven->books_num] = book_init(inven->curr_book_id, name, author);
    inven->books_num++;
    inven->curr_book_id++;
    return 0;
}

int read_and_add_book(inventory *inven)
{
    char name[30];
    char author[30];
    printf("Enter name of book: ");
    fgets(name, 29, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter author of book: ");
    fgets(author, 29, stdin);
    author[strcspn(author, "\n")] = '\0';
    return add_book(inven, name, author);
}