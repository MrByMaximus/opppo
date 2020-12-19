#pragma once
#include "Figures.h"

using namespace std;

class Parallelepiped : public Figures {
private:
	int* rib = new int[3];
	string color;
public:
	~Parallelepiped()override;
	Parallelepiped(int,int,int,float,string&,string&);
	void getData(ostream&);
	string getClass();
};