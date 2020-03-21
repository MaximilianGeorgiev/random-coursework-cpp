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

using namespace std;

ConsoleHandler::ConsoleHandler()
{
    //ctor
}

ConsoleHandler::~ConsoleHandler()
{
    //dtor
}


list<unique_ptr<Employee>> ConsoleHandler::readInput()
{

    // unique pointers so I can use runtime polymorphism and access virtual methods in derived classes
    list<unique_ptr<Employee>> employeeList;
    int employeesFilled = 0;
    string currentInput;

    cout << "Please input information about the company. \n";
    cout << "You will have to input more than one worker(s). The input continues until \"END\" is received. \n";

    while (currentInput != "END"){
        addEmployee(employeeList);
        employeesFilled++;
        cin >> currentInput;
    }

    return employeeList;
}

 void ConsoleHandler::print(const list<unique_ptr<Employee>>& printableList){
    for (const auto& it : printableList)   cout << *it << string(" ");
}

 void ConsoleHandler::addEmployee(list<unique_ptr<Employee>>& printableList){
        string currentInput, positionName, employeeName, employeeAddress, employeePIN, employeeLeader, employeeStartDate;
        int positionLevel;

        cout << "Please input this employee's position: (programmer, analyzer, lead) -- they are case sensitive \n";
        cin >> positionName;

        // can be improved with regex
        // white spaces not trimmed
        while (positionName != "programmer" && positionName != "analyzer" && positionName != "lead"){
            cout << "The position is invalid. Please try again. \n";
            cin >> positionName;
        }

        cout << "Please input this employee's position level: \n ";
        cin >> positionLevel;

        cout << "Please input this employee's full name: \n";
        cin >> employeeName;

        cout << "Please input this employee's address: \n";
        cin >> employeeAddress;

        cout << "Please input this employee's PIN: \n";
        cin >> employeePIN;

        cout << "Please input this employee's start date: \n";
        cin >> employeeStartDate;

        cout << "Please input this employee's leader: \n";
        cin >> employeeLeader;

        Position position(positionName, positionLevel);

        string projectName, customerEmail;
        list<string> analyzer_customerEmails;

        if (position.getPositionName() == "programmer"){
            cout << "Please input the project's name this programmer is working on: \n";
            cin >> projectName;

            printableList.emplace_back(make_unique<Programmer>(employeeName, employeeAddress, employeePIN, employeeStartDate,
                             employeeLeader, position, projectName));
           // employeeList.emplace_back(Programmer(employeeName, employeeAddress, employeePIN, employeeStartDate, employeeLeader, position, projectName));
        } else if (position.getPositionName() == "analyzer"){
            cout << "Please input the project's name this analyzer is working on: \n";
            cin >> projectName;

            cout << "Please input the customers' emails. The iteration continues until \"END\" is inputted. \n";
            cin >> customerEmail;

            while (customerEmail != "END"){
                analyzer_customerEmails.emplace_back(string(customerEmail));
                cin >> customerEmail;
            }

            printableList.emplace_back(make_unique<Analyzer>(employeeName, employeeAddress, employeePIN, employeeStartDate,
                              employeeLeader, position, projectName, analyzer_customerEmails));

           // employeeList.emplace_back(Analyzer(employeeName, employeeAddress, employeePIN, employeeStartDate,
                           //   employeeLeader, position, projectName, analyzer_customerEmails));
        }

 }

void ConsoleHandler::printEmployeeInfo(const list<unique_ptr<Employee>>& printableList, const string& name){
    for (const auto& it : printableList){
        if (it->getFullName() == name) {
            cout << *it << string(" ");
            return;
        }
    }
    cout << "Unable to find username";
}

void ConsoleHandler::sackEmployee(list<unique_ptr<Employee>>& printableList, const string& name){
     for (const auto& it : printableList){
        if (it->getFullName() == name) {
            printableList.remove(it);
            return;
        }
    }

    cout << "Unable to find username";
}

void ConsoleHandler::printEmployeesByPosition(const list<unique_ptr<Employee>>& printableList, const string& pos){
        for (const auto& it : printableList){
         if (it->getPositionName() == pos) {
            cout << *it << string(" ");
        }
    }
}

void ConsoleHandler::changeEmployeeInfo(Employee& employee, const string& modify_field, const string& modify_value){
    // thank you C++ for not supporting switch case for strings
    if (modify_field == "name") employee.setFullName(modify_value);
    else if (modify_field == "address") employee.setAddress(modify_value);
    else if (modify_field == "PIN") employee.setPIN(modify_value);
    else if (modify_field == "startDate") employee.setStartDate(modify_value);
    else if (modify_field == "leader") employee.setLeader(modify_value);
    else if (modify_field == "position"){
        int posLevel;
        cout << "Please input position level: ";
        cin >> posLevel;

        employee.setPosition(Position(modify_field, posLevel));
    }

    else if (modify_field == "project"){
        // could throw exception depending whether its derived or base class
        employee.setProjectName(modify_value);
    } else if (modify_field == "email"){
        string action;
        cin >> action;
        cout << "Would you like to remove or add emails or modify existing emails? Input ADD or REMOVE or MODIFY \n";


        // kind of memory consuming to create a new instance rather than use a pointer; might fix later
        list<string> customers = employee.getCustomerEmails();
        customers.emplace_back(modify_value);

        if (action == "ADD") customers.emplace_back(modify_value);
        else if (action == "REMOVE") customers.remove(modify_value);
        else if (action == "MODIFY") {
            string newValue;
            cout << "Please add the new value for " << modify_value << "\n";

            /* we need to grab the index of the value, remove it and insert the new one at this index, but we won't be doing
            it at this point */
            customers.remove(modify_value);
            customers.emplace_back(newValue);
        }

        employee.setCustomerEmails(customers);
    }
}

void ConsoleHandler::createSquad(list<unique_ptr<Squad>>& squads, const list<unique_ptr<Employee>>& printableList){
    string squadName, leaderName, projectName;
    list<Lead> empsToAdd;
    bool isLeaderValid = false;
    bool isCurrentEmployeeValid = false;

    cout << "Please input the name of the squad: \n";
    cin >> squadName;

    cout << "Please input the name of the leader: \n";
    cin >> leaderName;


    /*
        1. Iterate through all employees to find whether the leader is an active employee.
        2. Iterate with an inner cycle through all employees again to see whether the employee we are adding is
        already inside a squad (every employee can have one squad only)

    */


   for (const auto& it : printableList){
    if (it->getFullName() == leaderName){
        isLeaderValid = true;
        cout << "Please input the name of the project: \n";
        cin >> projectName; // no check to see if it's valid

        string inputNext, employeeName;
        cout << "Press any key to continue. \n";
        cin >> inputNext;

        while (inputNext != "END"){
            cout << "Please input the name of the employees in this squad. Filling continues until END is submitted.";
            cin >> employeeName;

            for (const auto& it2 : printableList){
                if (it2 != it && it2->getFullName() == employeeName && it2->getSquadName() != ""){
                    isCurrentEmployeeValid = true;
                    Employee emp = *it2;
                    empsToAdd.emplace_back(emp);
                }
            }

            if (!isCurrentEmployeeValid) {
                cout << "Unable to find an Employee with such name. Please try again. \n";
                continue;
            }

            cin >> inputNext;
        }

        list<Employee> newList;

        for (auto it : empsToAdd){
            newList.emplace_back((Employee)it);
        }

        Squad squad = Squad(squadName, **&it,
                             projectName, empsToAdd);
        squads.emplace_back(make_unique<Squad>(squad));
    }
   }

   if (!isLeaderValid) cout << "Unable to find an employee with such name. \n";
}

void ConsoleHandler::changeEmployeeSquad(list<unique_ptr<Squad>>& squads, list<unique_ptr<Employee>>& employees){
    string employeeName, newSquad;
    bool isSquadValid;

    cout << "Please input the name of the employee you would like to change the squad of: \n";
    cin >> employeeName;

    for (const auto& empIterator : employees) {
        if (empIterator->getFullName() == employeeName){
             cout << "Please input the name of the squad you would like this employee to receive: \n";
             cin >> newSquad;

             for (const auto& squadIterator : squads){
                if (squadIterator->getSquadName() == newSquad){
                    isSquadValid = true;
                    empIterator->setSquad(*squadIterator);
                }
             }
        }
    }

    if (!isSquadValid) cout << "Invalid name of squad. \n";
}

void ConsoleHandler::printSquads(list<unique_ptr<Squad>>& squads){
    for (const auto& it : squads){
        cout << it->getSquadName() << "\n";
        cout << it->getLeaderName() << "\n";
        cout << it->getProject() << "\n";

        cout << "Employees: \n";

        for (const auto& emp : it->getEmployees()){
            cout << emp.getFullName() << "\n";
        }

        cout << "\n";
    }
}
