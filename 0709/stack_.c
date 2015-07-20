#include<stdio.h>

int top = -1;
int stack[10];

int pop() {
	top--;
	return stack[top+1];
}

void push(int n) {
	top++;
	stack[top] = n;
}

int main() {

	push(1);
	push(2);
	push(3);

	printf("%d \n", pop());
	printf("%d \n", pop());
	printf("%d \n", pop());

	return 0;
}
