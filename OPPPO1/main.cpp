#include "List.h"
#include "ErrorCode.h"
#include "Ball.h"
#include "Reader.h"
#include "FunctionReader.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include "vld.h"

using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "rus");
	ifstream in(argv[1]);
	string str;

	List* list = new List();

	while (!in.eof()) {
		getline(in, str);
		Reader reader(str);
		try {
			Figures* obj = reader.get();
			list->push(obj);
		}
		catch (const ErrorCode) {
			FunctionReader temp(str, list);
			temp.startFunction();
		}
	}
	
	for (int i = 0; i < list->size(); i++)
		cout << (*list)[i]->figure;

	cout << "\nКоличество фигур: " << list->size() << "\n";

	delete list;
	return 0;
}