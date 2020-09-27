#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include "ReorderBuffer.h"

class IQ: public ReorderBuffer{
protected:
	struct queue_element {
		int PC_index, opcode;
		int* valid1;
		int src1;
		int* valid2;
		int src2;

		int rob_ID, immediate, dest;
		char type;
	};
	deque<queue_element> q;

public:
	void addToQueue() {
		//inceremtn timer since we added to que???
		q.push_back(queue_element());
		if (get_Type() == 'R') {
			q.back().type = 'R';
			q.back().PC_index = get_PC();
			q.back().opcode = get_op_code();

			q.back().src1 = get_src1();
			q.back().valid1 = &r[get_src1()].valid;

			q.back().src2 = get_src2();
			q.back().valid2 = &r[get_src2()].valid;

			q.back().dest = get_dest();
			//q.back().rob_ID = ;

			PC_increment();
		}
		
		else if (get_Type() == 'I') {
			q.back().type = 'I';
			q.back().PC_index = get_PC();
			q.back().opcode = get_op_code();

			q.back().src1 = get_src1();
			q.back().valid1 = &r[get_src1()].valid;

			q.back().immediate = get_immediate();

			q.back().dest = get_dest();

			PC_increment();
		}

		else if (get_Type() == 'J') { 
			q.back().type = 'J';
			q.back().PC_index = get_PC();

			set_PC(get_address());
		}

		else if (get_Type() == 'P') {
			q.back().type = 'P';
			q.back().PC_index = get_PC();
			q.back().opcode = get_op_code();

			q.back().immediate = input_immediate();

			q.back().dest = get_dest();

			PC_increment();
		}

	}

	void removeFromQueue(int ID) {
		
	}
};

