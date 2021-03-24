#pragma once


#include "Repository.h"

class Controller {
private:
	Repository& repo;


public:
	Controller(Repository& repo);

	void addEmployee(int CNP, string name, int salary, string departament);
	void deleteEmployee(int CNP);
	void updateEmployee(int CNP, string newName, int newSalary, string newDepartament);

	Map& getAll();
};