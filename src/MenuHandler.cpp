#include "MenuHandler.h"
#include <ConsoleHandler.h>
#include <Squad.h>
#include <iostream>
#include <list>
#include <memory>

MenuHandler::MenuHandler()
{
    //ctor
}

MenuHandler::~MenuHandler()
{
    //dtor
}

void MenuHandler::printMenu(bool isFirstTime){
    if (isFirstTime){
        std::cout << "Welcome to the company organization program. You are given the following options: \n";
    } else {
        std::cout << "Welcome back. Please select your next action: \n";
    }
        std::cout << "1. Add an employee \n";
        std::cout << "2. Print employee information (searching by name) \n";
        std::cout << "3. Sack an employee \n";
        std::cout << "4. Print employees (search by position name) \n";
        std::cout << "5. Change employee information \n";
        std::cout << "6. Create new squad \n";
        std::cout << "7. Change employee squad \n";
        std::cout << "8. Delete existing squad \n";
        std::cout << "9. Print squads \n";
}

void MenuHandler::handleMenu(std::list<std::unique_ptr<Squad>>& squads, std::list<std::unique_ptr<Employee>>& employees) {
    printMenu(true);

    int selection;
    std::string name;

    std::cin >> selection;

    while (selection != 0){

    std::cout << "You have chosen option Number #" << selection << std::endl;

    switch (selection){
    case 1:
        {
        ConsoleHandler::addEmployee(employees);
        break;
        }
    case 2:
        {
        std::cout << "Please provide a name to search for: \n";
        std::cin >> name;
        ConsoleHandler::printEmployeeInfo(employees, name);
        break;
        }
    case 3:
        {
        std::cout << "Please provide the name of the employee to sack: \n";
        std::cin >> name;
        ConsoleHandler::sackEmployee(employees, name);
        break;
        }
    case 4:
        {
        std::cout << "Please provide the position name to search for: \n";
        std::cin >> name;
        ConsoleHandler::printEmployeesByPosition(employees, name);
        break;
        }
    case 5:
        {
        std::string modify_field, modify_value;

        std::cout << "Please provide the name of the employee whose info you would like to change: \n";
        std::cin >> name;

        std::cout << "Please provide the field you would like to change: \n";
        std::cin >> modify_field;

        std::cout << "Please provide the value you would like this field to receive: \n";
        std::cin >> modify_value;

        for (auto& it : employees) {
            if (it->getFullName() == name) {
               ConsoleHandler::changeEmployeeInfo(**&it, modify_field, modify_value);
               break;
            }
        }

        std::cout << "Unable to find a user with that name. \n";
        break;
        }
    case 6:
    {
        std::cout << "You have chosen to create a squad. \n";
        ConsoleHandler::createSquad(squads, employees);
        break;
    }

    case 7:
    {
        std::cout << "You have chosen to change the squad of an employee. \n";
        ConsoleHandler::changeEmployeeSquad(squads, employees);
        break; //
    }

    case 8:
    {
        std::cout << "You have chosen to delete a squad. \n";
        ConsoleHandler::deleteSquad(squads, employees);
        break;
    }

    case 9:
    {
        std::cout << "You have chosen to print the squads: \n";
        ConsoleHandler::printSquads(squads);
        break;
    }
    default:
        break;
    }

    printMenu(false);
    std::cin >> selection;
   }
}
