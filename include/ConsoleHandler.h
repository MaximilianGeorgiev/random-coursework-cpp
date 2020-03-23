#ifndef CONSOLEHANDLER_H
#define CONSOLEHANDLER_H

#include <Employee.h>
#include <Squad.h>
#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <memory>

/* ConsoleHandler methods can be private and make an instance of the class to improve encapsulation but idk */
class ConsoleHandler
{
    public:
        ConsoleHandler();
        virtual ~ConsoleHandler();

        static std::list<std::unique_ptr<Employee>> readInput();
        static void print(const std::list<std::unique_ptr<Employee>>& printableList);
        static void addEmployee(std::list<std::unique_ptr<Employee>>& printableList);
        static void printEmployeeInfo(const std::list<std::unique_ptr<Employee>>& printableList, const std::string& name);
        static void sackEmployee(std::list<std::unique_ptr<Employee>>& printableList, const std::string& name);
        static void printEmployeesByPosition(const std::list<std::unique_ptr<Employee>>& printableList, const std::string& pos);
        static void changeEmployeeInfo(Employee& employee,
                                       const std::string& modifiable_field, const std::string& modify_value);

        static void createSquad(std::list<std::unique_ptr<Squad>>& squads, const std::list<std::unique_ptr<Employee>>& printableList);
        static void changeEmployeeSquad(std::list<std::unique_ptr<Squad>>& squads, std::list<std::unique_ptr<Employee>>& employee);
        static void deleteSquad(std::list<std::unique_ptr<Squad>>& squads, std::list<std::unique_ptr<Employee>>& employee);
        static void printSquads(std::list<std::unique_ptr<Squad>>& squads);

    protected:

    private:
};

#endif // CONSOLEHANDLER_H
