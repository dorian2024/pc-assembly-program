#pragma once
#include "Computer.h"
class ComputerAssembly
{
protected:
	CPU* cpu;
	MotherBoard* mb;
	double totalPrice;
	bool isLaptop;
	Computer* computer; //composition
	PhysicalMemory* pm;
	//external devices
	StorageDevice* storageDevice;
	NetworkCard* networkCard;
	PowerSupply* powerSupply;
	Battery* battery;
	Case* outerCase;

public: 
	ComputerAssembly();
	double getTotalPrice();
	void addToTotalPrice(double Price);
	void startOfAssembly();
	virtual void CPUcreation(int adders,int subtracters, int registers, int sizeOfRegisters, float clock){}
	virtual void ComputerCreation();
	void externalDeviceAddition();
	void display() const;
};
class MAC: public ComputerAssembly{
public:
	MAC();
	void CPUcreation(int adders, int subtracters, int registers, int sizeOfRegisters, float clock) override;
};
class Intel: public ComputerAssembly{
private:
	GraphicsCard* GC;
public:
	Intel();
	void CPUcreation(int adders, int subtracters, int registers, int sizeOfRegisters, float clock);
	void GraphicsCardAddition();
};
//public inheritance because i need to use start of assembly in main to start off the process
