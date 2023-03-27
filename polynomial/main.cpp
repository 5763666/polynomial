#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 6

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial multi(polynomial A, polynomial B);

int main() {
	polynomial a, b, c;
	int i;

	a = { 3, {1, 2, 3, 4} };
	b = { 2, {8, 2, 3} };

	c = multi(a, b);
	printf("%d", c.degree);
	for (i = 0; i < c.degree + 1; i++) {
		printf("%d", int(c.coef[i]));
	}
	return 0;
}

polynomial multi(polynomial A, polynomial B) {
	polynomial C;
	int i, j;

	for (i = 0; i < A.degree + B.degree + 1; i++) C.coef[i] = 0;
	C.degree = A.degree + B.degree;

	for (i = 0; i < A.degree + 1; i++)
		for (j = 0; j < B.degree + 1; j++)
			C.coef[i + j] += A.coef[i] * B.coef[j];

	return C;
}