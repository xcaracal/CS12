#include <iostream>
#include <string>
#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength,const string &allegiance) : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {}

void Warrior::attack(Character &opponent)
{
    //The damage done by the warrior is the percentage of the warrior's health remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.
    double damage = (health/MAX_HEALTH) * attackStrength;
    if(opponent.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.getAllegiance() != allegiance)
        {
            opp.damage(damage);
            cout << "Warrior " << name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
            cout << opp.getName() << " takes " << damage << " damage." << endl;
        }
        else
        {
            cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
    }
    else
    {
        opponent.damage(damage);
        cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
}

const string & Warrior::getAllegiance() const
{
    return allegiance;
}