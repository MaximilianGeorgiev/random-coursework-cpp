#include "Position.h"

Position::Position()
{
    setPositionName("Chistach");
    setPositionLevel(3);
}

Position::Position(const string& name, const int& level){
    setPositionName(name);
    setPositionLevel(level);
}

Position::~Position()
{
    //dtor
}

void Position::setPositionLevel(const int& posLevel){
    positionLevel = posLevel;
}

void Position::setPositionName(const string& posName){
    positionName = posName;
}

int Position::getPositionLevel()const{
    return positionLevel;
}

string Position::getPositionName() const {
    return positionName;
}
