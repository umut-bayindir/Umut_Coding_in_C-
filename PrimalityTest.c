#include <stdlib.h>
#include <math.h>
#include "PrimalityTest.h"

//function to check if number is prime number
int f_is_prime(long int num)
 {
	//declare return variable 
	int primality_value = 1;
	if (num <= 1) {
	  primality_value = 0;
	} else if (num <= 3) {
	  primality_value = 1;
	}

	if (num % 2 == 0) {
		primality_value = 0;
	}
	//checking if divisible by divisor_number
	int divisor_number;
	for (divisor_number = 3; divisor_number <= sqrt(num); divisor_number += 2) {
		if (num % divisor_number == 0) {
		  int primality_value = 0;
		  break;
        }
    }


	return primality_value;
	
}

//get next prime number
long int f_get_next_prime(long int num)
 {
	if (num < 2) {
        num = 2; 
	} else {
	  if (num % 2 == 0) {
        num += 1;
	  } else {
        num += 2;
	  }
	//incrementing to next prime value
	  while (f_is_prime(num == 0)) {
        num += 2;
	  }
	}

	return num;
}
