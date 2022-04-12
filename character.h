#ifndef EXERCISE_4_CHARACTER_H
#define EXERCISE_4_CHARACTER_H

#include <iostream>
#include <ostream>
#include <string>

#include "item.h"
#include "type.h"
#include "exception.h"

#define MAX_INVENTORY_SIZE 10

class Character
{
private:
    std::string char_name;
    int char_health;
    int char_gold;
    int char_armor;
    int char_mr;
    Item* inventory[MAX_INVENTORY_SIZE];

public:
    //Konstruktor der Class "Character"

    //Individueller Konstruktor
    Character(const std::string &name, int health, int gold, int armor, int mr)
            : char_name(name), char_health(health), char_gold(gold), char_armor(armor), char_mr(mr), inventory()
    {
        //Exception, falls kein Name bei der Initialisierung angegeben wurde
        if(name.empty())
        {
            throw InvalidArgumentException("Character:Character: Bitte gib einen Namen ein.");
        }

        //Exception, falls ein negativer Wert bei der Initialisierung angegeben wurde
        if(health < 0 || gold < 0 || armor < 0 || mr < 0)
        {
            throw InvalidArgumentException("Character::Character: Bitte gib einen Wert größer oder gleich 0 ein.");
        }

        //std::cout << "Character::Constructor: " << char_name << std::endl;
    }

    //Destruktor
    virtual ~Character()
    {
        //std::cout << "Character::Destructor: " << char_name << std::endl;
        for(int i = 0; i < MAX_INVENTORY_SIZE; ++i)
        {
            delete inventory[i];
        }
    }

    //----------------------------- Objektfunktionen -----------------------------
    virtual void attack(Character *enemy) = 0;

    bool fight(Character *enemy);

    int addInventarItem(Item *item);
    Item* removeInventarItem(int slot);

    virtual enumType &getType() = 0;

    Item* retrieveRandomLoot(Character *enemy);

    //----------------------------- Getter & Setter -----------------------------
    const std::string& getName() const;
    void setName(const std::string& newName);

    int getHealth() const;
    void setHealth(int newHealth);

    int getGold() const;
    void setGold(int newGold);

    int getArmor() const;
    void setArmor(int newArmor);

    int getMR() const;
    void setMR(int newMR);

    Item* getInventory(int index);
};

//Operatorenüberladung des Operators "<<"
std::ostream& operator<<(std::ostream& out, const Character& character);

#endif //EXERCISE_4_CHARACTER_H
