#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileio.h"
#include "helper.h"
#include "inventory.h"

const char books_file[] = "data/books"; 

int book_add_to_file(book *book_ptr)
{
    FILE *fp = fopen(books_file, "ab");
    if(!fp)  return 1;
    fwrite(book_ptr, sizeof(book), 1, fp);
    fclose(fp);
    return 0;
}

book books_query_id(int book_id)
{
    FILE *fp = fopen(books_file, "rb");
    book new_book;
    new_book = book_init(-1, "", "");
    book temp_book;
    if (fp)
    {
        while(fread(&temp_book, sizeof(book), 1, fp))
        {
            if (temp_book.id == book_id)
            {
                new_book = temp_book;
                break;
            }
        }
    }
    fclose(fp);
    return new_book;
}

int_vec books_query(char *name, char *author)
{
    int_vec new_vec = int_vec_init();
    if (name[0] == 0 && author[0] == 0)
    {
        return new_vec;
    }
    FILE *fp = fopen(books_file, "rb");
    if (fp)
    {
        book temp_book;
        while(fread(&temp_book, sizeof(book), 1, fp))
        {
            if (name[0] != 0 && author[0] != 0)
            {
                if (strstr(temp_book.name, name) && strstr(temp_book.author, author))
                {
                    int_vec_push_back(&new_vec, temp_book.id);
                }
            }
            else if (name[0] != 0 && strstr(temp_book.name, name))
            {
                int_vec_push_back(&new_vec, temp_book.id);
            }
            else if (author[0] != 0 && strstr(temp_book.author, author))
            {
                int_vec_push_back(&new_vec, temp_book.id);
            }
        }

        fclose(fp);
    }

    return new_vec;
}

int_vec books_get_all()
{
    int_vec new_vec = int_vec_init();

    FILE *fp = fopen(books_file, "rb");
    if (fp)
    {
        book temp_book;
        while(fread(&temp_book, sizeof(book), 1, fp))
        {
            int_vec_push_back(&new_vec, temp_book.id);
        }
        fclose(fp);
    }
    return new_vec;
}

/*************************************************************************************************************************************/

books_info books_info_get()
{
    books_info new_info;
    FILE *fp = fopen("data/books_info", "rb");
    int exists = 0;
    if (fp)
    {
        fread(&new_info, sizeof(books_info), 1, fp);
        fclose(fp);
        exists = 1;
    }

    if (!exists)
    {
        FILE *fpw = fopen("data/books_info", "wb");
        new_info.curr_book_id = 1;
        new_info.total_books = 0;
        fwrite(&new_info, sizeof(books_info), 1, fpw);
        fclose(fpw);
    }

    return new_info;
}

int books_info_update_add()
{
    books_info new_info = books_info_get();
    new_info.curr_book_id++;
    new_info.total_books++;

    FILE *fp = fopen("data/books_info", "wb");
    if (fp == NULL)
    {
        return 1;
    }
    fwrite(&new_info, sizeof(books_info), 1, fp);
    fclose(fp);
    return 0;
}

/*****************************************************************************************************************************************/