#include "Domain.h"

Employee::Employee()
{

	this->CNP = -11111;
	this->name = "";
	this->salary = -11111;
	this->departament = "";
}

Employee::Employee(int CNP, string name, int salary, string departament)
{
	this->CNP = CNP;
	this->name = name;
	this->salary = salary;
	this->departament = departament;
}

Employee& Employee::operator=(const Employee& other) 
{
	this->CNP = other.CNP;
	this->name = other.name;
	this->salary = other.salary;
	this->departament = other.departament;
	return *this;
}

bool Employee::operator==(const Employee& other) const
{
	if (this->CNP == other.CNP && this->name == other.name && this->salary == other.salary && this->departament == other.departament)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& ostream, const Employee& employee)
{
	ostream << employee.CNP << "  " << employee.name << "  " << employee.salary << "  " << employee.departament << '\n';
	return ostream;
}
