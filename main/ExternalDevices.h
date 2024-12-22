#pragma once
#include <string>
using namespace std;

class GraphicsCard {
	std::string brand;
	int memorySize;
	double price;
public:
	GraphicsCard();
	GraphicsCard(std::string& Brand, int MemorySize, double Price);
	std::string& getBrand();
	int getMemorySize();
	double getPrice();
	void setBrand(std::string& Brand);
	void setMemorySize(int MemorySize);
	void setPrice(double Price);
};
class StorageDevice {
	std::string type;
	int capacity;
	double price;
public:
	StorageDevice();
	StorageDevice(std::string& Type, int Capacity, double Price);
	string& getType();
	int getCapacity();
	double getPrice();
	void setType(std::string& Type);
	void setCapacity(int Capacity);
	void setPrice(double Price);
};
class NetworkCard {
	std::string type;
	int speed;
	double price;
public:
	NetworkCard();
	NetworkCard(std::string& Type, int Speed, double Price);
	std::string& getType();
	int getSpeed();
	double getPrice();
	void setType(std::string& Type);
	void setSpeed(int Speed);
	void setPrice(double Price);
};
class PowerSupply {
	int wattage;
	std::string efficiencyRating;
	double price;
public:
	PowerSupply();
	PowerSupply(int Wattage, std::string& EfficiencyRating, double Price);
	int getWattage();
	std::string getEfficiencyRating();
	double getPrice();
	void setWattage(int Wattage);
	void setEfficiencyRating(std::string& EfficiencyRating);
	void setPrice(double Price);

};
class Battery {
	int capacity;
public:
	Battery();
	Battery(int Capacity);
	int getCapacity();
	void setCapacity(int Capacity);
};
class Case {
	std::string formFactor;
	std::string color;
	int price;
public:
	Case();
	Case(std::string& FormFactor, std::string& Color);
	std::string getFormFactor();
	std::string getColor();
	void setPrice(double Price);
	double getPrice();
	void setFormFactor(std::string& FormFactor);
	void setColor(std::string& Color);
};







