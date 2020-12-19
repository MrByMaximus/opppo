#pragma once
#include "List.h"
#include <string>

using namespace std;

class FunctionReader {
public:
	FunctionReader(string,List*);
	void startFunction();
private:
	void sort();
	void deleteFigure(string);
	bool checkFunction();
	string str;
	List* list;
};