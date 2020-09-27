#pragma once
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

class statistics {
public:
 	clock_t start;
	double duration;


	void start_timer() {
		start = clock();
	};

	void stop_timer() {
		CLOCKS_PER_SEC;
	
	};




};