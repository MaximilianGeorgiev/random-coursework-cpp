#pragma once
class Employee;

/*
We need to forward declare classes to avoid circular dependancy. Such was the case with Employee and Squad
Because both the Employee had a squad and the Squad had an Employee and it failed miserably.

*/
