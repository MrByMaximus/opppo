#pragma once
#include "Figures.h"
#include "sstream"
#include "iostream"

using namespace std;

class Pyramid : public Figures {
public:	
	Pyramid(int,int,float,string,string);
	void getData(ostream&);
	string getClass();
private:
	~Pyramid();
	int s;
	int h;
	string color;
};