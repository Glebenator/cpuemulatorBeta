#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include "IQ.h"                                                                                
using namespace std;

// ---------- TODO ---------------
// 
// 
//
// 
//
// -------------------------------


class ALU : public IQ {
public:
	int ALU_result;
	void ALU_execute(int operation, int a, int b){
		switch(operation){
		case 0:
			ALU_result = a + b;
			// r = q[index].src1 + q[index].src2;
			break;
		case 1:
			ALU_result = a - b;
			break;
		case 2:
			ALU_result = a * b;
			break;
		case 3:
			//divide
			ALU_result = a / b;
			break;
		case 4:
			//modulo
			ALU_result = a % b;
			break;
		case 5:
			//BEQ
			if ((r[q[PC].dest].data - a) == 0) {
				PC = b-1;
			}
			//else
			//	PC = PC + 1;
			break;
		case 6:
			//BNE
			if ((r[q[PC].dest].data - a) != 0) {
				PC = b-1;
			}
			//else
			//	PC = PC + 1;
			break;
		case 7:
			//move;
			ALU_result = a;
			break;
		case 8:
			cout << "result: " << a << endl;
			break;

		}
	}
};
//r.[pc].data = ALU_execute(q[pc].opcode, q[pc].src1, q[pc].src2)