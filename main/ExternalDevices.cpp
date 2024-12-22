#include "ExternalDevices.h"
#include <string>
using namespace std;
//graphics card
GraphicsCard::GraphicsCard() {
	brand = "\0";
	memorySize = 0;
	price = 0;
}
GraphicsCard::GraphicsCard(std::string& Brand, int MemorySize, double Price) {
	brand = Brand;
	memorySize = MemorySize;
	price = Price;
}
std::string& GraphicsCard::getBrand() {
	return brand;
}
int GraphicsCard::getMemorySize() {
	return memorySize;
}
double GraphicsCard::getPrice() {
	return price;
}
void GraphicsCard::setBrand(std::string& Brand) {
	brand = Brand;
}
void GraphicsCard::setMemorySize(int MemorySize) {
	memorySize = MemorySize;
}
void GraphicsCard::setPrice(double Price) {
	price = Price;
}
//storage devices
StorageDevice::StorageDevice() {
	type = "\0";
	capacity = 0;
	price = 0;
}
StorageDevice::StorageDevice(string& Type, int Capacity, double Price) {
	type = Type;
	capacity = Capacity;
	price = Price;
}
string& StorageDevice::getType() {
	return type;
}
int StorageDevice::getCapacity() {
	return capacity;
}
double StorageDevice::getPrice() {
	return price;
}
void StorageDevice::setType(string& Type) {
	type = Type;
}
void StorageDevice::setCapacity(int Capacity) {
	capacity = Capacity;
}
void StorageDevice::setPrice(double Price) {
	price = Price;
}
//network card
NetworkCard::NetworkCard() {
	type = "";
	speed = 0;
	price = 0;
}
NetworkCard::NetworkCard(std::string& Type, int Speed, double Price) {
	type = Type;
	speed = Speed;
	price = Price;
}
std::string& NetworkCard::getType() {
	return type;
}
int NetworkCard::getSpeed() {
	return speed;
}
double NetworkCard::getPrice() {
	return price;
}
void NetworkCard::setType(string& Type) {
	type = Type;
}
void NetworkCard::setSpeed(int Speed) {
	speed = Speed;
}
void NetworkCard::setPrice(double Price) {
	price = Price;
}
//power supply
PowerSupply::PowerSupply() {
	wattage = 0;
	efficiencyRating = "";
	price = 0;
}
PowerSupply::PowerSupply(int Wattage, string& EfficiencyRating, double Price) {
	wattage = Wattage;
	efficiencyRating = EfficiencyRating;
	price = Price;
}
int PowerSupply::getWattage() {
	return wattage;
}
string PowerSupply::getEfficiencyRating() {
	return efficiencyRating;
}
double PowerSupply::getPrice() {
	return price;
}
void PowerSupply::setWattage(int Wattage) {
	wattage = Wattage;
}
void PowerSupply::setEfficiencyRating(string& EfficiencyRating) {
	efficiencyRating = EfficiencyRating;
}
void PowerSupply::setPrice(double Price) {
	price = Price;
}
//battery
Battery::Battery() {
	capacity = 0;
}
Battery::Battery(int Capacity) {
	capacity = Capacity;
}
int Battery::getCapacity() {
	return capacity;
}
void Battery::setCapacity(int Capacity) {
	capacity = Capacity;
}
//case
Case::Case() {
	formFactor = "";
	color = "";
}
Case::Case(string& FormFactor, string& Color) {
	formFactor = FormFactor;
	color = Color;

}
string Case::getFormFactor() {
	return formFactor;
}
string Case::getColor() {
	return color;
}
void Case::setFormFactor(string& FormFactor) {
	formFactor = FormFactor;
}
void Case::setColor(string& Color) {
	color = Color;
}
void Case::setPrice(double Price) {
	price = Price;
}
double Case::getPrice() {
	return price;
}