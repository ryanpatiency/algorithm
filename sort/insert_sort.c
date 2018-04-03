void insert_sort(int a[], int size)
{
    /*
     *  sort the second to last number j in key
     *      while there is a index in front, and
     *      key is smaller than the index in front,
     *          move the value back, make the index point to the front
     *      put the key in the index + 1;
     */
    for(int j = 1; j < size; j++) {
        int key = a[j];
        int i = j - 1;
        while(i >= 0 && key < a[i]) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}



