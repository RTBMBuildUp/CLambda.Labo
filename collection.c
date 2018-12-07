#include <stdio.h>

void foreach(int *this, int size, void (*lambda)(int*)) {
	if (size == 0) return;
	lambda(this);
	foreach(this+1, size-1, lambda);
}

void increment(int *num) {
	*num += 1;
}

#define foreach(array,func) foreach(array, sizeof(array) / sizeof(array[0]), func)

int main(void) {
	int array[5];
		
	for (int *array_p = array; array_p != &array[5]; array_p++)
		*array_p = array_p - array;
	
	for (int *array_p = array; array_p != &array[5]; array_p++)
		printf("%d ", *array_p);
	printf("\n");

	foreach(array, increment);
	for (int *array_p = array; array_p != &array[5]; array_p++)
		printf("%d ", *array_p);
	printf("\n");



	return 0;
}
