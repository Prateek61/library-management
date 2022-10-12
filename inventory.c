#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"
#include "inventory.h"

inventory inventory_init()
{
    inventory hmm;
    FILE *fp = fopen("data/info", "r");
    if(fp == NULL)
    {
        hmm.books = NULL;
        hmm.curr_book_id = 1;
        hmm.books_num = 0;
        hmm.total_books = 0;
    }
    else
    {
        fread(&hmm, sizeof(inventory), 1, fp);
        hmm.books = NULL;
        hmm.books_num = 0;
        fclose(fp);
    }
    return hmm;
}

void inventory_update_to_file(inventory *inven)
{
    FILE *fp = fopen("data/info", "wb");
    if (fp == NULL) printf("info file could'nt open\n");
    fwrite(inven, sizeof(inventory), 1, fp);
    fclose(fp);
}

book *add_book_to_inventory(inventory *inven, char name[], char author[])
{
    inven->books = realloc(inven->books, sizeof(book*) * (inven->books_num + 1));
    if(inven->books == NULL) return NULL;

    inven->books[inven->books_num] = book_init(inven->curr_book_id, name, author);
    inven->books_num++;
    inven->curr_book_id++;
    inven->total_books++;
    return inven->books[inven->books_num - 1];
}

book *add_book(inventory *inven, char name[], char author[], char *file_name)
{
    book *book_ptr = add_book_to_inventory(inven, name, author);
    if (book_ptr == NULL)
    {
        printf("Error!\n");
        return NULL;
    }
    add_book_to_file(book_ptr, file_name);
    inventory_update_to_file(inven);
    return book_ptr;
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
    if (add_book(inven, name, author, "data/books") == NULL)  return 1;
    return 0;
}

void inventory_vomit(inventory *inven)
{
    printf("ID\t|Name\t|Author\n");
    for (int i = 0; i < inven->books_num; i++)
    {
        printf("%d\t|%s\t|%s\n", inven->books[i]->id, inven->books[i]->name, inven->books[i]->author);
    }
    printf("Total books: %d \t %d\n", inven->curr_book_id, inven->total_books);
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