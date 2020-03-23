#include "Programmer.h"
#include <Position.h>

Programmer::Programmer()
{
   this->setProjectName("PROJECT ANTI CORONA VIUS");
}

Programmer::Programmer(std::string fullName, std::string address, std::string PIN, std::string startDate, std::string leader,
                 Position position, std::string projectName)
                 : Employee::Employee(fullName, address, PIN, startDate, leader, position)
{
    this->projectName = projectName;
}



Programmer::~Programmer()
{
    //dtor
}

 void Programmer::setProjectName(const std::string& name) {
    this->projectName = name;
 }

std::string Programmer::getProjectName() const {
    return this->projectName;
}

// major design flaw, deprecated in programmer but needs to be overriden in analyzer
// if it is not truly abstract it doesnt work either
std::list<std::string> Programmer::getCustomerEmails() {
    return std::list<std::string>();
}

void Programmer::setCustomerEmails(const std::list<std::string>& custs){}


void Programmer::printToStream(std::ostream& ostr)  {
     ostr << this->getFullName() << std::string(" ") << this->getAddress() << std::string(" ") << this->getPIN()
     << std::string(" ")  << this->getStartDate() << std::string(" ")  << this->getLeader() << std::string(" ")
     << this->getPositionName() << this->getProjectName() << std::string("\n");
}

 std::ostream& operator << (std::ostream& ostr, Programmer programmer) {
     programmer.printToStream(ostr);
     return ostr;
}
