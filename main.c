#include <stdio.h>
#include <stdlib.h>

#include "modules/inventory.h"
#include "modules/fileio.h"
#include "modules/fileio.h"

void ui();
int options();
void pause();

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
                printf("\n");
                fgetc(stdin);
                book_read_and_add();
                pause(0);
                break;
            case 2:
                printf("\n");
                books_print_all();
                pause(1);
                break;
            case 3:
                printf("\n");
                book_find();
                pause(1);
                break;
            case 4:
                printf("\n");
                fgetc(stdin);
                inventory_read_and_add();
                pause(0);
                break;
            case 5:
                printf("\n");
                inventory_print_all();
                pause(1);
                break;
            default:
                printf("Incorrect option..\n");
                pause(1);
        }
    }
}

int options()
{
    printf("\n");
    printf("----------MENU------------\n");
    int i = 1;
    printf("%d:\t Add book\n", i);
    i++;
    printf("%d:\t Print all books\n", i);
    i++;
    printf("%d:\t Find book\n", i);
    i++;
    printf("%d:\t Add inventory\n", i);
    i++;
    printf("%d:\t Print all inventory\n", i);

    printf("0:\t Exit\n");
    printf("Enter option: ");
    fscanf(stdin, "%d", &i);
    return i;
}

void pause(int do_get)
{
    printf("Press Enter to continue...");
    while(do_get--)
    {
        fgetc(stdin);
    }
    while(fgetc(stdin) != '\n');
    printf("\n");
}