#pragma once
#include "PhysicalMemory.h"
#include "MotherBoard.h"
#include "CPU.h"
#include <iostream>
using namespace std;
class Computer
{
protected:
	PhysicalMemory* pm;
	MotherBoard* mb;
	CPU* cpu;
public:
	Computer();
	Computer(PhysicalMemory& pm, MotherBoard& mb, CPU& cpu);
	PhysicalMemory& getPhysicalMemory();
	MotherBoard& getMotherBoard();
	CPU& getCPU();
	void setPhysicalMemory(PhysicalMemory& physicalMemory);
	void setMotherBoard(MotherBoard& motherBoard);
	void setCPU(CPU& CPU);
	void display();
	~Computer();
};

