#ifndef EXERCISE_4_HERO_H
#define EXERCISE_4_HERO_H

#include <string>

#include "character.h"

#define MAX_EQUIPMENT_SIZE 2

class Hero : public Character
{
private:
    Item* hero_gear[MAX_EQUIPMENT_SIZE];
    enumType typ;

protected:

public:
    //Konstruktoren der Class "Hero"
    /*
    //Default
    Hero() : char_name("Default-Hero")
    {
        std::cout << "Hero::Default-Constructor: " << char_name << std::endl;
    }
    */

    //Individueller Konstruktor
    Hero(const std::string &char_name, int char_health, int char_gold, int char_armor, int char_mr)
            : Character(char_name, char_health, char_gold, char_armor, char_mr), typ(typeHero)
    {
        /* Equipment ist bereits mit "Item* hero_gear[MAX_EQUIPMENT_SIZE];" initiiert (Zeile 21)
        //Initialisierung der Ausrüstung mit dem Default-Konstruktor aka "Default-Item" und "false"
        for(int i = 0; i < MAX_EQUIPMENT_SIZE; i++)
        {
            this->hero_gear[i] = Item();
        }
        */

        std::cout << "Hero::Constructor: " << char_name << std::endl;
    }

    //Destruktor
    virtual ~Hero()
    {
        //Grafische Trennung der Inhalte
        std::cout << "------------------------------" << std::endl;

        std::cout << *this << " verabschiedet sich und geht voller Stolz der untergehenden Sonne entgegen." << std::endl;
    }

    //----------------------------- Objektfunktionen -----------------------------
    virtual void attack(Character *enemy) override;

    int addEquipmentItem(const Item& item);
    Item* removeEquipmentItem(int slot);

    void sellItem(int index);

    virtual enumType& getType() override;

    //----------------------------- Getter & Setter -----------------------------
    //Werden von der Elternklasse "Character" übernommen
    Item* getEquipment(int index);
};

//Operatorenüberladung des Operators "<<"
std::ostream& operator<<(std::ostream& out, const Hero& hero);

#endif //EXERCISE_4_HERO_H
