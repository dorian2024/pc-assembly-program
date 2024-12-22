#pragma once
#include <string>
#include <iostream>
using namespace std;
//includes motherboard, ports and main memory classes
//MainMemory
class MainMemory
{
	int capacity;
	std::string technologyType;
public:
	MainMemory();
	MainMemory(int c, string& tt);
	void setCapacity(int c);
	int getCapacity();
	void setTechType(string& tt);
	string& getTechType();
};
//Ports
class Port
{
	string type;
	int baud_rate;
public:
	Port();
	Port(string& t, int br);
	void setType(string& t);
	void setBaudRate(int br);
	string& getType();
	int getBaudRate();
};
//MotherBoard
class MotherBoard
{
	MainMemory* mm;
	Port* ports;
public:
	MotherBoard();
	MotherBoard(MainMemory& mainmemory, int br, string& porttype);
	MainMemory& getmm();
	Port& getport();
	void setmm(MainMemory& mainmemory);
	void setport(Port& p);
	void display();
	~MotherBoard();
};


