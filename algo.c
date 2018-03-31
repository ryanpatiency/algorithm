#include <stdio.h>
#include "matrix/multiply_recursive.c"

int main()
{
    matrix_t a, b, c;

    a.size = b.size = c.size = 2;

    int adata[] = {
        1, 2,
        3, 4
    };
    a.data = adata;

    int bdata[] = {
            2, 0,
            1, 2
    };
    b.data = bdata;

    int cdata[] = {
            0, 0,
            0, 0
    };
    c.data = cdata;

    multiply_recursive(&a, &b, &c);
    for(int i = 0; i < 4; i++) {
        printf("cdata[%d] is [%d]\n", i, cdata[i]);
        printf("\n");
    }
}
