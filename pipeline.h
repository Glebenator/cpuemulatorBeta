#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include "ALU.h"
#include "statistics.h"

using namespace std;

// ---------- TODO ---------------
// 1. make read_csv not hardcoded to fibonacci.csv
// 2. setup registerfile so pc can update/be stored 
// 3. figure out the implementation of IQueue (how does it manage what function goes at what time?)
// 4. idk man too much shit
//
// -------------------------------


class pipeline: public ALU{
protected:
	statistics timer;
public:
	void begin() {
		string program;
		cout << "input a program to execute (formatted as xxxx.csv): ";
		cin >> program;
		read_csv(program);
		if (read_success == true) {

			//begin timer
			fetch();
			//time how long it fetches for.... in .... seconds? internal clock cyucles???
		}
		else {
			cout << endl;
			begin();

			
		}
	}

	void fetch() {
		//check if ROB and IQ have enough free entries
		//fetch the instruction located at PC from instruction memory
		//decode the instruction
		//asign a ROB ID to the instruction
		array<int,32> current_instruction = get_next_instruction(get_PC());
		decode(current_instruction);

		addToQueue();
		
		if (PC < instruction_size) {
			fetch();
		}
		else {
			q.resize(20);
			set_PC(0);
			//end timer
			//
			execute();
			
		}

		//if (get_Type() == 'j') {}
	}

	void execute() {
		if (q[PC].type == 'R') {
			int i = PC;
			ALU_execute(q[i].opcode, r[q[i].src1].data, r[q[i].src2].data);

			if (q[i].opcode != 5 && q[i].opcode != 6) {
				r[q[i].dest].data = ALU_result;
			}
			
			PC_increment();
		}
		if (q[PC].type == 'I') {
			int i = PC;
			ALU_execute(q[i].opcode, r[q[i].src1].data, q[i].immediate);

			if (q[i].opcode != 5 && q[i].opcode != 6) {
			r[q[i].dest].data = ALU_result;
			}
			
			PC_increment();
		}
		if (q[PC].type == 'P') {
			r[2].data = q[PC].immediate;

			PC_increment();
		}

		//q.back().src1 = &r[get_src1()].data;
		

		if (PC < instruction_size) {
			execute();
		}
		else {
			set_PC(0);
			//end timer
			//
			//commit();
			cout << "Program complete!" << endl;
		}
		//if (r[].data = NULL){ 
		//	r[].valid = 0;
		//}
	}

	void commit() {
		if (PC < instruction_size) {
			commit();
		}
		else {
			set_PC(0);
			//end timer
			//
			
		}
	}
	pipeline() {};

};

