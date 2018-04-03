/*
 *  multiply use strassen's method
 *
 *  generate four subarray for a, b, c
 *      the size of subarray should be size^2
 *      to copy the element, use a copy function
 *  generate 10 subarray for s1 to s10
 *      calculate the result
 *  generate 7 subarray for p1 to p7,
 *      call strassen for this array.
 *  free of a, b, c, s1 to s10
 *  calculate the result to subarray of c
 *  copy back the subarray of c to c
 *  free p1 to p7
 */

#include <stdlib.h>
#include "matrix.h"




void strassen(int *a, int *b, int *c, int size)
{

    if(size == 1) {
        *c = (*a) * (*b);
        return;
    }
    int subsize = size / 2;
    int *suba[2][2], *subb[2][2], *subc[2][2];
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            int offset = row * size * subsize + col * subsize;

            suba[row][col] = malloc(subsize * subsize * sizeof(int));
            subb[row][col] = malloc(subsize * subsize * sizeof(int));
            subc[row][col] = malloc(subsize * subsize * sizeof(int));

            copy_to_sub(suba[row][col],
                        a + offset,
                        size,
                        subsize);

            copy_to_sub(subb[row][col],
                        b + offset,
                        size,
                        subsize);

        }
    }

    int *s[11];
    for(int i = 1; i <= 10; i++) {
        s[i] = malloc(subsize * subsize * sizeof(int));
    }
    sub(subb[0][1], subb[1][1], s[1], subsize);
    add(suba[0][0], suba[0][1], s[2], subsize);
    add(suba[1][0], suba[1][1], s[3], subsize);
    sub(subb[1][0], subb[0][0], s[4], subsize);
    add(suba[0][0], suba[1][1], s[5], subsize);
    add(subb[0][0], subb[1][1], s[6], subsize);
    sub(suba[0][1], suba[1][1], s[7], subsize);
    add(subb[1][0], subb[1][1], s[8], subsize);
    sub(suba[0][0], suba[1][0], s[9], subsize);
    add(subb[0][0], subb[0][1], s[10], subsize);

    int *p[8];
    for(int i = 1; i <= 7; i++) {
        p[i] = malloc(subsize * subsize * sizeof(int));
    }
    strassen(suba[0][0], s[1], p[1], subsize);
    strassen(s[2], subb[1][1], p[2], subsize);
    strassen(s[3], subb[0][0], p[3], subsize);
    strassen(suba[1][1], s[4], p[4], subsize);
    strassen(s[5], s[6], p[5], subsize);
    strassen(s[7], s[8], p[6], subsize);
    strassen(s[9], s[10], p[7], subsize);
    for(int i = 1; i <= 10; i++) {
        free(s[i]);
    }
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            free(suba[row][col]);
            free(subb[row][col]);
        }
    }

    for(int row = 0; row < subsize; row++) {
        for(int col = 0; col < subsize; col++) {
            int offset = row * subsize + col;
            *(subc[0][0] + offset) = *(p[5] + offset) + *(p[4] + offset)
                    - *(p[2] + offset) + *(p[6] + offset);
            *(subc[0][1] + offset) = *(p[1] + offset) + *(p[2] + offset);
            *(subc[1][0] + offset) = *(p[3] + offset) + *(p[4] + offset);
            *(subc[1][1] + offset) = *(p[5] + offset) + *(p[1] + offset)
                    - *(p[3] + offset) - *(p[7] + offset);
        }
    }

    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            int offset = row * size + col;
            int *_subc;
            if(row / subsize) {
                if(col / subsize) {
                    _subc = subc[1][1];
                } else {
                    _subc = subc[1][0];
                }
            } else {
                if(col / subsize) {
                    _subc = subc[0][1];
                } else {
                    _subc = subc[0][0];
                }
            }
            *(c + offset) =
                    *(_subc + (row % subsize) * subsize + col % subsize);
        }
    }

    for(int i = 1; i <= 7; i++) {
        free(p[i]);
    }
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            free(subc[row][col]);
        }
    }

}
