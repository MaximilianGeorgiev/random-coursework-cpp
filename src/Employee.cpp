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
    squad = make_unique<Squad>();
}

/*
Employee::Employee(const Employee& emp)
{
    this->setFullName(emp.getFullName());
    this->setAddress(emp.getAddress());
    this->setPIN(emp.getPIN());
    this->setStartDate(emp.getStartDate());
    this->setPosition(emp.getPositionInfo());
    this->setSquad(emp.getSquad());
}
*/

Employee::Employee(const unique_ptr<Employee>& ptr)
{
    this->setFullName(ptr->getFullName());
    this->setAddress(ptr->getAddress());
    this->setPIN(ptr->getPIN());
    this->setStartDate(ptr->getStartDate());
    this->setPosition(ptr->getPositionInfo());
    this->setSquad(ptr->getSquad());
}

/*
Employee::Employee(const string& fullName, const string& address, const string& PIN,
                   const string& startDate, const string& leader,
                   const Position& position){
    setFullName(fullName);
    setAddress(address);
    setPIN(PIN);
    setStartDate(startDate);
    setLeader(leader);
    setPosition(position);
}

*/


Employee::Employee(string i_name, string i_address, string i_PIN, string i_startDate, string i_leader,
                 Position i_position)
                 : fullName(move(i_name)), address(move(i_address)), PIN(move(i_PIN)),
                 startDate(move(i_startDate)), leader(move(i_leader)), position(move(i_position)), squad(new Squad())
{
    //testing this type of constructor for vector.push_back
}



// access modifiers work on class level rather than object level hence why they had to be public
// bb encapsulation
void Employee::setFullName(const string& name){
    this->fullName = name;
}

void Employee::setAddress(const string& address){
    this->address = address;
}

void Employee::setPIN(const string& PIN){
    this->PIN = PIN;
}

void Employee::setStartDate(const string& startDate){
    this->startDate = startDate;
}

void Employee::setLeader(const string& leader){
    this->leader = leader;
}

void Employee::setPosition(const Position& pos){
    this->position = pos;
}

void Employee::setSquad(Squad& squad){
    this->squad = make_unique<Squad>(squad);
}


string Employee::getFullName() const {
    return this->fullName;
}

string Employee::getAddress() const {
    return this->address;
}

string Employee::getPIN() const {
    return this->PIN;
}

string Employee::getStartDate() const {
    return this->startDate;
}

string Employee::getLeader() const {
    return this->leader;
}

Position Employee::getPositionInfo() const {
    return this->position;
}

string Employee::getPositionName() const {
    return this->getPositionInfo().getPositionName();
}

Squad& Employee::getSquad() const {
    return *this->squad;
}


string Employee::getSquadName() const {
    return this->squad->getSquadName();
}

void Employee::setCustomerEmails(const list<string>& emails)
{

}

void Employee::setProjectName(const string& projectName)
{

}

list<string> Employee::getCustomerEmails() {

}


 void Employee::printToStream(std::ostream& ostr)  {
    ostr << this->getFullName() << string(" ") << this->getAddress() << string(" ") << this->getPIN()
     << string(" ")  << this->getStartDate() << string(" ")  << this->getLeader() << string(" ")
     << this->getPositionName() << string("\n");
}


std::ostream& operator << (std::ostream& ostr,  Employee& analyzer) {
     analyzer.printToStream(ostr);
     return ostr;
}

/*
std::ostream& Employee::operator = (const Employee& emp) {

}
*/




