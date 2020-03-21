#include "Squad.h"
#include "Employee.h"

Squad::Squad(){
this->setName(" ");
//this->setLeader(null);
this->setProject(" ");
this->setEmployees(list<Employee>());
}

Squad::Squad(const Squad& squad)
{
    this->setName(squad.getSquadName());
    this->setLeader(squad.getLeader());
    this->setProject(squad.getProject());
    this->setEmployees(squad.getEmployees());
}

Squad::Squad(const string& name, Employee& leader, const string& project, const list<Employee>& employees)
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

void Squad::setName(const string& name){
    this->squadName = name;
}

void Squad::setLeader (Employee& leader){
    this->leader = make_unique<Employee>(leader);
}

void Squad::setProject(const string& project){
    this->project = project;
}

void Squad::setEmployees(const list<Employee>& employees){
    this->employees = employees;
}

string Squad::getSquadName() const {
    return this->squadName;
}
Employee& Squad::getLeader() const {
    return *this->leader;
}

string Squad::getLeaderName() const {
    return this->leader->getFullName();
}

string Squad::getProject() const {
    return this->project;
}

list<Employee> Squad::getEmployees() const {
    return this->employees;
}
