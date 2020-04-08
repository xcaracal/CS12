#include <iostream>
#include "Elf.h"
#include <string>

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength,const string &familyName) : Character(ELF, name, health, attackStrength), familyName(familyName) {}

void Elf::attack(Character &opponent)
{
    //The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.
    double damage = (health/MAX_HEALTH) * attackStrength;
    if(opponent.getType() == ELF)
    {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(opp.getFamilyName() != familyName)
        {
            opp.damage(damage);
            cout << "Elf " << name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
            cout << opp.getName() << " takes " << damage << " damage." << endl;
        }
        else
        {
            cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << familyName << " family." << endl;
        }
    }
    else
    {
        opponent.damage(damage);
        cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
}

const string & Elf::getFamilyName() const
{
    return familyName;
}