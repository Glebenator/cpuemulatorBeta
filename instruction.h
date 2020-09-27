#pragma once
#include "memory.h"
// ---------- TODO ---------------
// whatever man who tf knows
// 
//
// -------------------------------
//
//Instruction – a class that contains all information required of an instruction -- decodes the instruction;
//converts instruction from unsigned int to binary; provides various accessor functions for all parameters of
//a given instruction(i.e.get src1, get src2, get operation, get immediate etc)


class instruction: public memory{
protected:
	int opcode, dest, unused;
	int src1;
	int src2; //RTYPE VARIABLES
	int immediate, address;
	char type;  /// have to be passed to ROB and IQ
	int index; 
	array <int,32> binary; // can we have only 1 binary value stored at a time? does this work with multiple instructions working simultaneously?
				 // ^ probably, as we shouldn't have to decode multiple instructions at the same time
				 // keyword: "shouldn't"

public:
	void decode (array<int,32>input){
		
		binary = input;
		int temp_type = binary[0]*2 + binary[1]; // converts 2 digit binary into an integer between 0 and 4. represents type of instruction

		if (temp_type == 0){
			R_type_decode(); 
		}
		else if (temp_type == 1){
			I_type_decode();
		}
		else if (temp_type == 2){
			J_type_decode();
		}
		else if (temp_type == 3){
			P_type_decode();
		}

	}
	
	//index = 10

	void R_type_decode(){
	
		type = 'R';
		opcode = binaryToDec(binary, 2, 5); // converts x digit binary starting from index 2 to index 5
		dest = binaryToDec(binary, 6, 10);
        src1 = binaryToDec(binary, 11, 15);
		src2 = binaryToDec(binary, 16, 20);
	}

	void I_type_decode(){
		type = 'I';
		opcode = binaryToDec(binary, 2, 5);
		dest = binaryToDec(binary, 6, 10);
		src1 = binaryToDec(binary, 11, 15);
		immediate = binaryToDec(binary, 16, 31);
	}

	void J_type_decode(){
		type = 'J';
		address = binaryToDec(binary, 2, 31);
	}

	void P_type_decode(){
		type = 'P';
		opcode = binaryToDec(binary, 2, 5);
		dest = binaryToDec(binary, 6, 10);
	}

	int get_op_code() {
		return opcode;
	}
	int get_dest() {
		return dest;
	}
	int get_src1() {
		return src1;
	}
	int get_src2() {
		return src2;
	}
	int get_immediate() {
		return immediate;
	}
	int get_address() {
		return address;
	}
	char get_Type() {
		return type;
	}

};

