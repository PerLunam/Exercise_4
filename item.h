#ifndef EXERCISE_4_ITEM_H
#define EXERCISE_4_ITEM_H

#include <iostream>
#include <string>

class Item
{
private:
    std::string item_name;
    int item_value;
    //bool isValid;

protected:

public:
    //Konstruktor der Class "Character"
    //Default
    Item() : item_name("Default-Item"), item_value(0)
    {
        std::cout << "Calling Item::Default-Constructor" << item_name << std::endl;
    }

    /* Version - Exercise 3
    Item() : item_name("Default-Item"), item_value(0), isValid(false)
    {
        //std::cout << "Calling Item::Default-Constructor" << item_name << std::endl;
    }
    */

    //Individueller Konstruktor
    Item(const std::string &name, int value)
            : item_name(name), item_value(value)
    {
        std::cout << "Item::Constructor : " << item_name << std::endl;
    }

    /* Version - Exercise 3
    Item(const std::string &name, int value)
            : item_name(name), item_value(value), isValid(true)
    {
        std::cout << "Item::Constructor : " << item_name << std::endl;
    }
    */

    //Destruktor
    ~Item()
    {
        std::cout << "Item::Destructor: " << item_name << std::endl;
    }

    //----------------------------- Getter & Setter -----------------------------
    const std::string &getName() const;
    void setName(const std::string &newName);

    int getValue() const;
    void setValue(int newValue);

    //Version - Exercise 3
    //Wird nicht mehr benötigt, da ab sofort "nullptr" zurückgegeben wird,
    //wenn der Item-Platz falsch oder nicht initialisiert ist
    //bool isIsValid() const;
    //void setIsValid(bool newIsValid);
};

//Operatorenüberladung des Operators "<<"
std::ostream& operator<<(std::ostream& out, const Item& item);

#endif //EXERCISE_4_ITEM_H
