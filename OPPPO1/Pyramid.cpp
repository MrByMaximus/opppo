#include "Pyramid.h"
#include "sstream"
#include "iostream"

using namespace std;

Pyramid::~Pyramid() {
}

Pyramid::Pyramid(int STeamp, int HTemp, float density, string owner, string colorTemp) {
	s = STeamp;
	h = HTemp;
	color = colorTemp;
	Figures::setDensity(density);
	Figures::setName(owner);
	Figures::setColor(colorTemp);
}

void Pyramid::getData(ostream& stream) {
	stream << "\n";
	if (color != "")
		stream << color << " ";
	stream << "Пирамида - Площадь основания: " << s << "; Высота: " << h;
	Figures::getDataFigure(stream);
}

string Pyramid::getClass() {
	return "Pyramid";
}