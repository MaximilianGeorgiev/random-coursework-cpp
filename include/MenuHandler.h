#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include <list>
#include <memory>
#include <Employee.h>

class MenuHandler
{
    public:
        MenuHandler();
        virtual ~MenuHandler();
        static void printMenu(bool isFirstTime);
        static void handleMenu(std::list<std::unique_ptr<Squad>>& squads, std::list<std::unique_ptr<Employee>>& printableList);
        static void handleExceptions();

    protected:

    private:
};

#endif // MENUHANDLER_H
