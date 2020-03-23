#include <Employee.h>
#include <Position.h>
#include <Squad.h>
#include "fwddeclare-squad.h"
#include "fwddeclare-emp.h"

Employee::Employee()
{
    fullName = "Pesho";
    address = "TU";
    PIN = "taina";
    startDate = "01/01/2011";
    leader = "Durtiq petrakis";
    position = Position();
    squad = " ";
}

Employee::Employee(std::string i_name, std::string i_address, std::string i_PIN, std::string i_startDate, std::string i_leader,
                 Position i_position)
                 : fullName(std::move(i_name)), address(std::move(i_address)), PIN(std::move(i_PIN)),
                 startDate(std::move(i_startDate)), leader(std::move(i_leader)), position(std::move(i_position)), squad(" ")
{
    //testing this type of constructor for vector.push_back
}

// access modifiers work on class level rather than object level hence why they had to be public
// bb encapsulation
void Employee::setFullName(const std::string& name){
    this->fullName = name;
}

void Employee::setAddress(const std::string& address){
    this->address = address;
}

void Employee::setPIN(const std::string& PIN){
    this->PIN = PIN;
}

void Employee::setStartDate(const std::string& startDate){
    this->startDate = startDate;
}

void Employee::setLeader(const std::string& leader){
    this->leader = leader;
}

void Employee::setPosition(const Position& pos){
    this->position = pos;
}

void Employee::setSquad(const std::string& squad){
    this->squad = squad;
}

std::string Employee::getFullName() const {
    return this->fullName;
}

std::string Employee::getAddress() const {
    return this->address;
}

std::string Employee::getPIN() const {
    return this->PIN;
}

std::string Employee::getStartDate() const {
    return this->startDate;
}

std::string Employee::getLeader() const {
    return this->leader;
}

Position Employee::getPositionInfo() const {
    return this->position;
}

std::string Employee::getPositionName() const {
    return this->getPositionInfo().getPositionName();
}

std::string Employee::getSquad() const {
    return this->squad;
}


// inherited from interface, they have to be implemented otherwise this is an abstract class
// bad design
void Employee::setCustomerEmails(const std::list<std::string>& emails){}

void Employee::setProjectName(const std::string& projectName){}

std::list<std::string> Employee::getCustomerEmails() {}


 void Employee::printToStream(std::ostream& ostr)  {
    ostr << this->getFullName() << std::string(" ") << this->getAddress() << std::string(" ") << this->getPIN()
     << std::string(" ")  << this->getStartDate() << std::string(" ")  << this->getLeader() << std::string(" ")
     << this->getPositionName() << std::string("\n");
}

std::ostream& operator << (std::ostream& ostr,  Employee& analyzer) {
     analyzer.printToStream(ostr);
     return ostr;
}
