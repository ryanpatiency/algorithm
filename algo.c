#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


void __merge_sort(int a[], int new_a[], int start, int end)
{
    if(start == end)
        return;
    int mid = (start + end) / 2;
    __merge_sort(a, new_a, start, mid);
    __merge_sort(a, new_a, mid + 1, end);

    int tmp = start;
    int i = start;
    int j = mid + 1;
    while(i <= mid && j <= end) {
        new_a[tmp++] = a[i] > a[j] ? a[j++] : a[i++];
    }
    if(i > mid)
        while(j <= end)
            new_a[tmp++] = a[j++];
    if(j > end)
        while(i <= mid)
            new_a[tmp++] = a[i++];
    memcpy(a + start, new_a + start, (1 + end - start) * sizeof(int));
}

void merge_sort(int *a, int size)
{
    /*
     * Divide:
     *  n to n/2
     * Conquer
     *  if n==1, return
     * Combine
     *  for two subarray, put the small element first
     */
    int *new_a = malloc(size * sizeof(int));
    __merge_sort(a, new_a, 0, size - 1);
    free(new_a);
}

void insert_sort(int a[], int size)
{
    for(int i = 1; i < size; i++) {
        int key = a[i];
        int j;
        for(j = i - 1; j >= 0 && key < a[j]; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    merge_sort(a, 5);
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
