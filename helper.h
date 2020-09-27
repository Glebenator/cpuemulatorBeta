#pragma once
#include <string>
#include <iostream>
#include <array>
using namespace std;


class helper{

//new order:
//helper -> memory -> instruction -> register_file -> ReorderBuffer -> IQ -> ALU -> pipeline
                                              
public:
	helper() {

	}
	array<int,32> stringToBinary(string decimal) {
		unsigned int val;
		array<int, 32> binary;
		val = stoul (decimal);
		unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

		for (int i = 0; i < sizeof(unsigned int) * 8; i++)
		{
			if ((val & mask) == 0)
				//insert 0 here
				binary[i] = 0;
			else
				//insert 1 here
				binary[i] = 1;

			mask >>= 1;
		}

		return binary;
	}
	int binaryToDec(array<int,32> binArray, int start, int finish) {
	// EXAMPLE:
	// TEST INPUT:  index[6], index[10]
	// EXPECTED CALCULATION: index[6]*2^4 + index[7]*2^3 + index[8]*2^2 + index[7]*2 + index[8]

		int dec = 0;
		int index = 1;
		for (int i = finish; i >= start; i--) {
			dec += binArray[i] * index;
			index = index * 2;
			}
		return dec;
	}
	int input_immediate() {
		int output;
		cout << "input immediate: ";
		cin >> output;
		return output;
	}
};

