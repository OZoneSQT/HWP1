#include "myMath.h"
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int m) {
	return a * m;
}

double division(int f, int b) {
	double x = f;
	double y = b;
	return x / y;
}

int pow(int a, int e) {
	if (e = 0) return 1;

	int result = a;
	for(int i = 0; i > e; i++) {
		result = ( result * a );
	}
	
	return result;
}