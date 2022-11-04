#include <stdio.h>
#include <stdlib.h>

#include "modules/inventory.h"
#include "modules/fileio.h"
#include "modules/fileio.h"

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
        int selected = options();
        if (selected == 0)
        {
            break;
        }
        switch(selected)
        {
            case 1:
                fgetc(stdin);
                book_read_and_add();
                break;
            case 2:
                books_print_all();
                break;
        }
    }
}

int options()
{
    printf("\n\n");
    int i = 1;
    printf("%d:\t Add book\n", i);
    i++;
    printf("%d:\t Print all books\n", i);

    printf("0:\t Exit\n");
    printf("Enter option: ");
    fscanf(stdin, "%d", &i);
    return i;
}