#pragma once
#include <iostream>

using namespace std;


class Employee {
private:
	string name;
	int CNP;
	int salary;
	string departament;

public:
	Employee();
	Employee(int CNP, string name, int salary, string departament);
	string getName() { return name; };
	string getDepartament() { return departament; };
	int getSalary() { return salary; };
	int getCNP() { return CNP; };
	
	Employee& operator=(const Employee& other) ;
	bool operator==(const Employee& other) const;
	friend std::ostream& operator<<(std::ostream& ostream, const Employee& employee);


};