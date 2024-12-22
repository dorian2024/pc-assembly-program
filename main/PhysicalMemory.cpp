#include "PhysicalMemory.h"
PhysicalMemory::PhysicalMemory() {
	capacity = 0;
}
PhysicalMemory::PhysicalMemory(int c) {
	capacity = 0;
}
void PhysicalMemory::setcapacity(int c) {
	capacity = c;
}
int PhysicalMemory::getcapacity() {
	return capacity;
}
void PhysicalMemory::display() {
	cout << "A physical memory of capacity: " << capacity << endl;
}
