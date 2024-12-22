#pragma once
#include <iostream>
#include <istream>
#include "ExternalDevices.h"
//has CPU ALU and ControlUnit classes
class ALU
{
	//private because i dont plan on inheriting it
private:
	int NoOfAdders;
	int NoOfSubtractor;
	int NoOfRegisters;
	int sizeOfRegisters;
public:
	//constructors
	ALU();
	ALU(int a, int s, int r, int sr);
	ALU(ALU& a);
	//getters
	int getNoOfAdders();
	int getNoOfSubtracters();
	int getNoOfRegisters();
	int getSizeOfRegisters();
	//setters
	void setNoOfAdders(int a);
	void setNoOfSubtracters(int a);
	void setNoOfRegisters(int a);
	void setSizeOfRegisters(int a);
};
class ControlUnit
{
private:
	float clock;
public:
	ControlUnit();
	ControlUnit(float c);
	ControlUnit(ControlUnit& c);
	float getClock();
	void setClock(float c);
};

class CPU
{
protected:
	//composition with ALU and CU
	ALU* alu;
	ControlUnit* cu;
public:
	CPU();
	CPU(ALU& a, ControlUnit& c);
	CPU(int adder, int subtractor, int registers, int size, float clock);
	virtual void setGraphicsCard(string Brand, int MemorySize, double Price);
	void setALU(ALU& ALU);
	void setCU(ControlUnit& CU);
	ALU& getALU();
	ControlUnit& getCU();
	virtual ~CPU();
	virtual void display();
};
class AppleSilicon : public CPU {
protected:
	GraphicsCard* GC;
public: 
	AppleSilicon();
	AppleSilicon(int adder, int subtractor, int registers, int size, float clock);
	virtual void setGraphicsCard(string Brand, int MemorySize, double Price);
	~AppleSilicon();
};
