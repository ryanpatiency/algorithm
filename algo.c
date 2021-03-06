#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "datastructure/heap.c"
#include "datastructure/list.h"
#include "matrix/basic_multiply.c"
#include "matrix/multiply_recursive.c"
#include "matrix/strassen.c"
#include "matrix/matrix.c"
#include "sort/sort.h"
#include "sort/redix_sort.c"
#include "sort/quick_sort.c"
#include "sort/counting_sort.c"

void test_matrix(void);
void rand_array(int *a, int size);
void analyze_matrix(void);
void analyze_sort(void);
void test_sort(void);
void print_array(int *a, int start, int size);
void test_priority_queue(void);

#define SIZE 20
//#define MAX 90
//#define NOTRAND

int main()
{
    //	test_matrix();
    //	analyze_matrix();
    //    test_sort();
    analyze_sort();
    //	test_priority_queue();
}

void analyze_sort(void)
{
    struct timespec ts1, ts2;
    int *a[SIZE];

    printf("input\tqsort\tredix_sort\n");

    for (int i = 0; i < SIZE; i++) {
        int array_size = 1 << i;
        long diff;
        a[i] = malloc(sizeof(int) * array_size);
        printf("%d\t", array_size);

        rand_array(a[i], array_size);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1);
        quick_sort(a[i], array_size);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);
        diff = 1000000000 * (ts2.tv_sec - ts1.tv_sec) +
               (ts2.tv_nsec - ts1.tv_nsec);
        printf("%ld\t", diff);

        rand_array(a[i], array_size);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1);
        redix_sort(a[i], array_size);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);
        diff = 1000000000 * (ts2.tv_sec - ts1.tv_sec) +
               (ts2.tv_nsec - ts1.tv_nsec);
        printf("%ld\n", diff);

        //        rand_array(a[i], array_size);
        //        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1);
        //        quick_sort3(a[i], array_size);
        //        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);
        //        diff = 1000000000 * (ts2.tv_sec - ts1.tv_sec) +
        //               (ts2.tv_nsec - ts1.tv_nsec);
        //
        //        printf("%ld\n", diff);


        free(a[i]);
    }
}
void analyze_matrix(void)
{
    struct timespec ts1, ts2;
    int *a[SIZE];
    printf("input_size\tbasic multiply\trecursive\tstrassen\n");
    for (int i = 500; i < SIZE; i++) {
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
void test_priority_queue(void)
{
    struct heap mheap;
    int *array = malloc(sizeof(int) * SIZE);
    build_priority_queue(&mheap, array, SIZE);
    insert(&mheap, -7);
    insert(&mheap, -123);
    insert(&mheap, -7);
    char input = 0;
    int data;
    while (input != 'q') {
        printf(
            "\n"
            "chose the following:\n"
            "q: quit\n"
            "i: insert\n"
            "m: getmax\n"
            "e: extract max\n"
            "c: change key\n");
        scanf(" %c", &input);
        switch (input) {
        case 'q':
            break;
        case 'i':
            printf("please give a integer: ");
            scanf("%d", &data);
            insert(&mheap, data);
            break;
        case 'c':
            printf("please give a integer: ");
            scanf("%d", &data);
            change_key(&mheap, 1, data);
            break;
        case 'm':
            printf("the max is %d\n", get_max(&mheap));
            break;
        case 'e':
            printf("the max is %d\n", extract_max(&mheap));
            break;
        default:
            printf("error reading input\n");
            break;
        }
        printf("new array is:\n");
        print_array(array, 1, mheap.heapsize + 1);
    }
    free(array);
}


void test_matrix(void)
{
    int a[] = {1, 2, 3, 4, 2, 2, 3, 4, 3, 2, 3, 4, 4, 2, 3, 4};
    strassen(a, a, a, 4);
    for (int i = 0; i < 16; i++) {
        printf("a[%d] is %d", i, a[i]);
        if (i % 4 == 3) {
            printf("\n");
        }
    }
}
void rand_array(int *a, int size)
{
    time_t t;
    srand(time(&t));
    for (int i = 0; i < size; i++) {
#ifdef MAX
        a[i] = (rand() % (MAX + 1));
#else
        a[i] = rand();
#endif
    }
}
void print_array(int *a, int start, int size)
{
    for (int i = start; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void test_sort(void)
{
    int *a = malloc(SIZE * sizeof(int));
#ifdef NOTRAND
    a[0] = 9;
    a[1] = 3;
    a[2] = 2;
    a[3] = 3;
#else
    rand_array(a, SIZE);
#endif
    print_array(a, 0, SIZE);
    redix_sort(a, SIZE);
    print_array(a, 0, SIZE);
    free(a);
}
