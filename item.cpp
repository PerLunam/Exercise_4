//
// Created by Alexander Huber on 28.03.22.
//

#include "item.h"

const std::string &Item::getName() const
{
    return this->item_name;
}

void Item::setName(const std::string &newName)
{
    //Prüfung, ob die Eingabe überhaupt einen Wert enthält
    //Funktion wird nur ausgeführt, wenn "newName.empty()" == false aka "!newName.empty()"
    if(!newName.empty())
    {
        this->item_name = newName;
    }
}

int Item::getValue() const
{
    return this->item_value;
}

void Item::setValue(int newValue)
{
    //Prüfung, ob die Eingabe einen korrekten Wert enthält, d. h. einen Wert größer gleich 0
    if(newValue >= 0)
    {
        this->item_value = newValue;
    }
}

/* Version - Exercise 3
bool Item::isIsValid() const
{
    return this->isValid;
}

void Item::setIsValid(bool newIsValid)
{
    this->isValid = newIsValid;
}
*/

std::ostream& operator<<(std::ostream& out, const Item& item)
{
    out << "Gegenstand " << item.getName() << " mit einem Wert von " << item.getValue() << " .";
    return out;
}
