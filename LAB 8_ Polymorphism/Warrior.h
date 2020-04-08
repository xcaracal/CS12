#include "Character.h"
#include <string>

using namespace std;

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior : public Character
{
private:
    string allegiance; 
public:
    Warrior(const string &, double, double,const string &);
    void attack(Character &);
    const string & getAllegiance() const;
};

#endif