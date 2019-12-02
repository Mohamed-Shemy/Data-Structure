#pragma once

#include <iostream>
#include "Dlist.h"

enum Sign{ PLUS, MINUS };

class BigInt
{
public:
	BigInt();
	BigInt(const BigInt&);
	bool operator < (BigInt); 
	bool operator == (BigInt);
	BigInt operator + (BigInt);
	BigInt operator - (BigInt);
	BigInt operator * (BigInt);
	BigInt operator / (BigInt);
	void insert(int);
	void write(std::ostream&);
	void print();
private: //
	Dlist<int> number;
	Sign sign;
	int numDigits;
};