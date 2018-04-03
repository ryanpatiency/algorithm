struct heap {
	int heapsize; // heap size
	int arraysize; // array size
	int *data;
};

#define left(i) (2*(i))
#define right(i) (2*(i)+1)
#define parent(i) (2/(i))

void swap(struct heap *mheap, int i, int j)
{
	int tmp = mheap->data[i];
	mheap->data[i] = mheap->data[j];
	mheap->data[j] = tmp;
}

void max_heapify(struct heap *mheap, int i)
{
	/*
	 * 	if biggest child(i) bigger then i
	 * 		swap and heapify it
	 *	bigidx = itself,
	 *	if left exist and bigger than the biggest,
	 *		bigidx = left
	 *	if right exist and bigget than the biggest
	 *		biggest = right
	 *	if biggest != itself
	 *		swap with biggest and heapify biggest
	 */
	int maxidx = i;
	if(left(i) <= mheap->heapsize
	        && mheap->data[left(i)] > mheap->data[maxidx]) {
		maxidx = left(i);
	}
	if(right(i) <= mheap->heapsize
	        && mheap->data[right(i)] > mheap->data[maxidx]) {
		maxidx = right(i);
	}
	if(maxidx != i) {
		swap(mheap, maxidx, i);
		max_heapify(mheap, maxidx);
	}
}

void build_maxheap(struct heap *mheap)
{
	/*
	 * 	maintain the heap by let the n/2 to 1's node to be a max heap
	 */
	mheap->heapsize = mheap->arraysize - 1;
	for(int i = mheap->heapsize / 2; i > 0; i--) {
		max_heapify(mheap, i);
	}
}
void min_heapify(struct heap *mheap, int i)
{
	/*
	 * 	if biggest child(i) smaller then i
	 * 		swap and heapify it
	 *
	 *
	 *	smallidx = itself,
	 *	if left exist and bigger than the biggest,
	 *		smallidx = left
	 *	if right exist and bigget than the biggest
	 *		biggest = right
	 *	if biggest != itself
	 *		swap with biggest and heapify biggest
	 */
	int minidx = i;
	if(left(i) <= mheap->heapsize
	        && mheap->data[left(i)] < mheap->data[minidx]) {
		minidx = left(i);
	}
	if(right(i) <= mheap->heapsize
	        && mheap->data[right(i)] < mheap->data[minidx]) {
		minidx = right(i);
	}
	if(minidx != i) {
		int tmp = mheap->data[i];
		mheap->data[i] = mheap->data[minidx];
		mheap->data[minidx] = tmp;
		min_heapify(mheap, minidx);
	}
}

void build_minheap(struct heap *mheap)
{
	/*
	 * 	maintain the heap by let the n/2 to 1's node to be a max heap
	 */
	mheap->heapsize = mheap->arraysize;
	for(int i = mheap->heapsize / 2; i > 0; i--) {
		min_heapify(mheap, i);
	}
}
void __heap_sort(struct heap *mheap)
{
	/*
	 *  swap the root of a max heap's head with its tail
	 *  heapify the root, minus heapsize, until heapsize = 1
	 */
	while(mheap->heapsize > 1) {
		int tmp = mheap->data[1];
		mheap->data[1] = mheap->data[mheap->heapsize];
		mheap->data[mheap->heapsize] = tmp;
		mheap->heapsize--;
		max_heapify(mheap, 1);
	}
}

void heap_sort(int *a, int size)
{
	struct heap mheap;
	mheap.arraysize = size;
	mheap.data = a;
	build_maxheap(&mheap);
	__heap_sort(&mheap);
}

/*
 *  priority queue: with these functions:
 *  - build priority queue
 *  - get_max(struct heap *mheap);
 *  - extract_max(struct heap *mheap);
 *  - change_key(struct heap *mheap, int idx, int newvalue);
 *  - insert(struct heap *mheap, int data);
 *
 */
void build_priority_queue(struct heap *mheap, int *data, int size)
{
	mheap->arraysize = size;
	mheap->data = data;
	mheap->heapsize = 0;
}

int get_max(struct heap *mheap)
{
	return mheap->data[1];
}
int extract_max(struct heap *mheap)
{
	int max = get_max(mheap);
	mheap->data[1] = mheap->data[mheap->heapsize];
	mheap->heapsize--;
	max_heapify(mheap, 1);
	return max;

}
void change_key(struct heap *mheap, int idx, int newvalue)
{
	/*
	 * 	change the heap[idx] to its new value, and do the following:
	 *
	 * 	if heap[idx] is bigger than its parent, than swap heap and its parent
	 * 	until it has no parent, idx == 1
	 */
	mheap->data[idx] = newvalue;
	max_heapify(mheap, idx);
	while(idx > 1 && mheap->data[idx] > mheap->data[parent(idx)]) {
		swap(mheap, idx, parent(idx));
		idx = parent(idx);
	}
}
void insert(struct heap *mheap, int data)
{
	mheap->heapsize++;
	mheap->data[mheap->heapsize] = data;
	change_key(mheap, mheap->heapsize, data);
}

