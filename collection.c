#include <stdio.h>
#define Type int

void foreach(void *this, Type type, int size, void (*func)(int*)) {
	if (size == 0) return;
	if (type == sizeof(int))
		func((int*)this);
	foreach(this+type, type, size-1, func);
}

void increment(int *num) {
	*num += 1;
}

#define foreach(array,func) foreach(array, sizeof(array[0]), sizeof(array) / sizeof(array[0]), func)

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
