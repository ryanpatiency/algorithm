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

#define SIZE 15

void rand_array(int *a, int size)
{
	time_t t;
	srand(time(&t));
	for(int i = 0; i < size; ++i) {
		a[i] = rand();
	}
}

void analyze(void)
{
	struct timespec ts1, ts2;
	int *a[SIZE];
	printf("input_size\tbasic multiply\trecursive\tstrassen\n");
	for(int i = 0; i < SIZE; i++) {
		a[i] = malloc(sizeof(int) * 1 << i);

		printf("%d\t", 1 << i);

		rand_array(a[i], 1 << i);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1);
		basic_multiply(a[i], a[i], 1 << i);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);
		assert(ts1.tv_sec == ts2.tv_sec);

		printf("%ld\t", ts2.tv_nsec - ts1.tv_nsec);

		rand_array(a[i], 1 << i);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1);
		insert_sort(a[i], 1 << i);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);
		assert(ts1.tv_sec == ts2.tv_sec);

		printf("%ld\n", ts2.tv_nsec - ts1.tv_nsec);

		free(a[i]);
	}
}

int main()
{
	analyze();
}
