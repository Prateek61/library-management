#include <stdio.h>
#include <stdlib.h>

#include "fileio.h"
#include "helper.h"
#include "inventory.h"

int book_add_to_file(book *book_ptr)
{
    char file_name[] = "data/books";
    FILE *fp = fopen(file_name, "ab");
    if(!fp)  return 1;
    fwrite(book_ptr, sizeof(book), 1, fp);
    fclose(fp);
    return 0;
}

/*************************************************************************************************************************************/

books_info books_info_get()
{
    books_info new_info;
    FILE *fp = fopen("data/books_info", "rb");
    if (fp == NULL)
    {
        FILE *fpw = fopen("data/books_info", "wb");
        new_info.curr_book_id = 1;
        new_info.total_books = 0;
        fwrite(&new_info, sizeof(books_info), 1, fpw);
        fclose(fpw);
    }
    else 
    {
        fread(&new_info, sizeof(books_info), 1, fp);
    }
    fclose(fp);

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