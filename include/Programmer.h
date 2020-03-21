#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <Employee.h>

class Programmer : public Employee, public EmployeeInterface
{
    public:
        Programmer();


        /*
        Programmer(const string& fullName, const string& address,
                   const string& PIN, const string& startDate, const string& leader,
                   const Position& position, const string& projectName);

        */

        Programmer(string fullName, string address, string PIN, string startDate, string leader,
                 Position position, string projectName);

        virtual ~Programmer();
        void printToStream(ostream& ostr);
        void setProjectName(const string& name);
        string getProjectName() const;
        list<string> getCustomerEmails(); // read cpp
        void setCustomerEmails(const list<string>& emails);

    protected:
       virtual Employee* clone_impl() const override {return new Programmer(*this); };;

    private:
        string projectName;

};

std::ostream& operator << (std::ostream& ostr, Programmer programmer);

#endif // PROGRAMMER_H
