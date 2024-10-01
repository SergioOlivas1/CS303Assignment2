#pragma once

class LinkedList
{
private:
	//Node structure
	struct Node {
		int data;
		Node* next;
		
		//Create a new node
		Node(const int value, Node* next_ptr = nullptr) : data(value), next(nullptr) {}
	};

	Node* head; //Pointer to the head of the list
	Node* tail; //Pointer to the end of the list;
	size_t num_items;

public:
	//Member functions
	void push_front(const int& value);
	void push_back(const int& value);
	void pop_front();
	int front();
	int back();
	bool empty();
	void insert(size_t index, const int& value);
	bool remove(size_t index);
	size_t find(const int& item);
	void print();

};

