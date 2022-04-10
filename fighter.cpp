//
// Created by Alexander Huber on 10.04.22.
//

#include "fighter.h"

#include <iostream>

//----------------------------- Objektfunktionen -----------------------------
void Fighter::attack(Character *enemy)
{
    //Berechnung einer zufälligen Zahl zwischen 15 und 25
    int rndNumber = 5 + std::rand() % (10 - 5 + 1);

    //Berechnung des Schadens
    //Bei Fighter ist die Vorgabe "damage = rand(5, 10) + strength - armor"
    //Wert von Strength bezieht sich auf den ausführenden Character/ Fighter
    //Wert von "armor" bezieht sich auf den Gegner
    int damage = (rndNumber + this->getStrength()) - enemy->getArmor();
    enemy->setHealth(enemy->getHealth() - damage);

    std::cout << this->getName() << " trifft " << enemy->getName() << " für " << damage << " Lebenspunkte." << std::endl;
}

enumType& Fighter::getType()
{
    return this->typ;
}

//----------------------------- Getter & Setter -----------------------------
int Fighter::getStrength() const
{
    return this->strength;
}

void Fighter::setStrength(int newStrength)
{
    if(newStrength < 0)
    {
        this->strength = newStrength;
    } else
    {
        this->strength = 0;
    }
}

//Operatorenüberladung des Opterators "<<"
std::ostream& operator<<(std::ostream& out, const Fighter& fighter)
{
    std::cout << "Fighter " << fighter.getName() << " mit " << fighter.getHealth() << " Lebenspunkten, " << fighter.getArmor() << " Rüstungspunkte, " << fighter.getMR() << " Magieresistenz und " << fighter.getStrength() <<
              " Muskelkraft sowie " << fighter.getGold() << " Gold." << std::endl;
    return out;
}