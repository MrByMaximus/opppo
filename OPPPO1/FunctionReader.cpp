#include "FunctionReader.h"
#include "Node.h"

#include <cmath>
#include <regex>
#include <sstream>
#include <functional>

using namespace std;

FunctionReader::FunctionReader(string strTeamp, List* listTeamp) {
	str = strTeamp;
	list = listTeamp;
}

void FunctionReader::startFunction() {
	checkFunction();
}

void FunctionReader::sort() {
	list->sort([](Node node1, Node node2) {return node1.figure->getName() < node2.figure->getName(); });
}

void FunctionReader::deleteFigure(string params) {
	if(params=="Ball")
		list->deleteFigure([](Node node) {return node.figure->getClass() == "Ball"; });
	if (params == "Pyramid")
		list->deleteFigure([](Node node) {return node.figure->getClass() == "Pyramid"; });
	if (params == "Parallelepiped")
		list->deleteFigure([](Node node) {return node.figure->getClass() == "Parallelepiped"; });
}

bool FunctionReader::checkFunction() {
	cmatch result;
	regex regular("((Delete (?:Ball|Parallelepiped|Pyramid))|(Sort))$");
	if (regex_match(str.c_str(), result, regular)) {
		istringstream stream(result[1].str());
		string function;
		string params;
		stream >> function;
		stream >> params;

		if (function == "Sort")
			sort();

		if (function == "Delete")
			deleteFigure(params);
	}
	else
		return false;
}