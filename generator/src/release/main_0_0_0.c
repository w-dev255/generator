#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include ".lib/release/randomize/randomize_0_0_0.h"

#define VERSION 000

/*buffer size*/
#define BUFFERSZ 5000

int main(int argc, char* argv[]) {
	/*arguments order*/
	int ao = 1;

	/*debug status*/
	int debug_status = 0;

	/*supported arguments*/
	const char* male = "male";
	const char* female = "female";
	const char* debug = "-debug";

	/*debug*/
	if (argc >= 1) {
		printf("warning: no arguments provvided.");
		return 1;
	}

	if (strcasecmp(argv[ao], debug) == 0) {
		debug_status = 1;
		if (argc >= 2) {
			ao++;
		} else {
			printf("warning: not enough arguments.\n");
			return 1;
		}
	}

	/*max array members*/
	const int mixed_male_first_name_count = 50;
        const int mixed_female_first_name_count = 50;
	const int mixed_last_name_count = 50;

	/*empty arrays*/
	char** mixed_male_first_name = calloc(mixed_male_first_name_count, sizeof(char*));
	char** mixed_female_first_name = calloc(mixed_female_first_name_count, sizeof(char*));
	char** mixed_last_name = calloc(mixed_last_name_count, sizeof(char*)); 

	if (!mixed_male_first_name | !mixed_female_first_name | !mixed_last_name) {
		printf("warning: it's not possible allocate memory with calloc.\n");
		return 1;
	}

	/*source files*/
	const char* paths = ".assets/values/strings/paths.txt";
	char* mixed_male_first_name_file_path = NULL;
	char* mixed_female_first_name_file_path = NULL;
	char* mixed_last_name_file_path = NULL;

	char **tmp = calloc(3, sizeof(char*));
	if (!tmp) {
		printf("warning: it's not possible allocate memory with calloc.\n");
		return 1;
	}

	/*get paths*/
	int mmfnt = 0;
        int mffnt = 0;
        int mlnt = 0;
        int total_paths = 0;

        int n = 0;
        int nE = 0;
        int new_size = 0;
        char* buffer = malloc(BUFFERSZ);
	FILE* paths_file = fopen(paths, "r");
	if (!paths_file) {
		printf("warning: it's not possible fetch the resources paths.\n");
		return 1;
	}
	while(fgets(buffer, 5000, paths_file) != NULL) {
 		buffer[strcspn(buffer, "\n")] = '\0';
		tmp[n] = strdup(buffer);
		if (!tmp) {
			printf("warning: it's not possible allocate memory with malloc.\n");
			return 1;
		}
		if (n != 2) {
			n++;
			total_paths++;
			continue;
		} else {
			fclose(paths_file);
			break;
		}
	}

	/*open source files*/
	FILE* mixed_male_first_name_file = fopen(tmp[0], "r");
	FILE* mixed_female_first_name_file = fopen(tmp[1], "r");
	FILE* mixed_last_name_file = fopen(tmp[2], "r");

	/*check if there is any invalid pointer*/
	if (!mixed_male_first_name_file | !mixed_female_first_name_file | !mixed_last_name_file) {
		return 1;
	}

	/*load each line fron files and process it*/
	if (!buffer) {
		printf("warning: it's not possible allocate memory with malloc.\n");
		return 1;
	}
	while(fgets(buffer, BUFFERSZ, mixed_male_first_name_file) != NULL) {
		if (n >= mixed_male_first_name_count) {
			nE++;
			new_size = mixed_male_first_name_count + nE;
			mixed_male_first_name = realloc(mixed_male_first_name, new_size * sizeof(char*));
			if (!mixed_male_first_name) {
				printf("warning: it's not possible realloc memory.\n");
				return 1;
			} else {
				for (int i = mixed_male_first_name_count; i < new_size; i++) {
					mixed_male_first_name[i] = NULL;
				}
			}
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		mixed_male_first_name[n] = strdup(buffer);
		if (!mixed_male_first_name[n]) {
			printf("warning: it's not possible allocate memory with malloc.\n");
			return 1;
		}
		n++;
		mmfnt++;
	}
	n = 0;
	nE = 0;
	new_size = 0;
	free(buffer);

	buffer = malloc(BUFFERSZ);
	if (!buffer) {
		printf("warning: it's not possible allocate memory with malloc.\n");
		return 1;
	}
	while (fgets(buffer, BUFFERSZ, mixed_female_first_name_file) != NULL) {
		if (n >= mixed_female_first_name_count) {
			nE++;
			new_size = mixed_female_first_name_count + nE;
			mixed_female_first_name = realloc(mixed_female_first_name, new_size * sizeof(char*));
			if (!mixed_female_first_name) {
				printf("warning: memory cannot be reallocated.\n");
					return 1;
				} else {
					for (int i = mixed_female_first_name_count; i < new_size; i++) {
						mixed_female_first_name[i] = NULL;
					}
				}
			}
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		mixed_female_first_name[n] = strdup(buffer);
		if (!mixed_female_first_name[n]) {
			printf("warning: it's not possible allocate memory with malloc.\n");
			return 1;
		}
		n++;
		mffnt++;
	}
	n = 0;
	nE = 0;
	new_size = 0;
	free(buffer);

	buffer = malloc(BUFFERSZ);
	if (!buffer) {
		printf("warning: it's not possible allocate memory with malloc.\n");
		return 1;
	}
	while (fgets(buffer, 5000, mixed_last_name_file) != NULL) {
		if (n >= mixed_last_name_count) {
			nE++;
			new_size = mixed_last_name_count + nE;
			mixed_last_name = realloc(mixed_last_name, new_size * sizeof(char*));
			if (!mixed_last_name) {
				printf("warning: memory cannot be reallocated.\n");
				return 1;
			} else {
				for (int i = mixed_last_name_count; i < new_size; i++) {
					mixed_last_name[i] = NULL;
				}
			}
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		mixed_last_name[n] = strdup(buffer);
		if (!mixed_last_name[n]) {
			printf("warning: it's not possible allocate memory.\n");
			return 1;
		}
		n++;
		mlnt++;
	}
	n = 0;
	nE = 0;
	new_size = 0;
	free(buffer);

	if (strcasecmp(argv[ao], male) == 0) {
		int name = random_index(mixed_male_first_name, (int)mmfnt);
		sleep(1);

		int last_name = random_index(mixed_last_name, mlnt);
		sleep(1);

		printf("%s %s\n", mixed_male_first_name[name], mixed_last_name[last_name]);
	} else if (strcasecmp(argv[ao], female) == 0) {
		int name = random_index(mixed_female_first_name, mffnt);
		sleep(1);

		int last_name = random_index(mixed_last_name, mlnt);
		sleep(1);

		printf("%s %s\n", mixed_female_first_name[name], mixed_last_name[last_name]);
	} else {
		printf("warning: invalid argument.\n");
	}

	/*clear arrays*/
	for (int i = 0; i < mmfnt; i++) {
		free(mixed_male_first_name[i]);
	}

	for (int i = 0; i < mffnt; i++) {
		free(mixed_female_first_name[i]);
	}

	for (int i = 0; i < mlnt; i++) {
		free(mixed_last_name[i]);
	}

	for (int i = 0; i < 2; i++) {
		free(tmp[i]);
	}

	free(mixed_male_first_name);
	free(mixed_female_first_name);
	free(mixed_last_name);
	free(tmp);

	printf("version: %d\nmixed_male_first_name: %d\nmixed_female_first_name: %d\nmixed_last_name: %d\n", VERSION, mmfnt, mffnt, mlnt);
	return 0;
}

