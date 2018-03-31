void basic_multiply(int **a, int **b, int **result, int size)
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            /*
             * cij = sum aik*bkj for k=0-n
             */
            result[i][j] = 0;
            for(int k = 0; k < size; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
