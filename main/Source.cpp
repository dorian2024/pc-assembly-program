#include<iostream>
#include <string>
#include"../OOPassignment3/CPU.h"
#include "../OOPassignment3/MotherBoard.h"
#include "../OOPassignment3/PhysicalMemory.h"
#include "ComputerAssembly.h"
using namespace std;
bool MACorIntel() {
	int input = 0;
	cout << "Welcome to our computer assembly workshop. Would you like to buy a MAC or an Intel computer?\n1. MAC.\n2. Intel.\n";
	cin >> input;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid value entered. The program will now restart\n";
		MACorIntel();
	}
	if (input == 1) {
		return true; //is a MAC
	}
	else if (input == 2) {
		return false;
	}
	else {
		cout << "Invalid value entered. The program will now restart\n";
		MACorIntel();
	}

}
int main() {
	MAC* computer = nullptr;
	Intel* computer2 = nullptr;
	if (MACorIntel()) {
		computer = new MAC();
		computer->startOfAssembly();
	}
	else {
		computer2 = new Intel();
		computer2->startOfAssembly();
	}
	delete computer;
	delete computer2;
	return 0;
}