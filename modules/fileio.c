#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileio.h"
#include "helper.h"
#include "inventory.h"

const char books_file[] = "data/books"; 
const char info_file[] = "data/info";
const char inventory_file[] = "data/inventory";
const char temp_file[] = "data/temp";

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

// Updates info
int info_update(info new_info)
{
    FILE *fp = fopen(info_file, "wb");
    if (fp == NULL)
    {
        return 1;
    }
    fwrite(&new_info, sizeof(info), 1, fp);
    fclose(fp);
    return 0;
}

info info_get()
{
    info new_info;
    FILE *fp = fopen(info_file, "rb");
    if (fp)
    {
        fread(&new_info, sizeof(info), 1, fp);
        fclose(fp);
    }
    else
    {
        FILE *fpw = fopen(info_file, "wb");
        new_info.curr_book_id = 1;
        new_info.total_books = 0;
        new_info.curr_inventory_id = 1;
        new_info.total_inventory = 0;
        fwrite(&new_info, sizeof(info), 1, fpw);
        fclose(fpw);
    }

    return new_info;
}

int info_update_book_add()
{
    info new_info = info_get();
    new_info.curr_book_id++;
    new_info.total_books++;

    return info_update(new_info);
}

int info_update_inventory_add()
{
    info new_info = info_get();
    new_info.curr_inventory_id++;
    new_info.total_inventory++;

    return info_update(new_info);
}

int info_update_inventory_remove()
{
    info new_info = info_get();
    new_info.total_inventory--;

    return info_update(new_info);
}

/*****************************************************************************************************************************************/

int inventory_add_to_file(inventory *inven_ptr)
{
    FILE *fp = fopen(inventory_file, "ab");
    if (!fp)
    {
        return 1;
    }

    fwrite(inven_ptr, sizeof(inventory), 1, fp);
    fclose(fp);
    return 0;
}

inventory inventory_query_id(int inven_id)
{
    inventory new_inven = inventory_init(-1, -1, -1, -1);
    inventory temp;

    FILE *fp = fopen(inventory_file, "rb");
    if (fp)
    {
        while(fread(&temp, sizeof(inventory), 1, fp))
        {
            if (temp.id == inven_id)
            {
                new_inven = temp;
                break;
            }
        }
        fclose(fp);
    }

    return new_inven;
}

inventory inventory_query_book_id(int book_id)
{
    inventory new_inven = inventory_init(-1, -1, -1, -1);
    inventory temp;

    FILE *fp = fopen(inventory_file, "rb");
    if (fp)
    {
        while(fread(&temp, sizeof(inventory), 1, fp))
        {
            if (temp.book_id == book_id)
            {
                new_inven = temp;
                break;
            }
        }
        fclose(fp);
    }

    return new_inven;
}

int_vec inventory_get_all()
{
    int_vec vec = int_vec_init();
    inventory temp;

    FILE *fp = fopen(inventory_file, "rb");
    if (fp)
    {
        while(fread(&temp, sizeof(inventory), 1, fp))
        {
            int_vec_push_back(&vec, temp.id);
        }
        fclose(fp);
    }

    return vec;
}

int inventory_update(inventory *inven)
{
    FILE *fp = fopen(inventory_file, "rb");
    FILE *fp_tmp = fopen(temp_file, "wb");

    if (fp == NULL || fp_tmp == NULL)
    {
        return -1;
        if (fp)
        {
            fclose(fp);
        }
        if (fp_tmp)
        {
            fclose(fp_tmp);
        }
    }
    else 
    {
        inventory temp;
        while(fread(&temp, sizeof(inventory), 1, fp))
        {
            if (temp.id == inven->id)
            {
                fwrite(inven, sizeof(inventory), 1, fp_tmp);
            }
            else
            {
                fwrite(&temp, sizeof(inventory), 1, fp_tmp);
            }
        }
        fclose(fp);
        fclose(fp_tmp);
        remove(inventory_file);
        rename(temp_file, inventory_file);
    }

    return 0;
}