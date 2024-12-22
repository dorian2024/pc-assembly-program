#include "MotherBoard.h"
#include <iostream>
using namespace std;
//includes motherboard, ports and main memory classes
//MainMemory
MainMemory::MainMemory() {
	capacity = 0;
	technologyType = "\0";
}
MainMemory::MainMemory(int c, string& tt) {
	capacity = c;
	technologyType = tt;
}
void MainMemory::setCapacity(int c) {
	capacity = c;
}
int MainMemory::getCapacity() {
	return capacity;
}
void MainMemory::setTechType(string& tt) {
	technologyType = tt;
}
string& MainMemory::getTechType() {
	return technologyType;
}
//Ports
Port::Port() {
	type = "\0";
	baud_rate = 0;
}
Port::Port(string& t, int br) {
	type = t;
	baud_rate = br;
}
void Port::setType(string& t) {
	type = t;
}
void Port::setBaudRate(int br) {
	baud_rate = br;
}
string& Port::getType() {
	return type;
}
int Port::getBaudRate() {
	return baud_rate;
}
//MotherBoard
MotherBoard::MotherBoard() {
	mm = new MainMemory;
	this->ports = new Port;

}
MotherBoard::MotherBoard(MainMemory& mainmemory, int br, string& porttype) {
	mm = &mainmemory;
	ports = new Port(porttype, br);
}
MainMemory& MotherBoard::getmm() {
	return *mm;
}
Port& MotherBoard::getport() {
	return *ports;
}
void MotherBoard::setmm(MainMemory& mainmemory) {
	mm->setCapacity(mainmemory.getCapacity());
	mm->setTechType(mainmemory.getTechType());
}
void MotherBoard::setport(Port& p) {
	ports->setBaudRate(p.getBaudRate());
	ports->setType(p.getType());
}
MotherBoard::~MotherBoard() {
	delete mm;
	delete ports;
}
void MotherBoard::display() {
	cout << "A motherboard with : \n";
	cout << "Capacity: " << mm->getCapacity() << endl;
	cout << "Technology type: " << mm->getTechType() << endl;
	cout << "Port type: " << ports->getType() << endl;
	cout << "Port baud rate: " << ports->getBaudRate() << endl;

}