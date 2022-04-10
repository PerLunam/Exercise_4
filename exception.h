#ifndef EXERCISE_4_EXCEPTION_H
#define EXERCISE_4_EXCEPTION_H

#include <stdexcept>

class GameException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

//Exception, sofern alle Plätze des Inventars komplett belegt sind
class InventarFullException : public GameException
{
public:
    using GameException::GameException;
};

//Exception, sofern ein Indexwert außerhalb des definierten Wertebereichs angegeben wurde
class InvalidIndexException : public GameException
{
public:
    using GameException::GameException;
};

//Exception, sofern der angegebene Indexwert "nullptr" enthält
class InvalidItemException : public GameException
{
public:
    using GameException::GameException;
};

//Exception, sofern alle Plätze des Equipments komplett belegt sind
class EquipmentFullException : public GameException
{
public:
    using GameException::GameException;
};

#endif //EXERCISE_4_EXCEPTION_H
