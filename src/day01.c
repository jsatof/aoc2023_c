#include "day01.h"

#include <assert.h>
#include <regex.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(arr) (sizeof((arr)) / sizeof((arr)[0]))

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

void run_regex(regex_t *regex, regmatch_t *pmatch, char *input, size_t input_len, char **output) {
	regoff_t off, len;
	char *str = input;
	printf("Input: %s\n", input);
	for (size_t i = 0; i < LEN(pmatch); ++i) {
		if (regexec(regex, input, LEN(pmatch), pmatch, 0) != 0) {
			printf("no match\n");
			break;
		}

		off = pmatch[0].rm_so + (str - input);
		len = pmatch[0].rm_eo - pmatch[0].rm_so;

		printf("#%zu:\n", i);
		printf("offset = %jd; length %jd\n", (intmax_t) off, (intmax_t) len);
		printf("substring = \"%.*s\"\n", len, str + pmatch[0].rm_so);
		sprintf(output[i], "%.*s", len, str + pmatch[0].rm_so);

		str += pmatch[0].rm_eo;

		break;
	}
}

void print_string_array(char **array, size_t length) {
	printf("[");
	for (size_t i = 0; i < length; ++i) {
		if (i > 0) {
			printf(", ");
		}
		printf("\"%s\"", array[i]);
	}
	printf("]\n");
}

void day1part1() {
	FILE *input_file = get_input_handle("../res/input01");

	char *matches[16];
	size_t match_groups = 16;
	for (size_t i = 0; i < match_groups; ++i) {
		// each match is no more than 5 characters + 1 for null byte
		matches[i] = (char*)malloc(6 * sizeof(char));
	}


	regex_t regex;
	char *regex_str = "(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)|(zero)|[0-9]";
	int regex_compiled = regcomp(&regex, regex_str, REG_EXTENDED);
	assert(regex_compiled == 0 && "failed to compile regex");

	regmatch_t pmatch[16]; // setting to 16 to cover each of the regex groups ive declared

	char *input_line;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&input_line, &len, input_file)) != -1) {
		run_regex(&regex, &pmatch, input_line, len, matches);

		print_string_array(matches, match_groups);

		break;
	}


	for (size_t i = 0; i < match_groups; ++i) {
		free(matches[i]);
	}
	free(input_line);
	regfree(&regex);
	fclose(input_file);
}
