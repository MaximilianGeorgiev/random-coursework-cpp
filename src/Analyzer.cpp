#include "Analyzer.h"
#include <list>
#include <iostream>
#include <vector>
#include <list>

Analyzer::Analyzer()
{
    // base class constructor will automatically be called
    this->setProjectName("PROJECT ANTI CORONA VIRUS");
    this->setCustomerEmails(std::list<std::string>());
}


Analyzer::Analyzer(std::string fullName, std::string address,
                    std::string PIN,  std::string startDate,
                    std::string leader,
                    Position position,  std::string projectName,
                    std::list<std::string> customersList)
                   : Employee::Employee(fullName, address, PIN, startDate, leader, position)
{
    this->setProjectName(projectName);
    this->setCustomerEmails(customersList);
}


Analyzer::~Analyzer()
{
    //dtor
}

std::string Analyzer::getProjectName() const {
    return this->projectName;
}

std::list<std::string> Analyzer::getCustomerEmails() {
    return this->customersList;
}

void Analyzer::setCustomerEmails(const std::list<std::string>& emails)
{
    this->customersList = emails;
}

void Analyzer::setProjectName(const std::string& projectName)
{
    this->projectName = projectName;
}

void Analyzer::printToStream(std::ostream& ostr)  {

     ostr << this->getFullName() << std::string(" ") << this->getAddress() << std::string(" ") << this->getPIN()
     << std::string(" ")  << this->getStartDate() << std::string(" ")  << this->getLeader() << std::string(" ")
     << this->getPositionName() << std::string("\n");

     ostr << this->getProjectName() << std::string(" ");

     for (const auto& iter : this->getCustomerEmails()) std::cout << iter << std::string(" ");
}

 std::ostream& operator << (std::ostream& ostr, Analyzer analyzer) {
     analyzer.printToStream(ostr);
     return ostr;
}

