#include "CPU.h"
#include <iostream>
using namespace std;
//has CPU ALU and ControlUnit classes
//ALU
ALU::ALU() {
	NoOfAdders = 0;
	NoOfSubtractor = 0;
	NoOfRegisters = 0;
	sizeOfRegisters = 0;
}
ALU::ALU(int a, int s, int r, int sr) {
	NoOfAdders = a;
	NoOfSubtractor = s;
	NoOfRegisters = r;
	sizeOfRegisters = sr;
}
ALU::ALU(ALU& a) {
	NoOfAdders = a.getNoOfAdders();
	NoOfRegisters = a.getNoOfRegisters();
	NoOfSubtractor = a.getNoOfSubtracters();
	sizeOfRegisters = a.getSizeOfRegisters();
}
int ALU::getNoOfAdders() {
	return NoOfAdders;
}
int ALU::getNoOfSubtracters() {
	return NoOfSubtractor;
}
int ALU::getNoOfRegisters() {
	return NoOfRegisters;
}
int ALU::getSizeOfRegisters() {
	return sizeOfRegisters;
}
void ALU::setNoOfAdders(int a) {
	NoOfAdders = a;
}
void ALU::setNoOfSubtracters(int a) {
	NoOfSubtractor = a;
}
void ALU::setNoOfRegisters(int a) {
	NoOfRegisters = a;
}
void ALU::setSizeOfRegisters(int a) {
	sizeOfRegisters = a;
}


//ControlUnit
ControlUnit::ControlUnit() {
	clock = 0;
}
ControlUnit::ControlUnit(float c) {
	clock = c;
}
ControlUnit::ControlUnit(ControlUnit& c) {
	clock = c.getClock();

}
float ControlUnit::getClock() {
	return clock;
}
void ControlUnit::setClock(float c) {
	clock = c;
}
//CPU
CPU::CPU() {
	alu = new ALU;
	cu = new ControlUnit;
}
CPU::CPU(ALU& a, ControlUnit& c) {
	alu = new ALU(a);
	cu = new ControlUnit(c);
	alu->setNoOfAdders(a.getNoOfAdders());
	alu->setNoOfRegisters(a.getNoOfRegisters());
	alu->setNoOfSubtracters(a.getNoOfSubtracters());
	alu->setSizeOfRegisters(a.getSizeOfRegisters());
	cu->setClock(c.getClock());
}
CPU::CPU(int adder, int subtractor, int registers, int size, float clock) {
	alu = new ALU;
	cu = new ControlUnit;
	alu->setNoOfAdders(adder);
	alu->setNoOfRegisters(registers);
	alu->setNoOfSubtracters(subtractor);
	alu->setSizeOfRegisters(size);
	cu->setClock(clock);
}
void CPU::setALU(ALU& ALU) {
	alu->setNoOfAdders(ALU.getNoOfAdders());
	alu->setNoOfRegisters(ALU.getNoOfRegisters());
	alu->setNoOfSubtracters(ALU.getNoOfSubtracters());
	alu->setSizeOfRegisters(ALU.getSizeOfRegisters());
}
void CPU::setCU(ControlUnit& CU) {
	cu->setClock(CU.getClock());
}
ALU& CPU::getALU() {
	return *alu;
}
ControlUnit& CPU::getCU() {
	return *cu;
}
void CPU::setGraphicsCard(string Brand, int MemorySize, double Price)
{
	GraphicsCard GC(Brand, MemorySize, Price); //will be overriden
}
void CPU::display() {
	cout << "A CPU with \n" << "No. of adders: " << alu->getNoOfAdders() << "\nNo of registers: " << alu->getNoOfRegisters()<< "\nNo. of subtractors: " << alu->getNoOfSubtracters() << "\nSize of registers: " << alu->getSizeOfRegisters() << endl;
	cout << "Clock size of : " << cu->getClock() << endl;
}
CPU::~CPU() {
	delete alu;
	delete cu;
}
AppleSilicon::AppleSilicon() {
	GC = new GraphicsCard;
}
AppleSilicon::AppleSilicon(int adder, int subtractor, int registers, int size, float clock) {
	GC = new GraphicsCard;
	this->cu->setClock(clock);
	this->alu->setNoOfAdders(adder);
	this->alu->setNoOfSubtracters(subtractor);
	this->alu->setNoOfRegisters(registers);
	this->alu->setSizeOfRegisters(size);
}
void AppleSilicon::setGraphicsCard(string Brand, int MemorySize, double Price)
{
	GC->setBrand(Brand);
	GC->setMemorySize(MemorySize);
	GC->setPrice(Price);
}
AppleSilicon::~AppleSilicon()
{
	delete GC;
}
