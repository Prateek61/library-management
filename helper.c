#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helper.h"

date date_init(int year, int month, int day)
{
    date hmm = {year, month, day};
    return hmm;
}

book *book_init(int id, char name[], char author[])
{
    book* hmm = (book*)malloc(sizeof(book));
    hmm->id = id;
    strcpy(hmm->name, name);
    strcpy(hmm->author, author);
    return hmm;
}

int add_book_to_file(book *book_ptr, char *file_name)
{
    FILE *fp = fopen(file_name, "ab");
    if(fp == NULL)  return 1;
    fwrite(book_ptr, sizeof(book), 1, fp);
    fclose(fp);
    return 0;
}