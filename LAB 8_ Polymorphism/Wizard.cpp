#include <iostream>
#include "Wizard.h"
#include <string>

using namespace std;

 Wizard::Wizard(const string &name, double health, double attackStrength,const double rank) : Character(WIZARD, name, health, attackStrength), rank(rank) {}
 
void Wizard::attack(Character &opponent)
{
    /*When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.
    The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.*/
    if(opponent.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        double damage = attackStrength*(rank/opp.getRank());
        opp.damage(damage);
        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        cout << opp.getName() << " takes " << damage << " damage." << endl;
    }
    else
    {
        opponent.damage(attackStrength);
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << attackStrength << " damage." << endl;
    }
}

const double Wizard::getRank() const
{
    return rank;
}
