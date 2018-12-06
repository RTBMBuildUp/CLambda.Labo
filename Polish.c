#include <stdio.h>
#include <stdlib.h>

int isoperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '/' || ch == '*') return 1;
	return 0;
}

int otoi(char operator)  {
	switch (operator) {
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
	}
}

int main(void) {
	int (*operation_array[4])(int, int);
	int (**operation_array_p)(int, int) = operation_array;
	int operation_array_length = sizeof(operation_array) / sizeof(operation_array[0]);
	int stack[256] = {0};

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

	int ctoi(char ch) {
		return ch - '0';
	}

	void polish(char *formula, int *result) {
		char ope_stack[256] = {'\0'};
		int num_stack[256];
		
        int *num_stack_p = num_stack;
        char *ope_stack_p = ope_stack;

        while (1) {
            char head = *formula++;
            if (head == '\0') break;
            if (&ope_stack[256] == ope_stack_p) {
                // message
                exit(2);
            }
            if (&num_stack[256] == num_stack_p) {
                // message
                exit(2);
            }
            if (isoperator(head)) {
                *ope_stack_p++ = head;
            } else {
                *num_stack_p++ = ctoi(head);
            }
        }

		while (1) {
			if (--ope_stack_p == &ope_stack[-1]) break;
			char operator = *ope_stack_p;
			*(num_stack_p-2) = operation_array[otoi(operator)](*(num_stack_p-2), *(num_stack_p-1));
			num_stack_p--;
		}
		*result = num_stack[0];
	}
		
	*operation_array_p++ = add;
	*operation_array_p++ = sub;
	*operation_array_p++ = mul;
	*operation_array_p++ = div;

//	operation_array_p = operation_array;
//	for (volatile int (*operation_p)(int, int) = div; operation_p != add + (add - sub); operation_p += (add - sub))
//		*operation_array_p++ = operation_p;

//	for (operation_array_p = operation_array; operation_array_p != &operation_array[operation_array_length]; operation_array_p++)
//		printf("%d\n", operation_array[operation_array_p - &operation_array[0]](4, 2));
	
	int array[256];
	char formula[256];
	int result = 0;
	
	scanf("%255s", formula);
	polish(formula, &result);
	printf("%d\n", result);

	return 0;
}
