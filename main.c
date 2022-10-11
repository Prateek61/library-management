#include <stdio.h>
#include <stdlib.h>

#include "helper.h"
#include "inventory.h"

int main()
{
    inventory inven = inventory_init();
    inventory_read_and_add(&inven);
    printf("%s  %d\n", inven.books[0]->author, inven.books_num);
}