#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define UP 100000



int main()
{
    /*
     * from second to last, sort key in to the sorted array, if the key is 
     * smaller than the front one, copy front one to back and compare to the 
     * one front to front one, until there is no front one, or front one is 
     * smaller than key.
     * 
     * Then, we copy insert the key into this location
     */
    
    int a[] = {5, 4, 3, 2, 1};
    for(int i = 1; i < 5; i++) {
        int key = a[i];
        int j;
        for(j = i - 1; j >= 0 && key < a[j]; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;    
    }
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
