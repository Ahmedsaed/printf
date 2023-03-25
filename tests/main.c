#include "../main.h"
#include <stdio.h>

int main()
{
    int count;

    printf("hallo world, number is %c, %s", '5', "yes");
    printf("\n");


    count = _printf("hallo world, number is %c, %s", '5', "yes");
    printf("\n%d\n", count);

    return (0);
}