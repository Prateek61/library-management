#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"
#include "inventory.h"
#include "fileio.h"


book book_init(int id, char name[], char author[])
{
    book new_book;
    new_book.id = id;
    strcpy(new_book.name, name);
    strcpy(new_book.author, author);
    return new_book;
}

book *book_init_ptr(int id, char name[], char author[])
{
    book* hmm = (book*)malloc(sizeof(book));
    hmm->id = id;
    strcpy(hmm->name, name);
    strcpy(hmm->author, author);
    return hmm;
}

/***************************************************************************************************************/

void book_add(book *new_book)
{
    new_book->id = books_info_get().curr_book_id;
    int err = book_add_to_file(new_book);
    if (err == 1)
    {
        new_book->id = -1;
    }
}

int book_read_and_add()
{
    char name[30];
    char author[30];
    printf("Enter name of book: ");
    fgets(name, 29, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter author of book: ");
    fgets(author, 29, stdin);
    author[strcspn(author, "\n")] = '\0';

    book new_book = book_init(-1, name, author);
    book_add(&new_book);
    return new_book.id;
}

void books_print(int_vec *vec)
{
    printf("ID\t|Name\t|Author\n");
    for (int i = 0; i < int_vec_size(vec); i++)
    {
        book tmp_book = books_query_id(int_vec_get(vec, i));
         printf("%d\t|%s\t|%s\n", tmp_book.id, tmp_book.name, tmp_book.author);
    }
}

void books_print_all()
{
    int_vec book_ids = books_get_all();
    books_print(&book_ids);
    int_vec_destroy(&book_ids);
}
/*****************************************************************************************************************************/
