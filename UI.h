#pragma once

#include "Controller.h"

class UI {
private:
	Controller& contrl;

public:
	UI(Controller& control) : contrl{ control } {}
	void addEmployee();
	void deleteEmployee();
	void updateEmployee();
	void listEmployees();
	void StartProgram();
	void listDepartament();

};