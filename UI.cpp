#include "UI.h"

void UI::addEmployee()
{
	int CNP, salary;
	string name, departament;
	cout << "CNP of the employee: ";
	cin >> CNP;
	cout << "Name of the employee: ";
	cin >> name;
	cout << "Salary of the employee: ";
	cin >> salary;
	cout << "Departament of the employee: ";
	cin >> departament;

	contrl.addEmployee(CNP, name, salary, departament);
}

void UI::deleteEmployee()
{
	int CNP;
	cout << "Give the CNP of the employee u want to delete: ";
	cin >> CNP;
	contrl.deleteEmployee(CNP);
}

void UI::updateEmployee()
{
	int CNP, salary;
	string name, departament;
	cout << "CNP of the employee: ";
	cin >> CNP;
	cout << "New name for the employee: ";
	cin >> name;
	cout << "New salary of the employee: ";
	cin >> salary;
	cout << "New departament of the employee: ";
	cin >> departament;

	contrl.updateEmployee(CNP, name, salary, departament);
}

void UI::listEmployees()
{
	Map& employees = contrl.getAll();
	MapIterator iterator = employees.iterator();
	while (iterator.valid())
	{
		cout << iterator.getCurrent().second;
		iterator.next();
	}
}

void UI::StartProgram()
{
	cout << "Hello and welcome to the employees manager. Select an option from below: \n";
	
	while (1)
	{
		int command;
		cout << "1.Add an employee\n";
		cout << "2.Delete an employee\n";
		cout << "3.Update an employee\n";
		cout << "4.List all employees\n";
		cout << "5.Search by departament\n";
		cout << "6. Exit\n";
		cin >> command;
		if (command == 1)
			addEmployee();
		else if (command == 2)
			deleteEmployee();
		else if (command == 3)
			updateEmployee();
		else if (command == 4)
			listEmployees();
		else if (command == 5)
			listDepartament();
		else if (command == 6)
			break;
		else
			cout << "Bad command!\n";
	}
}

void UI::listDepartament()
{
	Map& employees = contrl.getAll();
	MapIterator iterator = employees.iterator();
	string departament;
	cout << "Give departament: ";
	cin >> departament;
	while (iterator.valid())
	{
		if(iterator.getCurrent().second.getDepartament() == departament)
			cout << iterator.getCurrent().second;
		iterator.next();
	}
}
