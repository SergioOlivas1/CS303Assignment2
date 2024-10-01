#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Stack
{
private:
	vector<int> values;

public:
	void push(int item);
	void pop();
	int peek();
	bool isEmpty();
	double average();
};
