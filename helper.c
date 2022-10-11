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