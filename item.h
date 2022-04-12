#ifndef EXERCISE_4_ITEM_H
#define EXERCISE_4_ITEM_H

#include <iostream>
#include <string>

class Item
{
private:
    std::string item_name;
    int item_value;

public:
    //Konstruktor der Class "Item"

    //Individueller Konstruktor
    Item(const std::string &name, int value)
            : item_name(name), item_value(value)
    {
        std::cout << "Item::Constructor : " << item_name << std::endl;
    }

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
};

#endif //EXERCISE_4_ITEM_H
