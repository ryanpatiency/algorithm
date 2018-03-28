#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define UP 100000



int main()
{
	printf("N orig opt\n");
    for(int i = 1; i < UP; i += 1000) {
	
		printf("%d ", i);
		
		char *str = malloc(i+1);
		for(int j=0; j<i; j++){
			str[j] = 'a';
		}
		str[i] = '\0';
		
		clock_t t = clock();
        for(int j = 0; j < strlen(str); j++) {
			int x = i;
			x+=1;
		}
		t = clock()-t;
		
		printf("%f ", t/(double)CLOCKS_PER_SEC);
		
		t = clock();
        for(int j = 0; j < i; j++) {
			int x = i;
			x+=1;
		}
		t = clock()-t;
		
		printf("%f\n", t/(double)CLOCKS_PER_SEC);
		
		free(str);
	}
}
