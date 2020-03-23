#pragma once
#include "fwddeclare-squad.h"
#include "fwddeclare-emp.h"
#include <Employee.h>

#include <iostream>
#include <list>
#include <memory>

class Squad
{
    public:
        Squad();
        Squad(Squad& squad);
        Squad(const std::string& name, const std::string& leader, const std::string& project,
               const std::list<std::string>& employees); // cannot be const because unique ptr has no copy constructor
        std::string getSquadName() const;
        std::string getLeaderName() const;
        std::string getProject() const;
        std:: list<std::string> getEmployees() const;
        virtual ~Squad();

    protected:

    private:
        std::string squadName;
        //unique_ptr<Employee>  leader; // after 5 continuous days of trying to get it to work with pointers to the real objects, I just couldn't that's why we will work with strings only
        std::string leader;
        std::string project;
        std::list<std::string> employees; // every employee will have squad and every squad will have multiple employees

        void setName (const std::string& name);
        void setLeader (const std::string&  leader);
        void setProject (const std::string& project);
        void setEmployees (const std::list<std::string>& employees);

};

