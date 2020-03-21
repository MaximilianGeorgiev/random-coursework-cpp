#ifndef LEAD_H
#define LEAD_H

#include <Programmer.h>
#include <Analyzer.h>


using namespace std;

class Lead : public virtual Programmer, public virtual Analyzer
{
    public:
        unique_ptr<EmployeeInterface> empPtr;

        ~Lead() = default;
        Lead(const Lead& lead) : empPtr(lead.empPtr->clone()) {}
        Lead(Lead&& lead) = default;
        Lead& operator = (const Lead& lead) {empPtr = lead.empPtr->clone(); return *this; }
        Lead& operator = (Lead&& lead) = default;

    protected:

    private:
};

#endif // LEAD_H
