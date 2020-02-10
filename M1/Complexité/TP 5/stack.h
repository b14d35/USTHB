struct Stack {
	int capacity;
	int top;
	int* array;
};

struct Stack* createStack(int cap) {
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = cap;
	stack->top = -1;
	stack->array = (int*)malloc(cap * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack) { return (stack->top == stack->capacity - 1); }

int isEmpty(struct Stack* stack) { return stack->top == -1; }

void push(struct Stack* stack, int item) {
	if (isFull(stack)) return;
	stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
	if (isEmpty(stack)) return INT_MIN;
	return stack->array[stack->top--];
}

int show(struct Stack* stack) {
	int i = stack->top;
	for (i; i > -1; i--) printf("%d ", stack->array[i]);
	printf("\n");
}