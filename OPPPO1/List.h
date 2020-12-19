#pragma once
#include "string"
#include "Figures.h"
#include "Node.h"

#include <functional>

using namespace std;

class List {
private:
	Node* top, * last;
	int sizeList = 0;

public:
	~List();
	void push(Figures* object);
	Node* operator [](const int index);
	int size();
	void deleteFigure(function<bool(Node)> pred);
	void sort(function<bool(Node, Node)> pred);
};