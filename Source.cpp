#include "UI.h"
#include <cassert>

void testmap();

int main()
{
	testmap();
	Repository repo;
	Controller controller{ repo };
	UI ui{ controller };
	ui.StartProgram();
}

void testmap()
{
	Repository repo;
	Employee e1{1,"sas",2,"ddd"};
	repo.addEmployee(e1);
	assert(repo.getAllEmployees().size() == 1);
	repo.deleteEmployee(1);
	assert(repo.getAllEmployees().size() == 0);
}