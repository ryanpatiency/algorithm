#include <stdlib.h>
#include <string.h>

void __merge_sort(int a[], int new_a[], int start, int end)
{
	/*
	 *  assume input data: 2 3 1 4
	 *
	 *  Conquer: if the size ==1 (start==end) return
	 *
	 *  Divide: divide the input data into two part, each contain two data
	 *      we need the index of end, mid, and the first end is mid, the second
	 *      start is mid+1
	 *
	 *  Conbine:
	 *      i = start, j = mid+1, k = start;
	 *      while i<=mid && j<=end
	 *      	copy the bigger one in to new_a[k]
	 *          k++ and the bigger one ++
	 *      while k is <= end,
	 *          copy the rest one in to new_a[k]
	 *          k++
	 *		for i = start to end
	 *			copy new_a[i] to a[i];
	 *
	 */
	if(start == end)
		return;
	int mid = (start + end) / 2; // == 0 + 3 /2 = 1
	__merge_sort(a, new_a, start, mid);
	__merge_sort(a, new_a, mid + 1, end);
	int i = start;
	int j = mid + 1;
	int k = start;
	while(i <= mid && j <= end) {
		if(a[i] < a[j]) {
			new_a[k++] = a[i++];
		} else {
			new_a[k++] = a[j++];
		}
	}
	int *tmp = i > mid ? a + j : a + i;
	while(k <= end) {
		new_a[k++] = *tmp++;
	}
	for(i = start; i <= end; i++) {
		a[i] = new_a[i];
	}
}

void merge_sort(int *a, int size)
{
	/*
	 *  to call __merge_sort, I need a new_a which the size is the same as a,
	 *  and free it after,
	 *  and i need to get start and end of a by size
	 */
	int *new_a = malloc(sizeof(int) * size);
	__merge_sort(a, new_a, 0, size - 1);
	free(new_a);
}

