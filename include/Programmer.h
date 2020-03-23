#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <Employee.h>

class Programmer : public Employee, public EmployeeInterface
{
    public:
        Programmer();

        Programmer(std::string fullName, std::string address, std::string PIN, std::string startDate, std::string leader,
                 Position position, std::string projectName);

        virtual ~Programmer();
        void printToStream(std::ostream& ostr);
        void setProjectName(const std::string& name);
        std::string getProjectName() const;
        std::list<std::string> getCustomerEmails(); // read cpp
        void setCustomerEmails(const std::list<std::string>& emails);

    protected:
       virtual Employee* clone_impl() const override {return new Programmer(*this); };;

    private:
        std::string projectName;

};

std::ostream& operator << (std::ostream& ostr, Programmer programmer);

#endif // PROGRAMMER_H
