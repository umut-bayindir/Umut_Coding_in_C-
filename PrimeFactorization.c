#include <stdlib.h>
#include <string.h>
#include "PrimeFactorization.h"
#include "PrimalityTest.h"

char* primeFactorization(long int num, int* success) {
	if (success == NULL) {
		return NULL;
	} else {
		*success = '\0';
	}

	if (num <= 1) {
		*success = -1;
		return NULL;
	}

	char* list = (char*)malloc(sizeof(char));
	list[0] = '\0';

	if (isPrime(num) == 1) {
		*success = 1;
		list = addToList(list, num, 1);
		return list;
	}

	long int base = 2;
	long int power = 0;

	while (num != 1) {
		while (num % base == 0) {
			num /= base;
			power++;
		}

		if (power != 0) {
			list = addToList(list, base, power);

			if (num != 1 && isPrime(num) == 1) {
				list = addToList(list, num, 1);
				break;
			}
			power = 0;
		}
		base = getNextPrime(base);
	}
	*success = 1;
	return list;
}

char* toString(long int num) {
	int len = 1;
	long int newNum = num;

	while (newNum / 10 != 0) {
		newNum /= 10;
		len++;
	}

	char *ret = (char*)malloc(sizeof(char) * len + 1);

	ret[len] = '\0';

	int i;
	for (i = len - 1; i >= 0; i--) {
		ret[i] = ((num % 10) + '0');
		num /= 10;
	}
	return ret;
}

char* addToList(char* list, long int base, long int power) {
	int currentLen = strlen(list);
	char* baseStr = toString(base);
	char* powerStr = toString(power);
	int newLen = currentLen + strlen(baseStr) + strlen(powerStr);

	char* newList;
	if (currentLen == 0) {
		newList = (char*)realloc(list, sizeof(char) * newLen + 2);
		strcat(newList,baseStr);
		strcat(newList, "^");
		strcat(newList, powerStr);
	} else {
		newList = (char*)realloc(list, sizeof(char) * newLen + 5);
		strcat(newList, " * ");
		strcat(newList, baseStr);
		strcat(newList, "^");
		strcat(newList, powerStr);
	}
	free(baseStr);
	free(powerStr);
	baseStr = NULL;
	powerStr = NULL;
	return newList;
}
