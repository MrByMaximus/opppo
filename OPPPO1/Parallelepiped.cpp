#include "Parallelepiped.h"
#include "sstream"
#include "iostream"

#include <regex>

using namespace std;

Parallelepiped::~Parallelepiped() {
	delete[] rib;
}

Parallelepiped::Parallelepiped(int r1, int r2, int r3, float density, string& owner, string& colorTemp) {
	rib[0] = r1;
	rib[1] = r2;
	rib[2] = r3;
	color = colorTemp;
	Figures::setDensity(density);
	Figures::setName(owner);
	Figures::setColor(colorTemp);
}

void Parallelepiped::getData(ostream& stream) {
	stream << "\n";
	if (color != "")
		stream << color << " ";
	stream << "Параллелепипед - Первое ребро: " << rib[0] << "; Второе ребро: " << rib[1] << "; Третье ребро: " << rib[2];
	Figures::getDataFigure(stream);
}

string Parallelepiped::getClass() {
	return "Parallelepiped";
}