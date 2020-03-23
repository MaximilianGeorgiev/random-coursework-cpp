#ifndef LEAD_H
#define LEAD_H

#include <Programmer.h>
#include <Analyzer.h>

/*
Lead is not needed for now, Analyzer is the same as Lead. And in analyzer the position can still Be lead.
*/


class Lead : public Programmer, public Analyzer {};
#endif
