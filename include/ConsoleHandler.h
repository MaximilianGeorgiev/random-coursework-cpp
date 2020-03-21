#ifndef CONSOLEHANDLER_H
#define CONSOLEHANDLER_H

#include <Employee.h>
#include <Squad.h>
#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class ConsoleHandler
{
    public:
        ConsoleHandler();
        virtual ~ConsoleHandler();

        static list<unique_ptr<Employee>> readInput();
        static void print(const list<unique_ptr<Employee>>& printableList);
        static void addEmployee(list<unique_ptr<Employee>>& printableList);
        static void printEmployeeInfo(const list<unique_ptr<Employee>>& printableList, const string& name);
        static void sackEmployee(list<unique_ptr<Employee>>& printableList, const string& name);
        static void printEmployeesByPosition(const list<unique_ptr<Employee>>& printableList, const string& pos);
        static void changeEmployeeInfo(Employee& employee,
                                       const string& modifiable_field, const string& modify_value);

        static void createSquad(list<unique_ptr<Squad>>& squads, const list<unique_ptr<Employee>>& printableList);
        static void changeEmployeeSquad(list<unique_ptr<Squad>>& squads, list<unique_ptr<Employee>>& employee);
        static void deleteSquad(const string& name, list<unique_ptr<Squad>>& squads);
        static void printSquads(list<unique_ptr<Squad>>& squads);

    protected:

    private:
};

#endif // CONSOLEHANDLER_H
