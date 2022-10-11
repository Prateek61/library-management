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
    inven->books = realloc(inven->books, sizeof(book*) * (inven->books_num + 1));
    if(inven->books == NULL) return 1;

    inven->books[inven->books_num] = book_init(inven->curr_book_id, name, author);
    inven->books_num++;
    inven->curr_book_id++;
    return 0;
}

int inventory_read_and_add(inventory *inven)
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

void inventory_vomit(inventory *inven)
{
    printf("ID|\t|Name|\t|Author\n");
    for (int i = 0; i < inven->books_num; i++)
    {
        printf("%d|\t|%s|\t|%s\n", inven->books[i]->id, inven->books[i]->name, inven->books[i]->author);
    }
    printf("\n\n\n");
}

int inventory_murder(inventory *inven)
{
    for (int i = 0; i < inven->books_num; i++)
    {
        free(inven->books[i]);
    }
    free(inven->books);
    return 0;
}