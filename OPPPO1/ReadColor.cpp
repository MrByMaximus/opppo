#include "ReadColor.h"

using namespace std;

string readColor(stringstream& stream) {
	string str;
	char str2;
	int count = 0;
	
	if (stream.peek() != '"') {
		stream >> str;
		return str;
	}

	stream.get(str2);
	str += str2;
	while (1) {
		stream.get(str2);

		if (str2 == '"' || count == 50) {
			str += str2;
			break;
		}

		str += str2;
		count++;
	}

	return str;
}