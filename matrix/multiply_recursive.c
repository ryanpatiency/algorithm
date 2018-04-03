#include <stdlib.h>
#include "matrix.h"
void multiply_recursive(int *a, int *b, int *c, int len)
{
    /*
     *  if size == 1, return;
     *
     *  divide a, b, c into subarray,
     *      copy the content
     *
     *  subc = suba*subb + suba*subb
     *  store them in s[0], s[1]
     *  conbine it
     *
     */

    if(len == 1) {
        *c = (*a) * (*b);
        return;
    }
    int halflen = len / 2;
    int subarraysize = halflen * halflen * sizeof(int);
    int *suba[2][2], *subb[2][2], *subc[2][2];
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            int offset = row * len * halflen + col * halflen;

            suba[row][col] = malloc(subarraysize);
            subb[row][col] = malloc(subarraysize);
            subc[row][col] = malloc(subarraysize);
            copy_to_sub(suba[row][col],
                        a + offset,
                        len,
                        halflen);

            copy_to_sub(subb[row][col],
                        b + offset,
                        len,
                        halflen);
        }
    }

    int *tmp1, *tmp2;
    tmp1 = malloc(subarraysize);
    tmp2 = malloc(subarraysize);
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            multiply_recursive(suba[row][0], subb[0][col], tmp1, halflen);
            multiply_recursive(suba[row][1], subb[1][col], tmp2, halflen);
            add(tmp1, tmp2, subc[row][col], halflen);
        }
    }
    free(tmp1);
    free(tmp2);
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            free(suba[row][col]);
            free(subb[row][col]);
        }
    }

    for(int row = 0; row < len; row++) {
        for(int col = 0; col < len; col++) {
            int offset = row * len + col;
            int *_subc;
            if(row / halflen) {
                if(col / halflen) {
                    _subc = subc[1][1];
                } else {
                    _subc = subc[1][0];
                }
            } else {
                if(col / halflen) {
                    _subc = subc[0][1];
                } else {
                    _subc = subc[0][0];
                }
            }
            *(c + offset) =
                    *(_subc + (row % halflen) * halflen + col % halflen);
        }
    }

    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            free(subc[row][col]);
        }
    }

}
