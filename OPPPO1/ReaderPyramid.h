#pragma once
#include "Figures.h"
#include "Reader.h"

using namespace std;

class ReaderPyramid:public Reader {
public:
	ReaderPyramid(string);
	Figures* get();
private:
	string tmp;
	Figures* ObjPyramid(const string&, const string&, const string&, const string&, const string&);
};