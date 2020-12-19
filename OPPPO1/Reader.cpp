#include "Reader.h"
#include "ErrorCode.h"
#include "Ball.h"
#include "Parallelepiped.h"
#include "Pyramid.h"
#include "ReaderPyramid.h"
#include "ReadOwner.h"
#include "ReadColor.h"

#include <sstream>
#include <cmath>
#include <regex>
#include <string>
#include <sstream>

using namespace std;

int Reader::stringToInt(const string& intString) {
	stringstream stream(intString);
	int Int;
	stream >> Int;
	if (stream.fail() || !stream.eof()) {
		ErrorCode error;
		error.code = 0;
		throw error;
	}

	return Int;
}

float Reader::stringToFloat(const string floatString) {
	stringstream stream(floatString);
	float Float;
	stream >> Float;

	if (stream.fail() || !stream.eof()) {
		ErrorCode error;
		error.code = 0;
		throw error;
	}

	return Float;
}

Reader::Reader() {
}

Reader::Reader(string str) {
	tmp = str;
}

Figures* Reader::get() {
	Figures* object;
	cmatch result;
	regex regularBall("Ball[\\s]+([+-]?[\\d]+)[\\s]+([+-]?[\\d]+\\.[\\d]+)[\\s]+(.*)");
	regex regularParallelepiped("Parallelepiped[\\s]+\\[([+-]?[\\d]+),([+-]?[\\d]+),([+-]?[\\d]+)\\][\\s]+([+-]?[\\d]+\\.[\\d]+)[\\s]+(.*)");
	if (regex_match(tmp.c_str(), result, regularBall)) {
		Figures* figures = ObjBall(result[1].str(), result[2].str(), result[3].str(), result[4].str());
		return figures;
	}
	if (regex_match(tmp.c_str(), result, regularParallelepiped)) {
		Figures* figures = ObjParalelepiped(result[1].str(), result[2].str(), result[3].str(), result[4].str(), result[5].str(), result[6].str());
		return figures;
	}

	ReaderPyramid tmp(tmp);
	try {
		return tmp.get();
	}
	catch (const ErrorCode error) {
		throw error;
	}	
}

void Reader::isOwner(const string name) {
	cmatch result;
	regex regularOwner("([À-ß]|[A-Z])[\\S]+$");
	regex regularOwnerSplit("\"([À-ß]|[A-Z])[\\S]+ (.*)\"$");
	if (regex_match(name.c_str(), result, regularOwner) || regex_match(name.c_str(), result, regularOwnerSplit)) {
	}
	else {
		cmatch result;
		regex regularOwner("([À-ß]|[A-Z])[\\S]+[\\s]+(.*)");
		regex regularOwnerSplit("\"([À-ß]|[A-Z])[\\S]+ .*\"[\\s]+(.*)");

		if (regex_match(name.c_str(), result, regularOwner) || regex_match(name.c_str(), result, regularOwnerSplit)) {
			ErrorCode error;
			error.code = 2;
			error.str = result[2].str();
			throw error;
		}

		ErrorCode error;
		error.code = 0;
		throw error;
	}
}

void Reader::isColor(const string color) {
	cmatch result;
	regex regularColor("([À-ß]|[A-Z])[\\S]+$");
	regex regularColorSplit("\"([À-ß]|[A-Z])[\\S]+ (.*)\"$");
	if (regex_match(color.c_str(), result, regularColor) || regex_match(color.c_str(), result, regularColorSplit)) {
	}
	else {
		cmatch result;
		regex regularColor("([À-ß]|[A-Z])[\\S]+[\\s]+(.*)");
		regex regularColorSplit("\"([À-ß]|[A-Z])[\\S]+ .*\"[\\s]+(.*)");

		if (regex_match(color.c_str(), result, regularColor) || regex_match(color.c_str(), result, regularColorSplit)) {
			ErrorCode error;
			error.code = 2;
			error.str = result[2].str();
			throw error;
		}

		ErrorCode error;
		error.code = 0;
		throw error;
	}
}

Figures* Reader::ObjBall(const string& radiusTeamp, const string& densityTeamp, const string& ownerTeamp, const string& colorTeamp) {
	try {
		isOwner(ownerTeamp);
		if (colorTeamp != "")
			isColor(colorTeamp);
		int radius = stringToInt(radiusTeamp);
		float density = stringToFloat(densityTeamp);
		string owner = ownerTeamp;
		string color = colorTeamp;
		Figures* figure = new Ball(radius, density, owner, color);
		return figure;
	}
	catch (const ErrorCode error) {
		if (error.code == 0)
			throw error;

		if (error.code == 2) {
			int radius = stringToInt(radiusTeamp);
			float density = stringToFloat(densityTeamp);
			stringstream stream(ownerTeamp);
			string owner = readOwner(stream);
			string color = readColor(stream);
			Figures* figure = new Ball(radius, density, owner, color);
			return figure;
		}
	}
}

Figures* Reader::ObjParalelepiped(const string& r1, const string& r2, const string& r3, const string& densityTeamp, const string& ownerTeamp, const string& colorTeamp) {
	try {
		isOwner(ownerTeamp);
		if (colorTeamp != "")
			isColor(colorTeamp);
		int r1Int = stringToInt(r1);
		int r2Int = stringToInt(r2);
		int r3Int = stringToInt(r3);
		float density = stringToFloat(densityTeamp);
		string owner = ownerTeamp;
		string color = colorTeamp;
		Figures* figures = new Parallelepiped(r1Int, r2Int, r3Int, density, owner, color);
		return figures;
	}
	catch (const ErrorCode error) {
		if (error.code == 0)
			throw error;

		if (error.code == 2) {
			int r1Int = stringToInt(r1);
			int r2Int = stringToInt(r2);
			int r3Int = stringToInt(r3);
			float density = stringToFloat(densityTeamp);
			stringstream stream(ownerTeamp);
			string owner = readOwner(stream);
			string color = readColor(stream);
			Figures* figure = new Parallelepiped(r1Int, r2Int, r3Int, density, owner, color);
			return figure;
		}
	}
}