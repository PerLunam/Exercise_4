//
// Created by Alexander Huber on 10.04.22.
//

#include "sorcerer.h"

//----------------------------- Objektfunktionen -----------------------------
void Sorcerer::attack(Character *enemy)
{
    //Berechnung einer zufälligen Zahl zwischen 15 und 25
    int rndNumber = 5 + std::rand() % (10 - 5 + 1);

    //Berechnung des Schadens
    //Bei Sorcerer ist die Vorgabe "damage = rand(5, 10) + MagicPower - MagicResistance"
    //Wert von MagicPower bezieht sich auf den ausführenden Character/ Sorcerer
    //Wert von "MagicResistance" bezieht sich auf den Gegner
    int damage = (rndNumber + this->getMagicPower()) - enemy->getMR();
    enemy->setHealth(enemy->getHealth() - damage);

    std::cout << this->getName() << " trifft " << enemy->getName() << " für " << damage << " Lebenspunkte." << std::endl;
}

enumType& Sorcerer::getType()
{
    return this->typ;
}

//----------------------------- Getter & Setter -----------------------------
int Sorcerer::getMagicPower() const
{
    return this->magicPower;
}

void Sorcerer::setMagicPower(int newMagicPower)
{
    this->magicPower = newMagicPower;
}

//Operatorenüberladung des Opterators "<<"
std::ostream& operator<<(std::ostream& out, const Sorcerer& s)
{
    std::cout << "Sorcerer " << s.getName() << " mit " << s.getHealth() << " Lebenspunkten, " << s.getArmor() << " Rüstungspunkte, " << s.getMR() << " Magieresistenz und " << s.getMagicPower() <<
              " Zauberkraft sowie " << s.getGold() << " Gold." << std::endl;
    return out;
}