#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include <list>
#include <memory>
#include <Employee.h>

using namespace std;




class MenuHandler
{
    public:
        MenuHandler();
        virtual ~MenuHandler();
        static void printMenu(bool isFirstTime);
        static void handleMenu(list<unique_ptr<Squad>>& squads, list<unique_ptr<Employee>>& printableList);
        static void handleExceptions();


    protected:

    private:
};

#endif // MENUHANDLER_H
