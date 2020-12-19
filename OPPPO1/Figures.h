#pragma once
#include "string"
#include <ostream>

using namespace std;

class Figures {
private:
	float density;
	string name;
	string color;
public:
	virtual ~Figures();
	virtual void getData(ostream&) = 0;
	friend ostream& operator<<(ostream& os, Figures* figure);
	virtual string getClass() = 0;
	void setName(string& teampName);
	void setColor(string& teampColor);
	void setDensity(float teampDensity);
	void getDataFigure(ostream& os);
	string getName();
};