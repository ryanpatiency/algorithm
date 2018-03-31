typedef struct {
    size_t size;
    int *data;
} matrix_t;

void multiply_recursive(matrix_t *a, matrix_t *b, matrix_t *c)
{
    /*
     *  assume c is zero array
     *
     *  C = AB =>
     *
     *  C00 C01     A00 A01     B00 B01
     *  C10 C11  =  A10 A11  *  B10 B11
     *
     *  for example:
     *  {1, 2, 3, 4},
     *  {1, 2, 3, 4},
     *  {1, 2, 3, 4},
     *  {1, 2, 3, 4}
     *
     *  size = 4, size/2 = 2, C11's data start from 1*(size/2)*size+1*size/2
     */

    int size = a->size;
    int subsize = size / 2;
    if(size == 1) {
        c->data[0] += a->data[0] * b->data[0];
        return;
    }
    matrix_t _a[2][2], _b[2][2], _c[2][2];
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            _c[row][col].size = _b[row][col].size = _a[row][col].size
                    = subsize;
            _a[row][col].data = a->data + row * size * subsize;
            _b[row][col].data = b->data + row * size * subsize;
            _c[row][col].data = c->data + row * size * subsize;
        }
    }
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            for(int k = 0; k < 2; k++) {
                multiply_recursive(&_a[row][k], &_b[k][col], &_c[row][col]);
            }
        }
    }




}
