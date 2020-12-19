#include "ReaderPyramid.h"
#include "ErrorCode.h"
#include "Pyramid.h"
#include "ReadOwner.h"
#include "ReadColor.h"

#include <cmath>
#include <regex>
#include <string>

using namespace std;

ReaderPyramid::ReaderPyramid(string str) {
	tmp = str;
}

Figures* ReaderPyramid::get() {
	//Figures* object;
	cmatch result;
	regex regularPyramid("Pyramid[\\s]+([+-]?[\\d]+)[\\s]+([+-]?[\\d]+)[\\s]+([+-]?[\\d]+\.[\\d])[\\s]+(.*)");

	if (regex_match(tmp.c_str(), result, regularPyramid)) {
		Figures* figures = ObjPyramid(result[1].str(), result[2].str(), result[3].str(), result[4].str(), result[5].str());
		return figures;
	}

	ErrorCode error;
	error.code = 0;
	throw error;
}

Figures* ReaderPyramid::ObjPyramid(const string& STeamp, const string& HTeamp, const string& densityTeamp, const string& ownerTeamp, const string& colorTeamp) {
	try {
		isOwner(ownerTeamp);
		if (colorTeamp != "")
			isColor(colorTeamp);
		int s = stringToInt(STeamp);
		int h = stringToInt(HTeamp);
		float density = stringToFloat(densityTeamp);
		string owner = ownerTeamp;
		string color = colorTeamp;
		Figures* figure = new Pyramid(s, h, density, owner, color);
		return figure;
	}

	catch (const ErrorCode error) {
		if (error.code == 0)
			throw error;

		if (error.code == 2) {
			int s = stringToInt(STeamp);
			int h = stringToInt(HTeamp);
			float density = stringToFloat(densityTeamp);
			stringstream stream(ownerTeamp);
			string owner = readOwner(stream);
			string color = readColor(stream);
			Figures* figure = new Pyramid(s, h, density, owner, color);
			return figure;
		}
	}
}