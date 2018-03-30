#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "max_subarray.c"

int main()
{
    int a[] = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79,
            94, 90, 97};
    int lidx;
    int ridx;
    int max = max_subarray(a, 0, sizeof(a) / sizeof(int) - 1, &lidx, &ridx);
    printf("the max value is %d\n", max);
    printf("from a[%d] to a[%d]\n", lidx, ridx);
//    for(int i = 0; i < 5; i++) {
//        printf("%d ", a[i]);
//    }
    printf("\n");
}
