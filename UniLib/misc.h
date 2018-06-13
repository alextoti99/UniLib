#pragma once
#include <string>

using namespace std;

class misc {
public:
	//Gets size of a variable based on the index
	//1 = chat
	//2 = int
	//3 = short int
	//4 = long int
	//5 = float
	//6 = double
	//7 = wchar_t
	//8 = bool
	static int getSizeOf(int index) {
		int final = 0;

		if (index == 1)
			final = sizeof(char);
		else if (index == 2)
			final = sizeof(int);
		else if (index == 3)
			final = sizeof(short int);
		else if (index == 4)
			final = sizeof(long int);
		else if (index == 5)
			final = sizeof(float);
		else if (index == 6)
			final = sizeof(double);
		else if (index == 7)
			final = sizeof(wchar_t);
		else if (index == 8)
			final = sizeof(bool);

		int final;
	}

	//Gets the size of a byte array	(unsigned char)
	static int getSizeOfBytes(unsigned char *data) {
		return sizeof(data);
	}
};