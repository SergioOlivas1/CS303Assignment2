/*Sergio Olivas Assignment 2*/
#include "stack.h"

int main() {
	//create stack object
	Stack stack;
	//Check if empty
	if (stack.isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else
		cout << "Stack is not empty" << endl;
	//Add numbers into the stack
	stack.push(1);
	stack.push(2);
	stack.push(3);
	cout << "Added numbers 1, 2, 3 to the stack" << endl;
	//remove integer
	stack.pop();
	cout << "Removed the top number from the stack" << endl;
	//Check the top number
	cout << "The top number is " << stack.peek() << endl;
	//Find the average 
	cout << "Average of the stack is " << stack.average() << endl;
	return 0;
}

void Stack::push(int num)
{
	values.push_back(num);
}

void Stack::pop()
{
	if (isEmpty()) {
		throw underflow_error("Stack is empty");
	}
	values.pop_back();
}

int Stack::peek()
{
	if (isEmpty()) {
		throw underflow_error("Stack is empty");
	}
	return values.back();
}

bool Stack::isEmpty()
{
	return values.empty();
}

double Stack::average()
{
	if (isEmpty()) {
		throw underflow_error("Stack is empty");
	}
	double sum = 0;
	for (int item : values) {
		sum += item;
	}
	return sum / values.size();
}

