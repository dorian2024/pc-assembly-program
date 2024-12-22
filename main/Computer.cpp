#include "Computer.h"
#include "PhysicalMemory.h"
#include "MotherBoard.h"
#include "CPU.h"
#include <iostream>
#include <string>
using namespace std;
Computer::Computer() {
	mb = new MotherBoard;
	pm = NULL;
	cpu = new CPU;

}
Computer::Computer(PhysicalMemory& pm, MotherBoard& mb, CPU& cpu) {
	this->pm = &pm;
	this->mb = new MotherBoard(mb);
	this->cpu = new CPU(cpu);
}
PhysicalMemory& Computer::getPhysicalMemory() {
	return *pm;
}
MotherBoard& Computer::getMotherBoard() {
	return *mb;
}
CPU& Computer::getCPU() {
	return *cpu;
}
void Computer::setPhysicalMemory(PhysicalMemory& physicalMemory) {
	pm->setcapacity(physicalMemory.getcapacity());
}
void Computer::setMotherBoard(MotherBoard& motherBoard) {
	mb->setmm(motherBoard.getmm());
	mb->setport(motherBoard.getport());
}
void Computer::display() {
	pm->display();
	mb->display();
	cpu->display();
}
void Computer::setCPU(CPU& CPU) {
	cpu->setALU(CPU.getALU());
	cpu->setCU(CPU.getCU());
}
Computer::~Computer() {
	delete mb;
	delete cpu;
	mb = NULL;
	cpu = NULL;
}