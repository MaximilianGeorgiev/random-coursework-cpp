#ifndef POSITION_H
#define POSITION_H

#include <string>

using namespace std;

class Position
{
    public:
        Position();
        Position(const string& name, const int& level);
        string getPositionName() const;
        int getPositionLevel() const;
        virtual ~Position();

    protected:

    private:
        string positionName;
        void setPositionName(const string& posName);
        int positionLevel;
        void setPositionLevel(const int& posLevel);

};

#endif // POSITION_H
