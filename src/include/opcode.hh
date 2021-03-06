#ifndef OPCODE_HPP
#define OPCODE_HPP

#include "common.hh"

// Opcodes.
enum class OP : u8
{
	ERR, // Run-time fatal error. Crashes the program.

	HLT, // Loops infinitely at the same instruction. Equivalent to "JMP 0".

	// Harsha adding the new byte code instruction types

	ADD, // Adds 2 topmost numbers on stack
	SUB, // sames
	MUL, // sames
	DIV,
	MOD,
	NEG,

	LESS,
	EQUAL,
	LESS_EQUAL,
	GREATER,
	GREATER_EQUAL,
	NOT,
	AND,
	OR,
	CONST, // SETS


	// Nimish

	POP,

	CONST_0,

	GLOB_VARSET, GLOB_VARGET,
	VARSET, VARGET,

	CALL, CALL_NAT, RET,

	ARR, ARRSET, ARRGET,

	DEL,

	NOP,

	// Bhargav
	JMP_IF_FALSE,
	JMP,
	LOOP

};

struct OPData
{
	const char *str;
	u64 operand_size;
};

extern const OPData OP_DATA[];

#endif /* OPCODE_HPP */