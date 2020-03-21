#include "MenuHandler.h"
#include <ConsoleHandler.h>
#include <Squad.h>
#include <iostream>
#include <list>
#include <memory>

using namespace std;

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
        cout << "Welcome to the company organization program. You are given the following options: \n";
    } else {
        cout << "Welcome back. Please select your next action: \n";
    }
        cout << "1. Add an employee \n";
        cout << "2. Print employee information (searching by name) \n";
        cout << "3. Sack an employee \n";
        cout << "4. Print employees (search by position name) \n";
        cout << "5. Change employee information \n";
        cout << "6. Create new squad \n";
        cout << "7. \n";
        cout << "8. \n";
        cout << "9. Print squads \n";
}

void MenuHandler::handleMenu(list<unique_ptr<Squad>>& squads, list<unique_ptr<Employee>>& employees) {
    printMenu(true);

    int selection;
    string name;

    cin >> selection;

    while (selection != 7){

    cout << "You have chosen option Number #" << selection << endl;

    switch (selection){
    case 1:
        {
        ConsoleHandler::addEmployee(employees);
        break;
        }
    case 2:
        {
        cout << "Please provide a name to search for: \n";
        cin >> name;
        ConsoleHandler::printEmployeeInfo(employees, name);
        break;
        }
    case 3:
        {
        cout << "Please provide the name of the employee to sack: \n";
        cin >> name;
        ConsoleHandler::sackEmployee(employees, name);
        break;
        }
    case 4:
        {
        cout << "Please provide the position name to search for: \n";
        cin >> name;
        ConsoleHandler::printEmployeesByPosition(employees, name);
        break;
        }
    case 5:
        {
        string modify_field, modify_value;

        cout << "Please provide the name of the employee whose info you would like to change: \n";
        cin >> name;

        cout << "Please provide the field you would like to change: \n";
        cin >> modify_field;

        cout << "Please provide the value you would like this field to receive: \n";
        cin >> modify_value;


        for (auto& it : employees) {
            if (it->getFullName() == name) {
               ConsoleHandler::changeEmployeeInfo(**&it, modify_field, modify_value);
               break;
            }
        }

        cout << "Unable to find a user with that name. \n";
        break;
        }
    case 6:
    {
        cout << "You have chosen to create a squad. \n";
        ConsoleHandler::createSquad(squads, employees);
        break;
    }

    case 7:
    {
        cout << "You have chosen to change the squad of an employee. \n";
        ConsoleHandler::changeEmployeeSquad(squads, employees);
        break; //
    }

    case 9:
    {
        cout << "You have chosen to print the squads: \n";
        ConsoleHandler::printSquads(squads);
        break;
    }
    default:
        break;
    }

    printMenu(false);
    cin >> selection;
   }
}
