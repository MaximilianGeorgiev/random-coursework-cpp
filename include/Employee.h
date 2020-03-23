#pragma once
#include <iosfwd>
#include <fwddeclare-emp.h>
#include <fwddeclare-squad.h>

#include <Position.h>
#include <EmployeeInterface.h>
#include <Squad.h>
#include <string>
#include <list>
#include <memory>


/*
Initially this class had pure virtual methods but afterwards due to it being abstract and
being unable to make an instance, I had to create a base class (EmployeeInterface) containing virtual
methods only. Besides, it made no sense being a class with fields constructors etc. and non-virtual methods;
showed bad practice


Current hierarchy is still bad though because all classes implement all virtual methods even though they are not needed
everywhere. But who cares.

include\Analyzer.h|13|warning: direct base 'EmployeeInterface' inaccessible in 'Analyzer' due to ambiguity|
Seems like once it was once written in Employee, the later implementation in Analyzer is not used??
Even though this makes no sense. Will possibly address.
*/

class Employee : public EmployeeInterface
{
    public:
        std::unique_ptr<EmployeeInterface> empPtr;

        Employee();
        Employee(const Employee& otherEmp) : empPtr(otherEmp.empPtr->clone()) {}

        Employee(Employee&& other) = default;
        Employee& operator = (const Employee& emp) {empPtr = emp.empPtr->clone(); return *this; }
        Employee& operator = (Employee&& emp) = default;

        ~Employee() = default;

        //copying constructor used by vector.push_back
        Employee(std::string fullName, std::string address, std::string PIN, std::string startDate, std::string leader,
               Position position);

        void printToStream(std::ostream& ostr);
        void setProjectName(const std::string& name);
        void setCustomerEmails(const std::list<std::string>& emails);
        std::list<std::string> getCustomerEmails();

        void setFullName(const std::string& name);
        void setAddress(const std::string& address);
        void setPIN(const std::string& PIN);
        void setStartDate(const std::string& startDate);
        void setLeader(const std::string& leader);
        void setPosition(const Position& pos);
        void setSquad(const std::string& squad);
        std::string getFullName() const;
        std::string getAddress() const;
        std::string getPIN() const;
        std::string getStartDate() const;
        std::string getLeader() const;
        Position getPositionInfo() const;
        std::string getPositionName() const;
        std::string getSquad() const;
        std::string getSquadName() const;

    protected:
        virtual Employee* clone_impl() const override { return new Employee(*this); };

    private:
        std::string fullName, address, PIN, startDate, leader;
        Position position;
        std::string squad;
        /*
         as much as I hate working with pointers it is inevitable
        // circular dependancies throws runtime errors
        // to reverse order of the classes so the “used” class is defined before the class that uses it
        // we will use pointers for the squad here and the leader employee in squad

        */
};

// being passed as reference only, otherwise operator attempts to create new instance and eveything fails
// also cannot be passed as a const for whatever reason
std::ostream& operator << (std::ostream& ostr,  Employee& emp);

