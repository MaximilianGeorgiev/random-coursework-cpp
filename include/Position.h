#ifndef POSITION_H
#define POSITION_H

#include <string>


class Position
{
    public:
        Position();
        Position(const std::string& name, const int& level);
        std::string getPositionName() const;
        int getPositionLevel() const;
        virtual ~Position();

    protected:

    private:
        std::string positionName;
        void setPositionName(const std::string& posName);
        int positionLevel;
        void setPositionLevel(const int& posLevel);

};

#endif // POSITION_H
