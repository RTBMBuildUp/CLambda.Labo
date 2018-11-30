#include <stdio.h>

int main(void) {
	int (*operation_array[4])(int, int);
	int (**array_p)(int, int) = operation_array;

	int add(int f, int s) {
		return f + s;
	}

	int sub(int f, int s) {
		return f - s;
	}

	int mul(int f, int s) {
		return f * s;
	}

	int div(int f, int s) {
		return f / s;
	}

	*array_p++ = add;
	*array_p++ = sub;
	*array_p++ = mul;
	*array_p++ = div;

	array_p =  operation_array;

	for (array_p = operation_array; array_p != &operation_array[4]; array_p++)
		printf("%d\n", operation_array[array_p - operation_array](4, 2));


	return 0;
}
