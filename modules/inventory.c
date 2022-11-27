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
    new_book->id = info_get().curr_book_id;
    int err = book_add_to_file(new_book);
    if (err == 1)
    {
        new_book->id = -1;
    }
    else
    {
        info_update_book_add();
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
    book tmp_book;
    for (int i = 0; i < int_vec_size(vec); i++)
    {
        tmp_book = books_query_id(int_vec_get(vec, i));
        if (tmp_book.id > 0)
        {
            printf("%d\t|%s\t|%s\n", tmp_book.id, tmp_book.name, tmp_book.author);
        }
    }
}

void books_print_all()
{
    int_vec book_ids = books_get_all();
    books_print(&book_ids);
    int_vec_destroy(&book_ids);
}

void book_find()
{
    int_vec vec = int_vec_init();

    int id;
    printf("Enter id(0 if can't): ");
    fscanf(stdin, "%d", &id);

    if (id > 0)
    {
        int_vec_push_back(&vec, id);
    }
    else
    {
        fgetc(stdin);
        char name[30];
        char author[30];
        printf("Enter name or part of name of book('#' in cant): ");
        fgets(name, 29, stdin);
        name[strcspn(name, "\n")] = '\0';
        if (name[0] == '#')
        {
            name[0] = 0;
        }

        printf("Enter author or part of author name('#' if cant): ");
        fgets(author, 29, stdin);
        author[strcspn(author, "\n")] = '\0';
        if (author[0] == '#')
        {
            author[0] = 0;
        }

        vec = books_query(name, author);
    }
    printf("\n");
    books_print(&vec);
    int_vec_destroy(&vec);
}

/*****************************************************************************************************************************/

inventory inventory_init(int id, int book_id, int amount, int borrowed)
{
    inventory new_inven;
    new_inven.id = id;
    new_inven.book_id = book_id;
    new_inven.amount = amount;
    new_inven.borrowed = borrowed;
    return new_inven;
}

void inventory_add(inventory *new_inven)
{
    new_inven->id = info_get().curr_inventory_id;
    inventory temp_inven = inventory_query_book_id(new_inven->book_id);
    if (temp_inven.id < 1)
    {
        int err = inventory_add_to_file(new_inven);
        if (err == 1)
        {
            new_inven->id = -1;
        }
        else
        {
            info_update_inventory_add();
        }
    }
    else {
        //update inventory
        temp_inven.amount += new_inven->amount;
        inventory_update(&temp_inven);
    }

}

int inventory_read_and_add()
{
    int book_id;
    int amount;
    printf("Enter id of book: ");
    fscanf(stdin, "%d", &book_id);
    printf("Enter amount of books: ");
    fscanf(stdin, "%d", &amount);
    fgetc(stdin);

    inventory new_inven = inventory_init(-1, book_id, amount, 0);
    inventory_add(&new_inven);
    return new_inven.id;
}

void inventory_print(int_vec *vec)
{
    printf("ID\t|Book ID\t|Book Name\t|Amount\t|Borrowed\n");
    inventory tmp_inven;
    book tmp_book;
    for (int i = 0; i < int_vec_size(vec); i++)
    {
        tmp_inven = inventory_query_id(int_vec_get(vec, i));
        tmp_book = books_query_id(tmp_inven.book_id);
        if (tmp_inven.id > 0 && tmp_book.id > 0)
        {
            printf("%d\t|%d\t|%s\t|%d\t|%d\n", tmp_inven.id, tmp_inven.book_id, tmp_book.name, tmp_inven.amount, tmp_inven.borrowed);
        }
    }
}

void inventory_print_all()
{
    int_vec inventory_ids = inventory_get_all();
    inventory_print(&inventory_ids);
    int_vec_destroy(&inventory_ids);
}

void inventory_find()
{
    int_vec vec = int_vec_init();

    int inventory_id;
    int book_id;
    printf("Enter inventory id(0 if can't): ");
    fscanf(stdin, "%d", &inventory_id);

    if (inventory_id > 0)
    {
        int_vec_push_back(&vec, inventory_id);
    }
    else
    {
        printf("Enter book id(0 if can't): ");
        fscanf(stdin, "%d", &book_id);
        if (book_id > 0)
        {
            int_vec_push_back(&vec, inventory_query_book_id(book_id).id);
        }
    }

    inventory_print(&vec);
    int_vec_destroy(&vec);
}