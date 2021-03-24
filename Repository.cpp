#include "Repository.h"

void Repository::addEmployee(Employee& employee)
{
	employees.add(employee.getCNP(), employee);
}

void Repository::deleteEmployee(int CNP)
{
	employees.remove(CNP);
}

void Repository::updateEmployee(Employee& newEmployee)
{
	employees.add(newEmployee.getCNP(), newEmployee);
}
