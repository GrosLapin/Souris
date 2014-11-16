#ifndef GestionAge_hpp
#define GestionAge_hpp

#include "enum.hpp"
#include <iostream>
#include <chrono>
#include <random>

/* GestionAge don't give a shit a propos de la logique.
   Si tu veux pas que ta souris ne rajeunnise pas demerde toi pour que les param soit > 0
*/

class GestionAge
{
    private :
        static const double DEAD_RATE_PER_YEAR;
        static const double AGE_MATURITY;
        static const int MILLISECOND_PER_YEAR;

        std::minstd_rand0 generator;
        double age;
        double convertionMillisecondAge (double milliseconds) const {return (milliseconds/(double)MILLISECOND_PER_YEAR);}
        double getRandomPerCents ()
        {
           return (generator() / (double ) generator.max()) * 100;
        }

    public :

        // (google est mon ami, j'ecris pas ça de tete)
        GestionAge () :
            generator(std::chrono::system_clock::now().time_since_epoch().count()),
            age(0)
            {}

        bool isMature() const { return age >= AGE_MATURITY ;}
        EtatVie growOld (float milliseconds)
        {
            double temps = convertionMillisecondAge(milliseconds);
            age += temps;

            double mon_rand = getRandomPerCents();
            if (  mon_rand < temps * DEAD_RATE_PER_YEAR * 100 )
            {
                return EtatVie::Mort;
            }
            return EtatVie::EnVie;
        }
};
#endif // GestionAge_hpp
