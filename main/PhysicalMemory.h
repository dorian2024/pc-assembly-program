#pragma once
#include <iostream>
#include <string>
using namespace std;
class PhysicalMemory
{
	int capacity;
public:
	PhysicalMemory();
	PhysicalMemory(int c);
	void setcapacity(int c);
	int getcapacity();
	void display();
};
