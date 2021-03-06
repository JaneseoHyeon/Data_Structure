#pragma once
#include <cstdlib>
#include <cstdio>

const int MAX_STACK_SIZE = 20;
class Stack {
	int top; //요소의 개수
	char data[MAX_STACK_SIZE];
public:
	Stack() { top = -1; }
	~Stack() {}

	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }
	void push(int item) {
		if (isFull()) {
			printf("overflow");
			exit(1);
		}
		data[++top] = item;
	}
	int pop() {
		if (isEmpty()) {
			printf("underflow");
			exit(1);
		}
		return data[top--];
	}
	int peek() {
		if (isEmpty()) {
			printf("underflow");
			exit(1);
		}
		return data[top];
	}
};