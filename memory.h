#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream> 
#include <queue>
#include "helper.h"

using namespace std;

//Memory – a class that initializes memory(specify size in an overload constructor); initialize contents -
//read in csv file and create instruction memory.Note if you read in your csv contents as a string, then you
//will first need convert string to unsigned integer; fetch from memory using an input address(PC);

class memory: public helper{
protected:
	vector <string> str_instructions; // in case we need the string vector later;
	vector <array<int,32>> instructions;
	int instruction_size;

public:
	bool read_success = false;

	void read_csv(string filename) {
		read_success = true;
		ifstream myfile(filename);

		if (!myfile.is_open()) {
			cout << "ERROR LOADING. Make sure the file is not currently open, and the filename is correct." << '\n';
			read_success = false;
		}
		string inst;
		while (myfile.good()) {

			getline(myfile, inst, ','); //just reads numbers until comma
			str_instructions.push_back(inst);
			instructions.push_back(stringToBinary(inst)); //pushes them to queue right after ||| we could just do stoul()
			instruction_size++;
		}
		myfile.close();
	}
	memory() {

	}
	memory(int size) {

	}
	vector<array<int, 32>> get_instructions() {
		return instructions;
	}
	array<int,32> get_next_instruction(int PC) {
		return instructions[PC];
	}

	/*vector<string> str_get_instructions() {
		return str_instructions;
	}
	string str_get_next_instruction(int PC) {
		return str_instructions[PC];
	}*/
};

