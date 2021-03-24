#include "Controller.h"

Controller::Controller(Repository& repo) : repo{ repo } {}

void Controller::addEmployee(int CNP, string name, int salary, string departament)
{
	Employee employee{ CNP, name, salary, departament };
	repo.addEmployee(employee);
}

void Controller::deleteEmployee(int CNP)
{
	repo.deleteEmployee(CNP);
}

void Controller::updateEmployee(int CNP, string newName, int newSalary, string newDepartament)
{
	Employee newEmployee{CNP, newName, newSalary, newDepartament};
	bool ok = false;
	Map& employees = repo.getAllEmployees();
	MapIterator iterator = employees.iterator();
	while (iterator.valid())
	{
		if (iterator.getCurrent().second.getCNP() == CNP)
			ok = true; break;
		iterator.next();
	}
	if (ok == true)
		repo.addEmployee(newEmployee);
	else
		cout << "No employee with that CNP\n";
}

Map& Controller::getAll()
{
	return repo.getAllEmployees();
}
