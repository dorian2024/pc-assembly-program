#include "ComputerAssembly.h"
#include <iostream>
#include<cstdlib>
using namespace std;
ComputerAssembly::ComputerAssembly() {
	cpu = nullptr;
	pm = nullptr;
	mb = nullptr;
	storageDevice = nullptr;
	networkCard = nullptr;
	powerSupply = nullptr;
	battery = nullptr;
	outerCase = nullptr;
	totalPrice = 0;
	isLaptop = false;
	computer = NULL;
}
double ComputerAssembly::getTotalPrice() {
	return totalPrice;
}
void ComputerAssembly::addToTotalPrice(double Price) {
	totalPrice += Price;
}
void ComputerAssembly::startOfAssembly() {
	int input = 0;
	cout << "Do you want to create a Laptop or a Computer?\n1.Laptop.\n2.Computer.\n";
	cin >> input;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid value entered. The assembly will now restart\n";
		startOfAssembly();
	}
	if (input == 1) {
		isLaptop = true;
	}
	else if (input == 2) {
		isLaptop = false;
	}
	else if(input != 1 && input != 2) {
		cout << "Invalid value entered. The assembly will now restart\n";
		startOfAssembly();
	}
	//for ALU
	int adders;
	int subtracters;
	int registers;
	int sizeOfRegisters;
	cout << "Let's start with the ALU. Enter the number of adders in the ALU: ";
	cin >> adders;
	if (adders < 0) {
		char ch;
		cout << "Invalid value entered. The program will now restart. Press any key to continue. " << endl;
		cin.get(ch);
		system("cls");
		this->startOfAssembly();
	}
	cout << "Now enter the number of subtractors: ";
	cin >> subtracters;
	if (subtracters < 0) {
		char ch;
		cout << "Invalid value entered. The program will now restart. Press any key to continue. " << endl;
		cin.get(ch);
		system("cls");
		this->startOfAssembly();
	}
	cout << "How many registers do you want in the ALU? ";
	cin >> registers;
	if (registers < 0) {
		char ch;
		cout << "Invalid value entered. The program will now restart. Press any key to continue. " << endl;
		cin.get(ch);
		system("cls");
		this->startOfAssembly();
	}
	cout << "Enter the size of the registers: ";
	cin >> sizeOfRegisters;
	if (sizeOfRegisters < 0) {
		char ch;
		cout << "Invalid value entered. The program will now restart. Press any key to continue. " << endl;
		cin.get(ch);
		system("cls");
		this->startOfAssembly();
	}
	//for CU
	cout << "Now for the control unit, enter clock value: ";
	float clock;
	cin >> clock;
	if (clock < 0) {
		char ch;
		cout << "Invalid value entered. The program will now restart. Press any key to continue. " << endl;
		cin.get(ch);
		system("cls");
		this->startOfAssembly();
	}
	CPUcreation(adders, subtracters, registers, sizeOfRegisters, clock);
}
//constructors:
MAC::MAC() : ComputerAssembly() { 
	cpu = new AppleSilicon;//polymorphism
	pm = new PhysicalMemory();
	mb = new MotherBoard;
}
Intel::Intel():ComputerAssembly(){
	GC = NULL;
	cpu = new CPU();
	pm = new PhysicalMemory();
	mb = new MotherBoard();
}
void MAC::CPUcreation(int adders, int subtracters, int registers, int sizeOfRegisters, float clock) {
	//alu
	ALU alu(adders, subtracters, registers, sizeOfRegisters);
	cpu->setALU(alu);
	//cu
	ControlUnit cu(clock);
	cpu->setCU(cu);
	//GPU
	cout << "Select your AppleSilicon GPU size (from 8GB to 16GB): ";
	int size = 0;
	cin >> size;
	float price = 999 * (size - 7);
	cpu->setGraphicsCard("AppleSilicon", size, price);
	ComputerCreation();
	externalDeviceAddition();

}
void Intel::CPUcreation(int adders, int subtracters, int registers, int sizeOfRegisters, float clock)
{
	//alu
	ALU alu(adders, subtracters, registers, sizeOfRegisters);
	cpu->setALU(alu);
	//cu
	ControlUnit cu(clock);
	cpu->setCU(cu);
	ComputerCreation();
	GraphicsCardAddition();
	externalDeviceAddition();
}
void Intel::GraphicsCardAddition() {
	int check = 0;
	cout << "Would you like to add an additional graphics card to your pc?\n1. Yes\n2. No\n";
	cin >> check;
	if (check == 2) {
		return;
	}
	else if (check == 1) {
		cout << "Enter the brand of Graphics card you'd like: \nNvidia\nAMD";
		string brand;
		cin >> brand;
		cout << "Enter the required memory size for your graphics card: ";
		int size;
		cin >> size;
		double price = 999;
		addToTotalPrice(price);
		GC = new GraphicsCard(brand, size, price);
		return;
	}
	else {
		cin.ignore(10000, '\n');
		cout << "Invalid value entered\n";
		return;
	}
}
void ComputerAssembly::ComputerCreation() {
	//main memory
	int capacity;
	cout << "Enter main memory capacity: ";
	cin >> capacity;
	cout << "Type in the main memory technology type: \n 1. Semiconductor\n 2. Silicon\n";
	string type;
	cin >> type;
	MainMemory mm(capacity, type);
	mb->setmm(mm);
	//ports
	cout << "Enter type of port: \nIO ports\nVGI ports\nUSB port\nHDMI port";
	cin >> type;
	cout << "Enter baud_rate: ";
	int br;
	cin >> br;
	Port p(type, br);
	mb->setport(p);
	computer = new Computer(*pm, *mb, *cpu);
	//physical memory
	cout << "Select your physical memory capacity: \n";
	cin >> capacity;
	pm->setcapacity(capacity);
	double price = (765); //service charges
	addToTotalPrice(price);
}
void ComputerAssembly::externalDeviceAddition() {
	//storage device
	int check = 0;
	cout << "Would you like to add an additional storage device to your pc?\n1. Yes\n2. No\n";
	cin >> check;
	if (check == 1) {
		cout << "Enter the type of Storage Device you'd like: \nHDD\nSSD";
		string type;
		cin >> type;
		cout << "Enter the required capacity for your storage device: ";
		int size;
		cin >> size;
		double price = 999;
		addToTotalPrice(price);
		storageDevice = new StorageDevice(type, size, price);
	}
	else {
		cin.ignore(10000, '\n');
		cout << "Invalid value entered\n";
		return;
	}
	//network card
	check = 0;
	cout << "Would you like to add an additional network card to your pc?\n1. Yes\n2. No\n";
	cin >> check;
	if (check == 1) {
		cout << "Enter the type of network card you'd like: \nEthernet\nWi-fi\n";
		string type;
		cin >> type;
		cout << "Enter the required speed for your network card: ";
		int speed;
		cin >> speed;
		double price = 29.3;
		addToTotalPrice(price);
		storageDevice = new StorageDevice(type, speed, price);
	}
	else {
		cin.ignore(10000, '\n');
		cout << "Invalid value entered\n";
		return;
	}
	//powersupply
	if (isLaptop == false) {
		cout << "Enter the wattage of the power supply youd like: ";
		int wattage = 0;
		cin >> wattage;
		cout << "Give efficiency rating of required power supply: \n80 Plus Bronze\n80 Plus bronze\n";
		string efficiency;
		cin >> efficiency;
		double price = 87;
		addToTotalPrice(price);
		powerSupply = new PowerSupply(wattage, efficiency, price);
	}
	else if (isLaptop == true) {
		cout << "Enter capacity of the battery required for your laptop: ";
		int capacity = 0;
		cin >> capacity;
		battery = new Battery(capacity);
	}
	cout << "Enter the form factor for your case: \nATX\nMicro ATX\n";
	string form;
	cin >> form;
	cout << "Enter the desired color of your case: ";
	string color;
	cin >> color;
	int price = 90;
	outerCase = new Case(form, color);
	outerCase->setPrice(price);
	if (!isLaptop) {
		addToTotalPrice(price);
	}
	display();
}
void ComputerAssembly::display() const {
	cout << "Press enter to view your completer PC details: \n";
	system("cls");
	if (isLaptop) {
		cout << "Your Laptop contains: \n\n";
	}
	else { cout << "Your PC contains: \n\n"; }
	computer->display();
	if (storageDevice != nullptr) {
		cout << "A storage device of type: " << storageDevice->getType() << endl;
		cout << "Capacity: " << storageDevice->getCapacity() << endl;
		cout << "Price: " << storageDevice->getPrice() << endl;
	}
	if (networkCard != nullptr) {
		cout << "A network card of type: " << networkCard->getType() << endl;
		cout << "Speed: " << networkCard->getSpeed() << endl;
		cout << "Price: " << networkCard->getPrice() << endl;
	}
	if (powerSupply != nullptr) {
		cout << "A powersupply of wattage: " << powerSupply->getWattage() << endl;
		cout << "Efficiency rating: " << powerSupply->getEfficiencyRating() << endl;
		cout << "Price: " << powerSupply->getPrice() << endl;
	}
	if (battery != nullptr) {
		cout << "A battery of capacity: " << battery->getCapacity() << "watts" << endl;
	}
	if (outerCase != nullptr) {
		cout << "An outer case of form factor: " << outerCase->getFormFactor() << endl;
		cout << "Color: " << outerCase->getColor() << endl;
		cout << "Price: ";
		if (isLaptop) {
			cout << 0;
		}
		else {
			cout << outerCase->getPrice() << endl;
		}
	}
	cout << "The total price for your assembly is: " << totalPrice << endl;
}

