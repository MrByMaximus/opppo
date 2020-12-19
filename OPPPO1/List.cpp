#include "List.h"
#include <functional>

using namespace std;

List::~List() {
	Node* k = top;
	Node* tmp;

	for (int i = 0; i < sizeList; i++) {
		tmp = k;
		k = k->link;
		delete tmp->figure;
		delete tmp;
	}
}

void List::push(Figures* object) {
	Node* ptr = new Node;
	ptr->link = top;
	ptr->figure = object;
	top = ptr;
	if (sizeList == 0)
		last = ptr;

	last->link = top;
	sizeList++;
}

Node* List::operator[](const int index) {
	Node* ptr = top;
	for (int i = 0; i !=index; i++, ptr = ptr->link) {	
	}

	return ptr;
}

int List::size() {
	return sizeList;
}

void List::deleteFigure(function<bool(Node)> func) {
	Node* ptr = top;
	Node* ptr2 = top;
	Node* tmp;

	int teampSize = sizeList;
	for (int i = 0; i < sizeList; i++) {
		if (func(*ptr)) {
			if (ptr == top) {
				tmp = ptr->link;
				top = tmp;
				delete ptr->figure;
				delete ptr;
				ptr = top;
				teampSize--;
			}
			else {
				ptr2->link = ptr->link;
				delete ptr->figure;
				delete ptr;
				ptr = ptr2->link;
				teampSize--;
			}
		}
		else {
			ptr2 = ptr;
			ptr = ptr->link;
		}
	}
	sizeList = teampSize;
}

void List::sort(function<bool(Node, Node)> func) {
	Node* ptr = top;
	Node* ptr2 = top;
	for (int i = 0; i < sizeList; i++, ptr = ptr->link) {
		for (int j = 0; j < sizeList; j++, ptr2 = ptr2->link)
			if (func(*ptr, *ptr2))
				swap(ptr->figure, ptr2->figure);
	}
}