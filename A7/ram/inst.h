// definition of an instruction

#ifndef INSTHEADER
#define INSTHEADER

enum OPCODES { LDA, LDI, STA, STI, ADD, SUB, MUL, JMP, JMZ, JMN, JMI, HLT };

struct Instruction
{
	OPCODES opcode;
	int operand;
};

#endif
