void basic_multiply(int *a, int *b, int *c, int len)
{
	int *_c = calloc(sizeof(int), len * len);
	for(int row = 0; row < len; row++) {
		for(int col = 0; col < len; col++) {
			for(int k = 0; k < len; k++) {
				*(_c + row * len + col) += *(a + row * len + k)
				        * (*(b + k * len + col));
			}
		}
	}
	for(int i = 0; i < len * len; i++) {
		c[i] = _c[i];
	}
	free(_c);
}
