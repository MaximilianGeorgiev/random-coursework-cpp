#include <iostream>
#include <Employee.h>
#include <Analyzer.h>
#include <vector>
#include <ConsoleHandler.h>
#include <MenuHandler.h>
#include <list>
#include <iterator>
#include <memory>


int main()
{
    ConsoleHandler consoleHandler;


    list<std::unique_ptr<Employee>> employees;
    list<std::unique_ptr<Squad>> squads;
    MenuHandler::handleMenu(squads, employees);

    system("pause");
    return 0;
}
