#pragma once
#include "Figures.h"
#include <string>

using namespace std;

class Reader {
private:
	string tmp;
	
	Figures* ObjBall(const string&, const string&, const string&, const string&);
	Figures* ObjParalelepiped(const string&, const string&, const string&, const string&, const string&, const string&);
	
public:
	Reader();
	Reader(string);
	Figures* get();

protected:
	int stringToInt(const string& intString);
	float stringToFloat(const string floatString);
	void isOwner(const string name);
	void isColor(const string name);
};