#include "Position.h"

Position::Position()
{
    setPositionName("Chistach");
    setPositionLevel(3);
}

Position::Position(const std::string& name, const int& level){
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

void Position::setPositionName(const std::string& posName){
    positionName = posName;
}

int Position::getPositionLevel()const{
    return positionLevel;
}

std::string Position::getPositionName() const {
    return positionName;
}
