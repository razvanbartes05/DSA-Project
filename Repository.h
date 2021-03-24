#pragma once
#include "Domain.h"
#include "Map.h"
#include "MapIterator.h"

class Repository {
private:
	Map employees{};

public:
	Repository() {};
	void addEmployee(Employee& employee);
	void deleteEmployee(int CNP);
	void updateEmployee(Employee& newEmployee);

	Map& getAllEmployees() { return employees; };
}; 