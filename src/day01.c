#include "day01.h"

#include <assert.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// caller must close
FILE *get_input_handle(const char *path) {
	FILE *input_file = fopen(path, "r");
	assert(input_file && "couldnt open input file");
	return input_file;
}

int input_stoi(const char *s) {
	if (!strncmp(s, "zero", 4)) {
			return 0;
	} else if (!strncmp(s, "one",  3)) {
		return 1;
	} else if (!strncmp(s, "two",  3)){
 		return 2;
	} else if (!strncmp(s, "three", 5)) {
 		return 3;
	} else if (!strncmp(s, "four", 4)) {
		return 4;
	} else if (!strncmp(s, "five", 4)) {
 		return 5;
	} else if (!strncmp(s, "six",  3)) {
 		return 6;
	} else if (!strncmp(s, "seven", 5)) {
 		return 7;
	} else if (!strncmp(s, "eight", 5)) {
 		return 8;
	} else if (!strncmp(s, "nine", 4)) {
 		return 9;
	}
	return 0;
}

void day1part1() {
	FILE *input_file = get_input_handle("../res/input01");

	regex_t regex;
	char *regex_str = "^(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)|(zero)|[0-9]";
	int regex_compiled = regcomp(&regex, regex_str, 0);
	assert(regex_compiled == 0 && "failed to compile regex");

	char *input_line;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&input_line, &len, input_file)) != -1) {

		printf("Read: %s\n", input_line);

		size_t nmatches = 16;
		regmatch_t *pmatch = (regmatch_t*)malloc(sizeof(regmatch_t) * nmatches);
		int reg_returned = regexec(&regex, input_line, nmatches, pmatch, 0);
		if (reg_returned == 0) { 
			printf("Found: %ld\n", nmatches);
		} else if (reg_returned == REG_NOMATCH) {
			printf("no match\n");
		} else {
			// regex errored
		}

		free(pmatch);
		break;
	}


	free(input_line);
	regfree(&regex);
	fclose(input_file);
}
