#include "Character.h"
#include <string>

using namespace std;

#ifndef __WIZARD_H__
#define __WIZARD_H__

class Wizard : public Character 
{
private:
    const int rank;
public:
    Wizard(const string &, double, double,const double);
    void attack(Character &);
    const double getRank() const;
};

#endif