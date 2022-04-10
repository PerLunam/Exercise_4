#ifndef EXERCISE_4_NPC_H
#define EXERCISE_4_NPC_H

#include <string>

#include "character.h"

class NPC : public Character
{
public:
    //durch "using Character::Character;" kann in dieser Klasse auf die Konstruktoren und Destruktoren von "Character" zugegriffen werden
    using Character::Character;

    /*
    //Individueller Konstruktor
    NPC(const std::string &char_name, int char_health, int char_gold, int char_armor, int char_mr)
            : Character(char_name, char_health, char_gold, char_armor, char_mr)
    {
        //std::cout << "NPC::Constructor: " << char_name << std::endl;
    }
    */

    //Destruktor
    virtual ~NPC()
    {
        //std::cout << "Calling NPC::Destructor" << std::endl;
        //std::cout << this->getType() << " " << this->getName() << " verabschiedet sich und geht voller Stolz der untergehenden Sonne entgegen." << std::endl;
    }

    //----------------------------- Objektfunktionen -----------------------------
    //keine notwendig

    //----------------------------- Getter & Setter -----------------------------
    //keine notwendig
};

#endif //EXERCISE_4_NPC_H
