#include "hero.h"

void Hero::attack(Character *enemy)
{
    //Berechnung einer zufälligen Zahl zwischen 15 und 25
    int rndNumber = 15 + std::rand() % (25 - 15 + 1);

    //Berechnung des Schadens
    //Bei Hero ist die Vorgabe "damage = rand(15,25) - armor"
    //Wert von "armor" bezieht sich auf den Gegner
    int damage = rndNumber - enemy->getArmor();
    enemy->setHealth(enemy->getHealth() - damage);

    std::cout << this->getName() << " trifft " << enemy->getName() << " für " << damage << " Lebenspunkte." << std::endl;
}

int Hero::addEquipmentItem(const Item& item)
{
    for(int i = 0; i < MAX_EQUIPMENT_SIZE; i++)
    {
        if (this->hero_gear[i] != nullptr)
        {
            this->hero_gear[i]->setName(item.getName());
            this->hero_gear[i]->setValue(item.getValue());
            //this->hero_gear[i].setIsValid(true); Auszug aus Exercise 3

            //Bei erfolgreicher Platzierung soll der Index des Items ausgegeben werden
            return i;
        }
    }

    //Falls alle Plätze belegt sind oder der Platz falsch initialisiert ist, soll der Wert "-1" ausgegeben werden
    return -1;
}

Item* Hero::removeEquipmentItem(int slot)
{
    if (slot >= 0 && slot < MAX_EQUIPMENT_SIZE)
    {
        if (this->hero_gear[slot] != nullptr)
        {
            //TODO - wie "lösche" ich ein Item?
            this->hero_gear[slot].setIsValid(false);
            std::cout << "Das Item " << this->hero_gear[slot].getName() << " wurde aus dem Inventar von "
                      << this->getName() << " entfernt." << std::endl;
            return this->hero_gear[slot];
        }
    } else {
        return nullptr;
    }
}

void Hero::sellItem(int index)
{
    /*
    //Alternative Umsetzung - ausschließlicher Verkauf der Items aus "inventory"
    if(index >= 0 && index < MAX_INVENTORY_SIZE)
    {
        if(this->getInventory(index)->isIsValid())
        {
            this->getInventory(index)->setIsValid(false);
            this->setGold(this->getGold() + this->getInventory(index)->getValue());
            //this->setGold(this->getInventory(index)->getValue());
            //Ausgabe einer Bestätigung über das Terminal
            std::cout << "Der Gegenstand " << this->getInventory(index)->getName() << " wurde für "
                      << this->getInventory(index)->getValue() << " Gold verkauft. "
                      << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
        }
    }
    */

    //Alternative Umsetzung - Verkauf der Items aus "inventory" und "hero_gear"
    if(index >= 0 && index < MAX_EQUIPMENT_SIZE)
    {
        if(this->getEquipment(index)->isIsValid())
        {
            this->getEquipment(index)->setIsValid(false);
            this->setGold(this->getGold() + this->getEquipment(index)->getValue());
            //this->setGold(this->getEquipment(index)->getValue());

            //Ausgabe einer Bestätigung über das Terminal
            std::cout << "Der Gegenstand " << this->getEquipment(index)->getName() << " wurde für "
                      << this->getEquipment(index)->getValue() << " Gold verkauft. "
                      << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
        } else
        {
            if(this->getInventory(index)->isIsValid())
            {
                this->getInventory(index)->setIsValid(false);
                this->setGold(this->getGold() + this->getInventory(index)->getValue());
                //this->setGold(this->getInventory(index)->getValue());

                //Ausgabe einer Bestätigung über das Terminal
                std::cout << "Der Gegenstand " << this->getInventory(index)->getName() << " wurde für "
                          << this->getInventory(index)->getValue() << " Gold verkauft. "
                          << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
            }
        }
    } else
    {
        if(index >= 0 && index < MAX_INVENTORY_SIZE)
        {
            if(this->getInventory(index)->isIsValid())
            {
                this->getInventory(index)->setIsValid(false);
                this->setGold(this->getGold() + this->getInventory(index)->getValue());
                //this->setGold(this->getInventory(index)->getValue());

                //Ausgabe einer Bestätigung über das Terminal
                std::cout << "Der Gegenstand " << this->getInventory(index)->getName() << " wurde für "
                          << this->getInventory(index)->getValue() << " Gold verkauft. "
                          << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
            }
        }
    }
}

Item *Hero::getEquipment(int index)
{
    Item &item = this->hero_gear[index];
    return &item;
}

enumType& Hero::getType()
{
    return this->typ;
}

std::ostream& operator<<(std::ostream& out, const Hero& hero)
{
    out << "Hero " << hero.getName();
    return out;
}