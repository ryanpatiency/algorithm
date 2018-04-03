void basic_multiply(int *a, int *b, int *c, int size)
{
	int *_c = malloc(sizeof(int) * size * size);
	for(int row = 0; row < size; row++) {
		for(int col = 0; col < size; col++) {
			for(int k = 0; k < size; k++) {
				*(_c + row * size + col) = *(a + row * size + k)
				        * (*(b + k * size + col));
			}
		}
	}
	for(int i = 0; i < size * size; i++) {
		c[i] = _c[i];
	}
	free(_c);
}
