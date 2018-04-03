void basic_multiply(int *a, int *b, int *c, int size)
{
	for(int row = 0; row < size; row++) {
		for(int col = 0; col < size; col++) {
			for(int k = 0; k < size; k++) {
				*(c + row * size + col) = *(a + row * size + k)
				        * (*(b + k * size + col));
			}
		}
	}
}
