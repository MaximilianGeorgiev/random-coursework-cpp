#ifndef EMPLOYEEINSTANCE_H
#define EMPLOYEEINSTANCE_H

#include <Employee.h>
#include <EmployeeInterface.h>


class EmployeeInstance : public EmployeeInterface
{
    public:
        unique_ptr<EmployeeInterface> empPtr;

        ~EmployeeInstance() = default;
        EmployeeInstance(const EmployeeInstance& inst) : empPtr(inst.empPtr->clone()) {}
        EmployeeInstance(EmployeeInstance&& inst) = default;
        EmployeeInstance& operator = (const EmployeeInstance& inst) {empPtr = inst.empPtr->clone(); return *this; }
        EmployeeInstance& operator = (EmployeeInstance&& inst) = default;

    protected:
         virtual EmployeeInstance* clone_impl() const override { return new EmployeeInstance(*this); };

    private:
};

#endif // EMPLOYEEINSTANCE_H
