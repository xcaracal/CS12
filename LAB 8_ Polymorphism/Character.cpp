#include "Character.h"
#include <string>

using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength) : type(type), name(name), health(health), attackStrength(attackStrength) {}


 	HeroType Character::getType() const
    {
        return type;
    }

 	const string & Character::getName() const
    {
        return name;
    }

 	int Character::getHealth() const
    {
        return (int)health;
    }

 	void Character::setHealth(double h)
    {
        health = h;
    }

 	void Character::damage(double d)
    {
        double tempHealth = health - d;
        if(tempHealth < 0)
        {
            health = 0;
        }
        else
        {
            health = tempHealth;
        }
    }

 	bool Character::isAlive() const
    {
        if(health == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }