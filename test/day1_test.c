#include <criterion/criterion.h>

#include <day01.h>

#include <stdio.h>

Test(day01, file_load) {
	FILE *input = fopen("../../res/input01", "r");
	cr_assert(input);
	fclose(input);
}

Test(day01, input_stoi) {
	cr_assert(input_stoi("zero") == 0);
	cr_assert(input_stoi("one") == 1);
	cr_assert(input_stoi("two") == 2);
	cr_assert(input_stoi("three") == 3);
	cr_assert(input_stoi("four") == 4);
	cr_assert(input_stoi("five") == 5);
	cr_assert(input_stoi("six") == 6);
	cr_assert(input_stoi("seven") == 7);
	cr_assert(input_stoi("eight") == 8);
	cr_assert(input_stoi("nine") == 9);
}
