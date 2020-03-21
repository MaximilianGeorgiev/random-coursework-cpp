#include "Analyzer.h"
#include <list>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

Analyzer::Analyzer()
{
    // base class constructor will automatically be called
    this->setProjectName("PROJECT ANTI CORONA VIRUS");
    this->setCustomerEmails(list<string>());
}

/*
Analyzer::Analyzer(const string& fullName, const string& address,
                   const string& PIN, const string& startDate,
                   const string& leader,
                   const Position& position, const string& projectName,
                   const vector<string>& customersList)
                   : Employee::Employee(fullName, address, PIN, startDate, leader, position)
{
    this->projectName = projectName;
    this->customersList = customersList;
}

*/

Analyzer::Analyzer(string fullName, string address,
                    string PIN,  string startDate,
                    string leader,
                    Position position,  string projectName,
                    list<string> customersList)
                   : Employee::Employee(fullName, address, PIN, startDate, leader, position)
{
    setProjectName(projectName);
    setCustomerEmails(customersList);
}


Analyzer::~Analyzer()
{
    //dtor
}

string Analyzer::getProjectName() const {
    return this->projectName;
}

list<string> Analyzer::getCustomerEmails() {
    return this->customersList;
}

void Analyzer::setCustomerEmails(const list<string>& emails)
{
    this->customersList = emails;
}

void Analyzer::setProjectName(const string& projectName)
{
    this->projectName = projectName;
}


void Analyzer::printToStream(std::ostream& ostr)  {

     ostr << this->getFullName() << string(" ") << this->getAddress() << string(" ") << this->getPIN()
     << string(" ")  << this->getStartDate() << string(" ")  << this->getLeader() << string(" ")
     << this->getPositionName() << string("\n");

     ostr << this->getProjectName() << string(" ");

     for (const auto& iter : this->getCustomerEmails()) cout << iter << string(" ");
}

 std::ostream& operator << (std::ostream& ostr, Analyzer analyzer) {
     analyzer.printToStream(ostr);
     return ostr;
}

