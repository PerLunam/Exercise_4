#ifndef EXERCISE_4_HERO_H
#define EXERCISE_4_HERO_H

#include <string>

#include "character.h"

#define MAX_EQUIPMENT_SIZE 2

//Forward-Declaration der Class "NPC"
class NPC;

class Hero : public Character
{
private:
    Item* hero_gear[MAX_EQUIPMENT_SIZE];
    enumType typ;

protected:

public:
    //Konstruktor der Class "Hero"

    //Individueller Konstruktor
    Hero(const std::string &char_name, int char_health, int char_gold, int char_armor, int char_mr)
            : Character(char_name, char_health, char_gold, char_armor, char_mr), hero_gear(), typ(typeHero)
    {
        std::cout << "Hero::Constructor: " << char_name << std::endl;
    }

    //Destruktor
    virtual ~Hero()
    {
        for(int i = 0; i < MAX_EQUIPMENT_SIZE; ++i)
        {
            delete hero_gear[i];
        }

        //Grafische Trennung der Inhalte
        //std::cout << "------------------------------" << std::endl;

        std::cout << *this << " verabschiedet sich und geht voller Stolz der untergehenden Sonne entgegen." << std::endl;
    }

    //----------------------------- Objektfunktionen -----------------------------
    virtual void attack(Character *enemy) override;

    int addEquipmentItem(Item* item);
    Item* removeEquipmentItem(int slot);

    void sellItem(int index);

    virtual enumType& getType() override;

    //----------------------------- Getter & Setter -----------------------------
    //Werden von der Elternklasse "Character" übernommen
    Item* getEquipment(int index);
};

#endif //EXERCISE_4_HERO_H
