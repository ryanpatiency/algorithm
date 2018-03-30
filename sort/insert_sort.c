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

