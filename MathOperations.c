#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include "MathOperations.h"
#include "PrimalityTest.h"
#include "PrimeFactorization.h"
#include "Fibonacci.h"
#include "BaseConversion.h"
#include "GreatestCommonDivisor.h"

int main(int argc, char *argv[]) {

	long int i = '\0';
	long int i2 = '\0';
	int baseFrom = '\0';
	int baseTo = '\0';
	char *a = NULL;

	int boolResult = '\0';
	long int longResult = '\0';
	unsigned long int unsignedLResult = '\0';
	char *strResult = NULL;

	int *success = (int*)malloc(sizeof(int));
	*success = '\0';

	int lastDigit = '\0';
	char *ordinalIndicator = NULL;

	while (1) {
		do {
			printf("*** FUN WITH MATH OPERATIONS ***\n");
			printf("Select one of the following options to continue (1 - 6):\n"
					"1.) Primality Test\n"
					"2.) Prime Factorization\n"
					"3.) Nth Term in Fibonacci Sequence\n"
					"4.) Convert a Number from any Base to any Base\n"
					"5.) Greatest Common Divisor\n"
					"6.) Exit\n"
					"Your Selection: ");

			i = retrieveNumericInput(success);
			if (*success != 1 || i > 6 || i < 1) {
				printf("\nError parsing response, please try again.\n");
			}
		} while (*success != 1 || i > 6 || i < 1);

		switch (i) {
			case 1:

				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Primality Test:\n"
							"Enter a Number to Test the Primality Of: ");

					i = retrieveNumericInput(success);
					if (*success != 1) {
						printf("\nError parsing response, please try again.");
					}
				} while (*success != 1);

				if ((boolResult = isPrime(i)) == 0) {
					printf("The Number IS NOT Prime.\n");
				} else if (boolResult == 1) {
					printf("The Number IS Prime.\n");
				}

				*success = '\0';
				boolResult = '\0';
				i = '\0';
				break;

			case 2:
				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Prime Factorization:\n"
							"Enter a Number to take the Prime Factorization Of: ");

					i = retrieveNumericInput(success);
					if (*success != 1) {
						printf("\nError parsing response, please try again.\n");
					} else {

						strResult = primeFactorization(i, success);
						if (strResult == NULL && *success == -1) {
							printf("\nError: Please Enter a Number Greater Than 1.\n");
						}
					}
				} while (*success != 1);

				printf("The Prime Factorization of %ld is:\n"
						"%s\n", i, strResult);

				free(strResult);
				strResult = NULL;

				*success ='\0';
				i = '\0';
				break;

			case 3:
				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Nth Term in Fibonacci Sequence:\n"
							"Enter the Term of the Fibonacci Sequence You Want: ");

					i = retrieveNumericInput(success);
					if (*success != 1) {
						printf("\nError parsing response, please try again.\n");
					} else {

						unsignedLResult = nthFibonacciTerm(i, success);
						if (*success == -1) {
							printf("\nError: Please Enter a Non-Negative Number.\n");
						} else if (*success == 0 && unsignedLResult == ULONG_MAX) {
							printf("\nError: Number Too Big. Please Enter a Smaller Term.\n");
						}
					}
				} while (*success != 1);

				lastDigit = i % 10;
				if (lastDigit == 1) {
					ordinalIndicator = "st";
				} else if (lastDigit == 2) {
					ordinalIndicator = "nd";
				} else if (lastDigit == 3) {
					ordinalIndicator = "rd";
				} else {
					ordinalIndicator = "th";
				}

				printf("The %ld%s Term of the Fibonacci Sequence is:\n"
						"%lu\n", i, ordinalIndicator, unsignedLResult);

				*success = '\0';
				i = '\0';
				unsignedLResult = '\0';
				lastDigit = '\0';
				ordinalIndicator = NULL;
				break;

			case 4:
				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Convert a Number From Any Base to Any Base:\n"
							"Enter the Base to Convert From: ");

					baseFrom = retrieveNumericInput(success);

					if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
					} else if (baseFrom < 2 || baseFrom > 36) {
						printf("\nError: Please Enter a Base Between 2 and 36 (Inclusive)\n");
						*success = 0;
						continue;
					}

					printf("Now Enter the Number to Convert: ");
					a = retrieveAlphanumericInput(success, baseFrom);

					if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
					}

					printf("Now Enter the Base to Convert To: ");
					baseTo = retrieveNumericInput(success);

					if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
					} else if (baseTo < 2 || baseTo > 36) {
						printf("\nError: Please Enter a Base Between 2 and 36 (Inclusive)\n");
						*success = 0;
						continue;
					}

					strResult = baseConversion(baseFrom, baseTo, a, success);
					if (*success != 1) {
						printf("\nError Converting Number. Please try again.\n");
						continue;
					}
				} while (*success != 1);

				printf("The Base %d Number %s in Base %d is:\n"
						"%s\n", baseFrom, a, baseTo, strResult);

				*success = '\0';
				baseFrom = '\0';
				free(a);
				a = NULL;
				baseTo = '\0';
				free(strResult);
				strResult = NULL;
				break;

			case 5:
				do {
					printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
							"Greatest Common Divisor:\n"
							"Enter Number 1: ");

					i =  retrieveNumericInput(success);

					if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
					}

					if (i == 0) {
						printf("\nError: Please Enter a Non-Zero Number.\n");
						continue;
					}

					printf("Now Enter Number 2: ");
					i2 = retrieveNumericInput(success);

					if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
					}

					if (i == 0) {
						printf("\nError: Please Enter a Non-Zero Number.\n");
						continue;
					}

					longResult = gcd(i, i2, success);

					if (*success != 1) {
						printf("\nError getting result. Please try again.\n");
						continue;
					}

				} while (*success != 1);

				printf("The Greatest Common Divisor of %ld and %ld is\n"
						"%ld\n", i, i2, longResult);

				*success = '\0';
				i =  '\0';
				i2 = '\0';
				break;

			case 6:
				free(success);
				success = NULL;
				return 0;
				break;

			default:
				free(success);
				success = NULL;
				return 1;
		}

		printf("\n~~~~~~~~~~~~~~~~~~~~\n\n");
	}	
}

long int retrieveNumericInput(int* success) {
	char *input = NULL;
	char *endptr = NULL;
	retrieveInput(&input, success, 10);

	if (input == NULL || *success != 1) {
		*success = 0;
		return '\0';
	}

	long int ret = '\0';
	errno = 0;
	ret = strtol(input, &endptr, 10);

	free(input);
	input = NULL;

	if (input == endptr) {
		*success = 0;
		return '\0';
	}

	if ((ret == LONG_MAX || ret == LONG_MIN) && errno == ERANGE) {
		*success = 0;
		return '\0';
	}

	*success = 1;
	return ret;
}

char* retrieveAlphanumericInput(int* success, int base) {
	char *input = NULL;
	retrieveInput(&input, success, base);

	if (input == NULL || *success != 1) {
		*success = 0;
		return NULL;
	}

	*success = 1;
	return input;

}

void retrieveInput(char** input, int* success, int base) {
	if (input == NULL || success == NULL || (base < 2 || base > 36)) {
		return;
	} else {
		*success = '\0';
	}

	int size = 128;
	*input = (char*)malloc(sizeof(char) * size);

	(*input)[size - 1] = '\0';

	if (*input == NULL) {
		*success = 0;
		return;
	}

	char* newInput = NULL;
	char maxChar = '\0';
	char c = '\0';
	int len = 0;

	if (base <= 10) {
		maxChar = base + '0' - 1;
	} else {
		maxChar = 'A' + (base - 11);
	}

	do {
		c = getchar();
		c = toupper(c);

		if (isspace(c)) {
			continue;
		}

		if ((!isalnum(c) && (c != '-' && c != '+')) || ((c == '-' || c == '+') && len != 0) || c > maxChar) {
			free(*input);
			*input = NULL;
			*success = 0;
			while ((c = getchar()) != '\n' && c != EOF);
			return;
		}

		if (len == (size - 1)) {
			size += 64;

			newInput = (char*)realloc(*input, sizeof(char) * size);

			if (newInput == NULL) {
				*success = 0;
				free(*input);
				*input = NULL;
				return;
			} else {
				*input = newInput;
				newInput = NULL;
			}
		}

		if (len == 0) {
			if (c != '-' && c != '+') {
				(*input)[len] = '+';
				len++;
			}
		}

		(*input)[len] = c;
		len++;

	} while (c != '\n' && c != EOF);

	if (len == 0) {
		free(*input);
		*input = NULL;
		*success = 0;
		return;
	}

	newInput = (char*)realloc(*input, sizeof(char) * len + 1);

	if (newInput == NULL) {
		*success = 0;
		free(*input);
		*input = NULL;
		return;
	} else {
		*input = newInput;
		newInput = NULL;
	}

	*success = 1;
	(*input)[len] = '\0';
}
