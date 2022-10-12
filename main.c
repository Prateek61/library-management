#include <stdio.h>
#include <stdlib.h>

#include "helper.h"
#include "inventory.h"

int main()
{
    inventory inven = inventory_init();
    while(1)
    {
        printf("continue?: ");
        if(getc(stdin) == 'n')
        {
            getc(stdin);
            break;
        }
        getc(stdin);
        inventory_read_and_add(&inven);
    }
    inventory_vomit(&inven);
    inventory_murder(&inven);
}