/*
 * 	divide into these:
 * 	head - lessend | --- | bigend+1 - end-1
 *
 * 	observe that the bigend will stop at correct location, so must the next of
 * 	lessend, which is bighead
 */

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void __quick_sort(int *a, int head, int end)
{
	if(head >= end) {
		return;
	}
	int pivot = a[end];
	int lessend = head - 1;
	int bigend = head - 1;
	while(bigend < end - 1) {
		bigend++;
		if(a[bigend] <= pivot) {
			// swap with bighead
			int bighead = ++lessend;
			swap(&(a[bighead]), &(a[bigend]));
		}
	}
	int newpivotidx = lessend + 1;
	swap(&(a[end]), &(a[newpivotidx]));
	__quick_sort(a, newpivotidx + 1, end);
	__quick_sort(a, head, newpivotidx - 1);

}
void __quick_sort_end(int *a, int head, int end)
{
	/*
	 * 	use end as pivot, the safe one will be the increase idx
	 * 	for quick sort 2, invariant:
	 * 	the j will always be bigger or equal to the pivot
	 * 	swap the pivot with j after break;
	 */
	if(head >= end) {
		return;
	}
	int i = head - 1;
	int j = end;
	int pivot = a[end];
	while(1) {
		do {
			i++;
		} while(a[i] < pivot);
		do {
			j--;
		} while(j >= head && a[j] >= pivot);
		if(i >= j) {
			break;
		}
		swap(&(a[i]), &(a[j]));
	}
	swap(&(a[end]), &(a[i]));
	__quick_sort_end(a, head, i - 1);
	__quick_sort_end(a, i + 1, end);

}

void __quick_sort_head(int *a, int head, int end)
{
	/*
	 * 	use head as pivot, the safe one will be the increase idx
	 * 	for quick sort 2, invariant:
	 * 	the j will always be bigger or equal to the pivot
	 * 	swap the pivot with j after break;
	 */
	if(head >= end) {
		return;
	}
	int i = head;
	int j = end + 1;
	int pivot = a[head];
	while(1) {
		do {
			i++;
		} while(i <= end && a[i] <= pivot);
		do {
			j--;
		} while(a[j] > pivot);
		if(i >= j) {
			break;
		}
		swap(&(a[i]), &(a[j]));
	}
	swap(&(a[head]), &(a[j]));
	__quick_sort_head(a, head, j - 1);
	__quick_sort_head(a, j + 1, end);

}

void quick_sort(int *a, int size)
{
	__quick_sort(a, 0, size - 1);
}
void quick_sort2(int *a, int size)
{
	__quick_sort_head(a, 0, size - 1);
}
void quick_sort3(int *a, int size)
{
	__quick_sort_end(a, 0, size - 1);
}

