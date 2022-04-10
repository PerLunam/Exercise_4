#ifndef EXERCISE_4_SORCERER_H
#define EXERCISE_4_SORCERER_H

#include <string.h>

#include "npc.h"

class Sorcerer : public NPC
{
private:
    int magicPower;
    enumType typ;

protected:

public:
    //Konstruktor der Class "Sorcerer"

    //Individueller Konstruktor
    Sorcerer(const std::string &char_name, int char_health, int char_gold, int char_armor, int char_mr, int magicPower)
            : NPC(char_name, char_health, char_gold, char_armor, char_mr), magicPower(magicPower), typ(typeSorcerer)
    {
        std::cout << "Sorcerer::Constructor: " << char_name << std::endl;
    }

    //Destruktor
    virtual ~Sorcerer()
    {
        //Grafische Trennung der Inhalte
        std::cout << "------------------------------" << std::endl;

        std::cout << "Sorcerer " << this->getName() << " verlässt das Abenteuer und ärgert andere Held*Innen." << std::endl;
    }

    //----------------------------- Objektfunktionen -----------------------------
    virtual void attack(Character *enemy) override;

    virtual enumType &getType() override;

    //----------------------------- Getter & Setter -----------------------------
    int getMagicPower() const;
    void setMagicPower(int newMagicPower);
};

//Operatorenüberladung des Operators "<<"
std::ostream& operator<<(std::ostream& out, const Sorcerer& s);

#endif //EXERCISE_4_SORCERER_H
