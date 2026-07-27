#ifndef RANDOMIZE
	#define RANDOMIZE
	#include <stdlib.h>
	#include <time.h>

	int random_index(char** arr, size_t n) {
        	int count = (int)n / sizeof(arr[0]);

	        srand((unsigned)time(NULL));

        	int index = rand() % count;

	        return index;
	}
#endif
