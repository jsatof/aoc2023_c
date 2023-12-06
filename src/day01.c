#include "day01.h"

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <regex.h>

// caller must close
FILE *get_input_handle(const char *path) {
	FILE *input_file = fopen(path, "r");
	assert(input_file && "couldnt open input file\n");
	return input_file;
}

void day1part1() {
	FILE *input_file = get_input_handle("../res/input01");

	regex_t regex;
	assert(regcomp(&regex, "(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)|(zero)|[0-9]", 0)
			&& "failed to compile regex\n");

	char *input;
	int reg_returned = regexec(&regex, input, 0, NULL, 0);
	if (reg_returned == 0) { 
		// matched
	} else if (reg_returned == REG_NOMATCH) {
		// no match
	} else {
		// regex errored
	}



	

	regfree(&regex);


	fclose(input_file);
}
