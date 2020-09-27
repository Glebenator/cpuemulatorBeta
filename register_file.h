#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include "instruction.h"


using namespace std;
struct sregister {
	int data = NULL;
	int valid = 0;

	sregister() {
		int data = NULL;
		int valid = 0;
	};
};
class register_file: public instruction{
protected:
	int PC = 0;
public:
	vector<sregister> r;

	void PC_increment() {
		PC++;
	}

	int get_PC() {
		return PC;
	}

	void set_PC(int input) {
		PC = input;
	}

	register_file() {
		for (int i = 0; i < 16; i++) {
			r.push_back(sregister());
		}
		r[0].data = 0;
		r[0].valid = 1;
	}
};

