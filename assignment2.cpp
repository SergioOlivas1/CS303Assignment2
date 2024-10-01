/*Sergio Olivas Assignment 2
CS303 */
#include "assignment2.h"
#include <iostream>

using namespace std;

void LinkedList::push_front(const int& value)
{
	Node* new_node = new Node(value, head);
	head = new_node;
	if (tail == nullptr) {
		tail = new_node;
	}
	++num_items;
}

void LinkedList::push_back(const int& value)
{
	Node* new_node = new Node(value);
	if (tail != nullptr) {
		tail->next = new_node;
	}
	else {
		head = new_node;
	}
	tail = new_node;
	++num_items;
}

void LinkedList::pop_front()
{
	if (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
		--num_items;
		if (head == nullptr) {
			tail = nullptr;
		}
	}
}

int LinkedList::front()
{
	if (head != nullptr) {
		return head->data;
	}
	throw std::out_of_range("List is empty");
}

int LinkedList::back()
{
	if (tail != nullptr) {
		return tail->data;
	}
	throw std::out_of_range("List is empty");
}

bool LinkedList::empty()
{
	return num_items == 0;
}

void LinkedList::insert(size_t index, const int& value)
{
	if (index > num_items) {
		throw std::out_of_range("Index out of range");
	}
	if (index == 0) {
		push_front(value);
	}
	else if (index == num_items) {
		push_back(value);
	}
	else {
		Node* prev = head;
		for (size_t i = 0; i < index - 1; ++i) {
			prev = prev->next;
		}
		Node* new_node = new Node(value, prev->next);
		prev->next = new_node;
		++num_items;
	}

}

bool LinkedList::remove(size_t index)
{
	if (index >= num_items) {
		return false;
	}
	if (index == 0) {
		pop_front();
		return true;
	}
	else {
		Node* prev = head;
		for (size_t i = 0; i < index - 1; i++) {
			prev = prev->next;
		}
		Node* target = prev->next;
		prev->next = target->next;
		if (target == tail) {
			tail = prev;
		}
		delete target;
		--num_items;
		return true;
	}
}

size_t LinkedList::find(const int& item)
{
	Node* current = head;
	size_t index = 0;
	while (current != nullptr) {
		if (current->data == item) {
			return index;
		}
		current = current->next;
		++index;
	}
	return -1;
}

void LinkedList::print()
{
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " -> ";
		current = current->next;
	}
	cout << "nullptr\n";
}
