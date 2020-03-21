#ifndef ANALYZER_H
#define ANALYZER_H

#include <Employee.h>
#include <EmployeeInterface.h>
#include <vector>
#include <list>


using namespace std;


class Analyzer : public Employee, public EmployeeInterface
{
    public:
        Analyzer();



        /*
        Analyzer(const string& fullName, const string& address,
                 const string& PIN, const string& startDate, const string& leader,
                 const Position& position, const string& projectName,
                 const vector<string>& customersList);
                 */

        Analyzer(string fullName, string address,
                    string PIN,  string startDate,
                    string leader,
                    Position position,  string projectName,
                    list<string> customersList);

         // copying constructor used by vector.push_back


        virtual ~Analyzer();
        string getProjectName() const;
        list<string> getCustomerEmails();
        void printToStream(ostream& ostr);
        void setProjectName(const string& name);
        void setCustomerEmails(const list<string>& emails);


    protected:
        virtual Employee* clone_impl() const override {return new Analyzer(*this); };

    private:
        string projectName;
        list<string> customersList;

};

std::ostream& operator << (std::ostream& ostr, Analyzer analyzer);





#endif // ANALYZER_H
