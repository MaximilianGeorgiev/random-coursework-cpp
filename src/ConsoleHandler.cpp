#include "ConsoleHandler.h"
#include <iostream>
#include <Position.h>
#include <Programmer.h>
#include <Analyzer.h>
#include <Lead.h>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>

ConsoleHandler::ConsoleHandler()
{
    //ctor
}

ConsoleHandler::~ConsoleHandler()
{
    //dtor
}


std::list<std::unique_ptr<Employee>> ConsoleHandler::readInput()
{
    // unique pointers so I can use runtime polymorphism and access virtual methods in derived classes
    std::list<std::unique_ptr<Employee>> employeeList;
    int employeesFilled = 0;
    std::string currentInput;

    std::cout << "Please input information about the company. \n";
    std::cout << "You will have to input more than one worker(s). The input continues until \"END\" is received. \n";

    while (currentInput != "END"){
        addEmployee(employeeList);
        employeesFilled++;
        std::cin >> currentInput;
    }

    return employeeList;
}

 void ConsoleHandler::print(const std::list<std::unique_ptr<Employee>>& printableList){
    for (const auto& it : printableList)   std::cout << *it << std::string(" ");
}

 void ConsoleHandler::addEmployee(std::list<std::unique_ptr<Employee>>& printableList){
        std::string currentInput, positionName, employeeName, employeeAddress, employeePIN, employeeLeader, employeeStartDate;
        int positionLevel;

        std::cout << "Please input this employee's position: (programmer, analyzer, lead) -- they are case sensitive \n";
        std::cin >> positionName;

        // can be improved with regex
        // white spaces not trimmed
        while (positionName != "programmer" && positionName != "analyzer" && positionName != "lead"){
            std::cout << "The position is invalid. Please try again. \n";
            std::cin >> positionName;
        }

        std::cout << "Please input this employee's position level: \n ";
        std::cin >> positionLevel;

        std::cout << "Please input this employee's full name: \n";
        std::cin >> employeeName;

        std::cout << "Please input this employee's address: \n";
        std::cin >> employeeAddress;

        std::cout << "Please input this employee's PIN: \n";
        std::cin >> employeePIN;

        std::cout << "Please input this employee's start date: \n";
        std::cin >> employeeStartDate;

        std::cout << "Please input this employee's leader: \n";
        std::cin >> employeeLeader;

        Position position(positionName, positionLevel);

        std::string projectName, customerEmail;
        std::list<std::string> analyzer_customerEmails;

        if (position.getPositionName() == "programmer"){
            std::cout << "Please input the project's name this programmer is working on: \n";
            std::cin >> projectName;

            printableList.emplace_back(std::make_unique<Programmer>(employeeName, employeeAddress, employeePIN, employeeStartDate,
                             employeeLeader, position, projectName));
           // employeeList.emplace_back(Programmer(employeeName, employeeAddress, employeePIN, employeeStartDate, employeeLeader, position, projectName));
        } else if (position.getPositionName() == "analyzer" || position.getPositionName() == "lead"){
            std::cout << "Please input the project's name this analyzer is working on: \n";
            std::cin >> projectName;

            std::cout << "Please input the customers' emails. The iteration continues until \"END\" is inputted. \n";
            std::cin >> customerEmail;

            while (customerEmail != "END"){
                analyzer_customerEmails.emplace_back(std::string(customerEmail));
                std::cin >> customerEmail;
            }

            printableList.emplace_back(std::make_unique<Analyzer>(employeeName, employeeAddress, employeePIN, employeeStartDate,
                              employeeLeader, position, projectName, analyzer_customerEmails));
        }
 }

void ConsoleHandler::printEmployeeInfo(const std::list<std::unique_ptr<Employee>>& printableList, const std::string& name){
    for (const auto& it : printableList){
        if (it->getFullName() == name) {
            std::cout << *it << std::string(" ");
            return;
        }
    }
    std::cout << "Unable to find username";
}

void ConsoleHandler::sackEmployee(std::list<std::unique_ptr<Employee>>& printableList, const std::string& name){
     for (const auto& it : printableList){
        if (it->getFullName() == name) {
            printableList.remove(it);
            return;
        }
    }

    std::cout << "Unable to find username";
}

void ConsoleHandler::printEmployeesByPosition(const std::list<std::unique_ptr<Employee>>& printableList, const std::string& pos){
        for (const auto& it : printableList){
         if (it->getPositionName() == pos) {
            std::cout << *it << std::string(" ");
        }
    }
}

void ConsoleHandler::changeEmployeeInfo(Employee& employee, const std::string& modify_field, const std::string& modify_value){
    // thank you C++ for not supporting switch case for strings
    if (modify_field == "name") employee.setFullName(modify_value);
    else if (modify_field == "address") employee.setAddress(modify_value);
    else if (modify_field == "PIN") employee.setPIN(modify_value);
    else if (modify_field == "startDate") employee.setStartDate(modify_value);
    else if (modify_field == "leader") employee.setLeader(modify_value);
    else if (modify_field == "position"){
        int posLevel;
        std::cout << "Please input position level: ";
        std::cin >> posLevel;

        employee.setPosition(Position(modify_field, posLevel));
    }

    else if (modify_field == "project"){
        // could throw exception depending whether its derived or base class
        employee.setProjectName(modify_value);
    } else if (modify_field == "email"){
        std::string action;
        std::cin >> action;
        std::cout << "Would you like to remove or add emails or modify existing emails? Input ADD or REMOVE or MODIFY \n";

        // kind of memory consuming to create a new instance rather than use a pointer; might fix later
        std::list<std::string> customers = employee.getCustomerEmails();
        customers.emplace_back(modify_value);

        if (action == "ADD") customers.emplace_back(modify_value);
        else if (action == "REMOVE") customers.remove(modify_value);
        else if (action == "MODIFY") {
            std::string newValue;
            std::cout << "Please add the new value for " << modify_value << "\n";

            /* we need to grab the index of the value, remove it and insert the new one at this index, but we won't be doing
            it at this point */
            customers.remove(modify_value);
            customers.emplace_back(newValue);
        }

        employee.setCustomerEmails(customers);
    }
}

void ConsoleHandler::createSquad(std::list<std::unique_ptr<Squad>>& squads, const std::list<std::unique_ptr<Employee>>& printableList){
    std::string squadName, leaderName, projectName;
    std::list<std::string> empsToAdd;
    bool isLeaderValid = false;
    bool isCurrentEmployeeValid = false;

    std::cout << "Please input the name of the squad: \n";
    std::cin >> squadName;

    std::cout << "Please input the name of the leader: \n";
    std::cin >> leaderName;

    /*
        1. Iterate through all employees to find whether the leader is an active employee.
        2. Iterate with an inner cycle through all employees again to see whether the employee we are adding is
        already inside a squad (every employee can have one squad only)

    */

   for (auto& it : printableList){
    if (it->getFullName() == leaderName){
        isLeaderValid = true;
        std::cout << "Please input the name of the project: \n";
        std::cin >> projectName; // no check to see if it's valid

        std::string inputNext, employeeName;
        std::cout << "Press any key to continue. \n";
        std::cin >> inputNext;

        while (inputNext != "END"){
            std::cout << "Please input the name of the employees in this squad. Filling continues until END is submitted.";
            std::cin >> employeeName;

            for (auto& it2 : printableList){
                if (it2 != it && it2->getFullName() == employeeName && it2->getSquad() != ""){
                    isCurrentEmployeeValid = true;
                    empsToAdd.emplace_back(it2->getFullName());
                }
            }

            if (!isCurrentEmployeeValid) {
                std::cout << "Unable to find an Employee with such name. Please try again. \n";
                continue;
            }

            std::cin >> inputNext;
        }

        Squad squad(projectName,
                     it->getFullName(),
                     projectName,
                      empsToAdd);

        squads.emplace_back(std::make_unique<Squad>(squad));
    }
   }

   if (!isLeaderValid) std::cout << "Unable to find an employee with such name. \n";
}

void ConsoleHandler::changeEmployeeSquad(std::list<std::unique_ptr<Squad>>& squads, std::list<std::unique_ptr<Employee>>& employees){
    std::string employeeName, newSquad;
    bool isSquadValid;

    std::cout << "Please input the name of the employee you would like to change the squad of: \n";
    std::cin >> employeeName;

    for (const auto& empIterator : employees) {
        if (empIterator->getFullName() == employeeName){
             std::cout << "Please input the name of the squad you would like this employee to receive: \n";
             std::cin >> newSquad;

             for (const auto& squadIterator : squads){
                if (squadIterator->getSquadName() == newSquad){
                    isSquadValid = true;
                    empIterator->setSquad(squadIterator->getSquadName());
                }
             }
        }
    }

    if (!isSquadValid) std::cout << "Invalid name of squad. \n";
}

void ConsoleHandler::deleteSquad(std::list<std::unique_ptr<Squad>>& squads, std::list<std::unique_ptr<Employee>>& employee){
    std::string squadToDelete;
    std::cout << "Please input the name of the squad you wish to delete: \n";

    std::cin >> squadToDelete;
    bool isSquadValid = false;

    for (const auto& sq : squads){
        if (sq->getSquadName() == squadToDelete){
            isSquadValid = true;
            squads.remove(sq);
        }
    }

    if (!isSquadValid) {
        std::cout << "Invalid name of squad. \n";
        return;
    }

    for (const auto& emp : employee){
        if (emp->getSquad() == squadToDelete){
            emp->setSquad("NOSQUAD");
        }
    }
}

void ConsoleHandler::printSquads(std::list<std::unique_ptr<Squad>>& squads){
    for (const auto& it : squads){
        std::cout << "Squad name: " << it->getSquadName() << "\n";
        std::cout << "Leader name " << it->getLeaderName() << "\n";
        std::cout << "Project name: " <<it->getProject() << "\n";

        std::cout << "Employees: \n";

        for (const auto& emp : it->getEmployees()){
            std::cout << emp << "\n";
        }
        std::cout << "\n";
    }
}
