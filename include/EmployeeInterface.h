#ifndef EMPLOYEEINTERFACE_H
#define EMPLOYEEINTERFACE_H

#include <iostream>
#include <memory>
#include <list>

using namespace std;


class EmployeeInterface
{
    public:
        EmployeeInterface();
        virtual ~EmployeeInterface();

        virtual void printToStream(ostream& ostr) = 0;
        virtual void setProjectName(const string& name) = 0;
        virtual void setCustomerEmails(const list<string>& emails) = 0;
        virtual list<string> getCustomerEmails() = 0;

        auto clone() const {return unique_ptr<EmployeeInterface>(clone_impl()); };

    protected:

        virtual EmployeeInterface* clone_impl() const = 0;

        /* I must have a way to clone the instance since I am working with smart pointers quite often
        and there is no constructor to call when I want to make an instance from a unique pointer
        */

    private:
};

#endif // EMPLOYEEINTERFACE_H
