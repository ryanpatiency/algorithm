#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>
#include "sort/merge_sort.c"
#include "sort/insert_sort.c"
#include "matrix/basic_multiply.c"
#include "matrix/multiply_recursive.c"
#include "matrix/strassen.c"
#include "matrix/matrix.c"


#define SIZE 550

void test_matrix(void);
void rand_array(int *a, int size);
void analyze_matrix(void);

int main()
{
//	test_matrix();
	analyze_matrix();
}

void analyze_matrix(void)
{
	struct timespec ts1, ts2;
	int *a[SIZE];
	printf("input_size\tbasic multiply\trecursive\tstrassen\n");
	for(int i = 500; i < SIZE; i++) {
		int array_size = i * i;
		int matrix_len = i;
		a[i] = malloc(sizeof(int) * array_size);
		printf("%d\t", matrix_len);

		rand_array(a[i], array_size);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1);
		basic_multiply(a[i], a[i], a[i], matrix_len);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);
//		assert(ts1.tv_sec == ts2.tv_sec);
//		printf("%ld\t", ts2.tv_nsec - ts1.tv_nsec);
		printf("%ld\t", ts2.tv_sec - ts1.tv_sec);

		rand_array(a[i], array_size);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1);
		multiply_recursive(a[i], a[i], a[i], matrix_len);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);
//		assert(ts1.tv_sec == ts2.tv_sec);
//		printf("%ld\t", ts2.tv_nsec - ts1.tv_nsec);
		printf("%ld\t", ts2.tv_sec - ts1.tv_sec);

		rand_array(a[i], array_size);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1);
		strassen(a[i], a[i], a[i], matrix_len);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);
//		assert(ts1.tv_sec == ts2.tv_sec);
//		printf("%ld\n", ts2.tv_nsec - ts1.tv_nsec);
		printf("%ld\n", ts2.tv_sec - ts1.tv_sec);

		free(a[i]);
	}
}
void test_matrix(void)
{
	int a[] = {
	        1, 2, 3, 4,
	        2, 2, 3, 4,
	        3, 2, 3, 4,
	        4, 2, 3, 4
	};
	strassen(a, a, a, 4);
	for(int i = 0; i < 16; i++) {
		printf("a[%d] is %d", i, a[i]);
		if(i % 4 == 3) {
			printf("\n");
		}
	}
}
void rand_array(int *a, int size)
{
	time_t t;
	srand(time(&t));
	for(int i = 0; i < size; ++i) {
		a[i] = rand();
	}
}
