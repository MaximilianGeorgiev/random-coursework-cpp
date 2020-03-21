#pragma once
#include "fwddeclare-squad.h"
#include "fwddeclare-emp.h"
#include <Employee.h>

#include <iostream>
#include <list>
#include <memory>


using namespace std;


class Squad
{
    public:
        Squad();
        Squad(const Squad& squad);
        Squad(const string& name, Employee& leader, const string& project, const list<Employee>& employees);
        string getSquadName() const;
        Employee& getLeader() const;
        string getLeaderName() const;
        string getProject() const;
        list<Employee> getEmployees() const;
        virtual ~Squad();

    protected:

    private:
        string squadName;
        unique_ptr<Employee> leader;
        string project;
        list<Employee> employees; // every employee will have squad and every squad will have multiple employees

        void setName (const string& name);
        void setLeader (Employee& leader);
        void setProject (const string& project);
        void setEmployees (const list<Employee>& employees);

};

