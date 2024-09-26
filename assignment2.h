#pragma once

class LinkedList
{
private:
	//Node structure
	struct Node {
		int head, tail, num_items; 
		Node* next;
		//Create a new node
		Node(int value) : num_items(value), next(nullptr) {}
	};

	Node* head; //Pointer to the head of the list

public:
	//Member functions
	void push_front();
	void push_back();
	void pop_front();
	void front();
	void back();
	void empty();
	void insert(size_t index, const Item_Type& item);
	bool remove(size_t index);
	size_t find(const Item_Type& item);



};

