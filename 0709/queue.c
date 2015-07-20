#include<stdio.h>

int queue[10000];
int front=0, rear=0;

void enqueue(int n) {
	queue[rear]=n;
	rear++;
}

int dequeue() {
	front++;
	return queue[front-1];
}


