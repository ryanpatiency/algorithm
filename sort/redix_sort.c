#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
 * sort every digit inplace.
 * implement counting sort, with specify digit
 *  @digit 1 means it is 0 to 9;
 *  @digit 2 means it is 10 to 90
 */
int getval(int val, int offset, int bits)
{
    return (val >> offset) & ((1 << bits) - 1);
}

void counting_sort_index(int *a, int size, int bits, int offset)
{
    int max = 1 << bits;
    int *freq_of_val = calloc(sizeof(int), (max));
    int *b = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        int nval = getval(a[i], offset, bits);
        freq_of_val[nval]++;
    }
    for (int i = 1; i <= max; i++) {
        freq_of_val[i] += freq_of_val[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        int nval = getval(a[i], offset, bits);
        b[freq_of_val[nval] - 1] = a[i];
        freq_of_val[nval]--;
    }
    free(freq_of_val);
    memcpy(a, b, size * sizeof(int));
    free(b);
}

void redix_sort(int *a, int size)
{
    /*
     *  so there will be b (32) bits, r bit as a group, k = 2^r as max,
     *  and d = b/r group. the runing time
     *  is d*(n+k) = b/r * (n+2^r) , minimize when r = ln(n)
     */
    if (size == 1)
        return;
    int r = log2(size);
    int b = 32;
    int max_offset = r * ((b / r) - (32 % r == 0 ? 1 : 0));
    for (int offset = 0; offset <= max_offset; offset += r) {
        counting_sort_index(a, size, r, offset);
    }
}
