#include "Figures.h"
#include "iostream"
#include <iomanip>

using namespace std;

Figures::~Figures() {
}

void Figures::setName(string& teampName) {
	name = teampName;
}

void Figures::setDensity(float teampDensity) {
	density = teampDensity;
}

void Figures::setColor(string& teampColor) {
	color = teampColor;
}

void Figures::getDataFigure(ostream& stream) {
	stream << "; Плотность: " << density << "; Владелец: " << name;
}

string Figures::getName() {
	return name;
}

ostream& operator<<(ostream& stream, Figures* figure) {
	figure->getData(stream);
	return stream;
}