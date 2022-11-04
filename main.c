#include <stdio.h>
#include <stdlib.h>

#include "modules/inventory.h"

void ui();
int options();

int main()
{
    ui();
    return 0;
}

void ui()
{
    while(1)
    {
        printf("continue?: ");
        if(getc(stdin) == 'n')
        {
            getc(stdin);
            break;
        }
        book_read_and_add();
        getc(stdin);
    }
    books_print_all();
}

int options()
{
    int i = 1;
    printf("%d: Add book", i);
    i++;
    printf("%d: Print all books", i);

    printf("0:/t Exit");
}