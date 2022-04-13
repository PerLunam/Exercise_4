#ifndef EXERCISE_4_FIGHTER_H
#define EXERCISE_4_FIGHTER_H

#include <string.h>

#include "npc.h"

class Fighter : public NPC
{
private:
    int strength;
    enumType typ;

public:
    //Konstruktor der Class "Fighter"

    //Individueller Konstruktor
    Fighter(const std::string &char_name, int char_health, int char_gold, int char_armor, int char_mr, int strength)
            : NPC(char_name, char_health, char_gold, char_armor, char_mr), strength(strength), typ(typeFighter)
    {
        std::cout << "Fighter::Constructor: " << char_name << std::endl;
    }

    //Destruktor
    virtual ~Fighter()
    {
        //Grafische Trennung der Inhalte
        //std::cout << "------------------------------" << std::endl;

        std::cout << "Fighter " << this->getName() << " verlässt das Abenteuer und ärgert andere Held*Innen." << std::endl;
    }

    //----------------------------- Objektfunktionen -----------------------------
    virtual void attack(Character *enemy) override;

    virtual enumType &getType() override;

    //----------------------------- Getter & Setter -----------------------------
    int getStrength() const;
    void setStrength(int newStrength);
};

//Operatorenüberladung des Operators "<<"
std::ostream& operator<<(std::ostream& out, const Fighter& fighter);

#endif //EXERCISE_4_FIGHTER_H
