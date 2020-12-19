#pragma once
#include "Figures.h"
#include <fstream>

using namespace std;

class Ball : public Figures {
private:
	int radius;
	string color;
public:
	~Ball();
	Ball(int,float,string&,string&);
	void getData(ostream&);
	string getClass();
};