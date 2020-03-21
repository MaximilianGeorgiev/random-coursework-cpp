#include "Programmer.h"
#include <Position.h>


Programmer::Programmer()
{
   this->setProjectName("PROJECT ANTI CORONA VIUS");
}

/*
Programmer::Programmer(const string& fullName, const string& address, const string& PIN,
                       const string& startDate, const string& leader,
                       const Position& position, const string& projectName)
                       : Employee::Employee(fullName, address, PIN, startDate, leader, position)
{
    this->projectName = projectName;
}

*/

Programmer::Programmer(string fullName, string address, string PIN, string startDate, string leader,
                 Position position, string projectName)
                 : Employee::Employee(fullName, address, PIN, startDate, leader, position)
{
    this->projectName = projectName;
}



Programmer::~Programmer()
{
    //dtor
}

 void Programmer::setProjectName(const string& name) {
    this->projectName = name;
 }

string Programmer::getProjectName() const {
    return this->projectName;
}

// major design flaw, deprecated in programmer but needs to be overriden in analyzer
// if it is not truly abstract it doesnt work either
list<string> Programmer::getCustomerEmails() {
    return list<string>();
}

void Programmer::setCustomerEmails(const list<string>& custs){
    // again
}


void Programmer::printToStream(std::ostream& ostr)  {
     ostr << this->getFullName() << string(" ") << this->getAddress() << string(" ") << this->getPIN()
     << string(" ")  << this->getStartDate() << string(" ")  << this->getLeader() << string(" ")
     << this->getPositionName() << this->getProjectName() << string("\n");
}

 std::ostream& operator << (std::ostream& ostr, Programmer programmer) {
     programmer.printToStream(ostr);
     return ostr;
}
