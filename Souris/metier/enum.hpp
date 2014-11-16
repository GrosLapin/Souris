#ifndef enum_hpp
#define enum_hpp

#include <chrono>
#include <random>

enum class Sex
{
    Male,
    Femelle
};

Sex getRandomSex ();

enum class EtatVie
{
    EnVie,
    Mort
};

enum DegresCousin
{
    Frere = 0,
    Cousin = 1,
    CousinIssuDeGermain = 2
};

#endif // enum_hpp
