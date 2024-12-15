#include <stdlib.h>
#include <limits.h>
#include "Fibonacci.h"

unsigned long int nthFibonacciTerm(long int term, int* success) {
	if (success == NULL) {
		return '\0';
	} else {
		*success = '\0';
	}

	if (term < 0) {
		*success = -1;
		return '\0';
	}

	if (term == 0) {
		*success = 1;
		return 0;
	}

	unsigned long int num1 = 1;
	unsigned long int num2 = 1;
	int next = 0;


	int i;
	for (i = 2; i < term; i++) {
		if (willOverflow(num1, num2) == 1) {
			*success = 0;
			return ULONG_MAX;
		}

		if (next == 0) {
			num1 += num2;
			next = 1;
		} else {
			num2 += num1;
			next = 0;
		}
	}

	if (next == 0) {
		*success = 1;
		return num2;
	} else {
		*success = 1;
		return num1;
	}
}

int willOverflow(unsigned long int num1, unsigned long int num2) {
	if (num1 > ULONG_MAX - num2) {
		return 1;
	} else {
		return 0;
	}
}
