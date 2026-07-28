#ifndef RANDOMIZE
	#define RANDOMIZE
	#include <stdlib.h>
	#include <time.h>

	int random_index(char** arr, int n) {
        	int count = n / sizeof(arr[0]);

	        srand((unsigned)time(NULL));

        	int index = rand() % count;

	        return index;
	}
#endif
