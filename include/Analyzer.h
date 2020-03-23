#ifndef ANALYZER_H
#define ANALYZER_H

#include <Employee.h>
#include <EmployeeInterface.h>
#include <vector>
#include <list>

class Analyzer : public Employee, public EmployeeInterface
{
    public:
        Analyzer();

        Analyzer(std::string fullName, std::string address,
                    std::string PIN,  std::string startDate,
                    std::string leader,
                    Position position,  std::string projectName,
                    std::list<std::string> customersList);

        virtual ~Analyzer();
        std::string getProjectName() const;
        std::list<std::string> getCustomerEmails();
        void printToStream(std::ostream& ostr);
        void setProjectName(const std::string& name);
        void setCustomerEmails(const std::list<std::string>& emails);

    protected:
        virtual Employee* clone_impl() const override {return new Analyzer(*this); };

    private:
        std::string projectName;
        std::list<std::string> customersList;

};

std::ostream& operator << (std::ostream& ostr, Analyzer analyzer);

#endif // ANALYZER_H
