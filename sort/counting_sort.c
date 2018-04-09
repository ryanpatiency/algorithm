/**
 *  Count the frequency of each value, and use the frequency as the output
 *
 *  For i = 0 to the end of the input array
 *      record the a[i] into b[a[i]].
 *  after the record, the value of b[i] will be the frequency of the value.
 *  for the sattlelite value, we need to accumulate the value
 *  for i = 1 to the end of b array
 *      b[i] = b[i] + b[i-1]
 *  So now the b[end] will hold the size of array a, and end is actrually the
 *  biggest size of a, which is the index of the value max should go
 *  So, for i = end to 0 of the input array ( because frequency count from end)
 *      c[b[a[i]]] = a[i],
 *      b[a[i]]--;
 *  array b must be able to hold value @max
 *  array c is as the same size as array a
 *  ***note
 *  the index of array b is  the accumulated freq_of_val - 1, because the value
 *  show up once so far should be at 0
 */
#include <string.h>
void counting_sort(int *a, int size, int max)
{
    int *freq_of_val = calloc(sizeof(int), (max + 1));
    int *b = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        freq_of_val[a[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        freq_of_val[i] += freq_of_val[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        b[freq_of_val[a[i]] - 1] = a[i];
        freq_of_val[a[i]]--;
    }
    memcpy(a, b, size * sizeof(int));
}
