void copy_to_sub(int *sub, int *parrent, int origsize, int subsize)
{
	for(int row = 0; row < subsize; row++) {
		for(int col = 0; col < subsize; col++) {
			*(sub + row * subsize + col) = *(parrent + row * origsize + col);
		}
	}
}

void sub(int *a, int *b, int *c, int size)
{
	for(int row = 0; row < size; row++) {
		for(int col = 0; col < size; col++) {
			int offset = row * size + col;
			*(c + offset) = *(a + offset)
			        - *(b + offset);
		}
	}
}
void add(int *a, int *b, int *c, int size)
{
	for(int row = 0; row < size; row++) {
		for(int col = 0; col < size; col++) {
			int offset = row * size + col;
			*(c + offset) = *(a + offset)
			        + *(b + offset);
		}
	}
}
