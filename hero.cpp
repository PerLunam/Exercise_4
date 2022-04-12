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

int Hero::addEquipmentItem(Item *item)
{
    for(int i = 0; i < MAX_EQUIPMENT_SIZE; ++i)
    {
        //Prüfung, ob Index auf "nullptr" zeigt oder auf eine gültige Speicheradresse
        //bei "false" zeigt der Index auf "nullptr" und wird nun korrekt initialisiert
        if(!this->hero_gear[i])
        {
            this->hero_gear[i] = item;
            //this->inventory[i]->setName(item->getName());
            //this->inventory[i]->setValue(item->getValue());

            //Bei erfolgreicher Platzierung soll der Index des Items ausgegeben werden
            return i;
        }
    }
    //Exception, falls alle Plätze belegt sind
    throw InventarFullException("Character::addInventarItem(): Inventar ist bereits komplett belegt.");
}

Item* Hero::removeEquipmentItem(int slot)
{
    if (slot >= 0 && slot < MAX_EQUIPMENT_SIZE)
    {
        //Passende Exception, wenn der eingegebene Indexwert außerhalb des Wertebereichs liegt
        throw InvalidIndexException("Hero::removeEquipmentItem(): Der angegebene Indexwert liegt außerhalb des gültigen Wertebereichs.");
    } else if(this->hero_gear[slot])
    {
        //Überschreiben des Slots mit "nullptr" mithilfe einer zusätzlichen Variablen "retValue"
        Item* retValue = this->hero_gear[slot];
        this->hero_gear[slot] = nullptr;

        std::cout << "Das Item " << this->hero_gear[slot]->getName() << " wurde aus dem Equipment von " << this->getName() << " entfernt." << std::endl;
        return retValue;
    } else
    {
        //Passende Exception, wenn der angegebene Indexwert auf "nullptr" zeigt
        throw InvalidItemException("Hero::removeEquipmentItem(): Unter dem angegebenen Index ist kein gültiges Item gespeichert.");
    }
}

/*
void Hero::sellItem(int index)
{
    //Alternative Umsetzung - Verkauf der Items aus "inventory" und "hero_gear"
    if(index >= 0 && index < MAX_EQUIPMENT_SIZE)
    {
        if(this->getEquipment(index))
        {
            Item* retValue = this->getEquipment(index);
            retValue = nullptr;
            this->setGold(this->getGold() + this->getEquipment(index)->getValue());
            //this->setGold(this->getEquipment(index)->getValue());

            //Ausgabe einer Bestätigung über das Terminal
            std::cout << "Der Gegenstand " << this->getEquipment(index)->getName() << " wurde für "
                      << this->getEquipment(index)->getValue() << " Gold verkauft. "
                      << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
        } else
        {
            if(this->getInventory(index))
            {
                Item* retValue = this->getInventory(index);
                retValue = nullptr;
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
            if(this->getInventory(index))
            {
                Item* retValue = this->getInventory(index);
                retValue = nullptr;
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
*/

void Hero::sellItem(int index)
{
    //Verkauf der Items aus "inventory" und "hero_gear"
    if(index >= 0 && index < MAX_EQUIPMENT_SIZE)
    {
        if(this->hero_gear[index])
        {
            this->setGold(this->getGold() + this->getEquipment(index)->getValue());
            //this->setGold(this->getEquipment(index)->getValue());

            //this->hero_gear[index] = nullptr;
            this->removeEquipmentItem(index);

            //Ausgabe einer Bestätigung über das Terminal
            std::cout << "Der Gegenstand " << this->getEquipment(index)->getName() << " wurde für "
                      << this->getEquipment(index)->getValue() << " Gold verkauft. "
                      << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
        } else if (this->getInventory(index))
        {
            this->setGold(this->getGold() + this->getInventory(index)->getValue());
            //this->setGold(this->getInventory(index)->getValue());

            this->removeInventarItem(index);

            //Ausgabe einer Bestätigung über das Terminal
            std::cout << "Der Gegenstand " << this->getInventory(index)->getName() << " wurde für "
                      << this->getInventory(index)->getValue() << " Gold verkauft. "
                      << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
        } else
        {
            //Passende Exception, wenn der angegebene Indexwert auf "nullptr" zeigt
            throw InvalidItemException("Hero::sellItem(): Unter dem angegebenen Index ist kein gültiges Item gespeichert.");
        }
    } else if(index >= 0 && index < MAX_INVENTORY_SIZE)
    {
            if(this->getInventory(index))
            {
                this->setGold(this->getGold() + this->getInventory(index)->getValue());
                //this->setGold(this->getInventory(index)->getValue());

                this->removeInventarItem(index);

                //Ausgabe einer Bestätigung über das Terminal
                std::cout << "Der Gegenstand " << this->getInventory(index)->getName() << " wurde für "
                          << this->getInventory(index)->getValue() << " Gold verkauft. "
                          << this->getName() << " besitzt nun " << this->getGold() << " Gold." << std::endl;
            } else
            {
                //Passende Exception, wenn der angegebene Indexwert auf "nullptr" zeigt
                throw InvalidItemException("Hero::sellItem(): Unter dem angegebenen Index ist kein gültiges Item gespeichert.");
            }
    } else
    {
        //Passende Exception, wenn der eingegebene Indexwert außerhalb des Wertebereichs liegt
        throw InvalidIndexException("Hero::sellItem(): Der angegebene Indexwert liegt außerhalb des gültigen Wertebereichs.");
    }
}

Item* Hero::getEquipment(int index)
{
    if(index >= 0 && index < MAX_EQUIPMENT_SIZE)
    {
        Item* equipment = this->hero_gear[index];
        return equipment;
    } else
    {
        //Passende Exception, wenn der eingegebene Indexwert außerhalb des Wertebereichs liegt
        throw InvalidIndexException("Hero::getEquipment(): Der angegebene Indexwert liegt außerhalb des gültigen Wertebereichs.");
    }
}

enumType& Hero::getType()
{
    return this->typ;
}
