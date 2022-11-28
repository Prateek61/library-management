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
                fgetc(stdin);
                inventory_read_and_remove();
                pause(0);
                break;
            case 6:
                printf("\n");
                inventory_find();
                pause(1);
                break;
            case 7:
                printf("\n");
                inventory_lend();
                pause(0);
                break;
            case 8:
                printf("\n");
                inventory_return();
                pause(0);
                break;
            case 9:
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
    printf("%d:\t Add book\n", i); // 1
    i++;
    printf("%d:\t Print all books\n", i); // 2
    i++;
    printf("%d:\t Find book\n", i); // 3
    i++;
    printf("%d:\t Add to inventory\n", i); // 4
    i++;
    printf("%d:\t Remove from inventory\n", i); // 5
    i++;
    printf("%d:\t Check availability of book\n", i); // 6
    i++;
    printf("%d:\t Lend Book\n", i); // 7
    i++;
    printf("%d:\t Return Book\n", i); // 8
    i++;
    printf("%d:\t Print all inventory\n", i); // 9

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