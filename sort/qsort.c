/*
 * 	ex:
 *		idx: 	0 	1
 *		value:	9	11
 *
 * 	Conquer:
 * 		when size <= 1, return, and it is sorted
 *	Divide:
 *		three part:
 *		by head, smallertail, largertail, tail
 *
 *		1. head <-> lesstail : less than pivot,
 *		2. lesstail+1 <-> bigtail : larger than pivot
 *		3. bigtail+1 <-> tail - 1 : unsort
 *
 *		init value: no 1, 2, all 3
 *		there is no element bigger than pivot: bigtail = head-1
 *		there is no element less or equal than pivot: lesstail = head-1
 *
 *		increase bigtail,
 *		if bigtail is bigger than pivot, do nothing
 *		else change bighead with bigtail, bighead is the element next to
 *		lesstail. and increase next tail
 *
 *		until bigtail + 1 == tail, => we sort every thing
 *
 *		change tail to bighead, and
 *		qsort head to lesstial
 *		qsort bighead+1 to tail
 */
void qsort(int *a, int head, int tail)
{
	if(head >= tail) {
		return;
	}
	int lesstail = head - 1;
	int bigtail = head - 1;
	int pivot = a[tail];
	do {
		bigtail++;
		if(a[bigtail] <= pivot) {
			lesstail++;
			int bigheadvalue = a[lesstail];
			a[lesstail] = a[bigtail];
			a[bigtail] = bigheadvalue;
		}
	} while(bigtail < tail - 1);

	int bigheadvalue = a[lesstail + 1];
	a[lesstail + 1] = pivot;
	a[tail] = bigheadvalue;
	qsort(a, head, lesstail);
	qsort(a, lesstail + 2, tail);
}
