#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <deque>
#include "register_file.h"

using namespace std;


class ReorderBuffer : public register_file {
protected:
	int a = 0;

	struct ROB_element {
		int valid;
		int rob_ID;
		ROB_element() {
			valid = 0;
		};
	};

	deque<ROB_element> rob;

};