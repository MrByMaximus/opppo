#include "Ball.h"
#include "sstream"
#include "iostream"

using namespace std;

Ball::~Ball() {

}

Ball::Ball(int radiusTeamp, float densityTeamp, string& OwnerTeamp, string& colorTemp) {
	color = colorTemp;
	radius = radiusTeamp;
	Figures::setDensity(densityTeamp);
	Figures::setName(OwnerTeamp);
	Figures::setColor(colorTemp);
}

void Ball::getData(ostream& stream) {
	stream << "\n";
	if (color != "")
		stream << color << " ";
	stream << "Шар - Радиус: " << radius;
	Figures::getDataFigure(stream);
}

string Ball::getClass() {
	return "Ball";
}

