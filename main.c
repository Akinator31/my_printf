#include "include/my.h"

int main(void)
{
    int test = 45;
    my_printf("Salut voici un pointeur %p vers %d\n", &test, test);
}
