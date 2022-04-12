#include "item.h"

//----------------------------- Getter & Setter -----------------------------
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
    //Prüfung, ob die Eingabe einen korrekten Wert enthält, d. h. einen Wert größer oder gleich 0
    if(newValue >= 0)
    {
        this->item_value = newValue;
    }
}
