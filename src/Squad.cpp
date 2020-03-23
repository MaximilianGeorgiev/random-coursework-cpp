#include "Squad.h"
#include "Employee.h"

/*
 As much as I wished employees in Squad can be objects/pointers to the Employee class, after 5 continious days of debugging and
 going in circles I had to do a ghetto fix and keep strings only (employee name for example). Same applies for the squads in
 Employee
*/

Squad::Squad(){
this->setName(" ");
this->setLeader(" ");
this->setProject(" ");
this->setEmployees(std::list<std::string>());
}

Squad::Squad(Squad& squad)
{
    this->setName(squad.getSquadName());
    this->setLeader(squad.getLeaderName());
    this->setProject(squad.getProject());
    this->setEmployees(squad.getEmployees());
}

// unique ptr has no copy constructor so cannot be const
Squad::Squad(const std::string& name, const std::string& leader, const std::string& project, const std::list<std::string>& employees)
{
    this->setName(name);
    this->setLeader(leader);
    this->setProject(project);
    this->setEmployees(employees);
}

Squad::~Squad()
{
    //dtor
}

void Squad::setName(const std::string& name){
    this->squadName = name;
}

void Squad::setLeader (const std::string& leader){
    this->leader = leader;
}

void Squad::setProject(const std::string& project){
    this->project = project;
}

void Squad::setEmployees(const std::list<std::string>& employees){
    this->employees = employees;
}

std::string Squad::getSquadName() const {
    return this->squadName;
}


std::string Squad::getLeaderName() const {
    return this->leader;
}

std::string Squad::getProject() const {
    return this->project;
}

std::list<std::string> Squad::getEmployees() const {
    return this->employees;
}
