#ifndef souris_hpp
#define souris_hpp


#include "fonction.hpp"
#include "GestionAge.hpp"
#include <list>
#include <functional>
#include <chrono>
#include <vector>
#include <set>
#include <random>
#include <algorithm>

class Souris
{

    static const unsigned int degresCousinLegal;

    GestionAge gestionAge;
    std::list <Souris*> parentsEnVie;
    std::list <Souris*> enfantDirectEnVie;
    Sex sex;


    std::string name;

public :
    static void testToi ();
    Souris (std::string unNom) : name (unNom)
    {
        sex = getRandomSex ();
    }

    Souris (std::string unNom,Souris * const parent1, Souris * const parent2) : name (unNom)
    {
        assert(parent1->isOpositeSex(*parent2),"Go lire un manuel de biologie");

        parentsEnVie.push_back({parent2});
        parentsEnVie.push_back({parent1});

        parent1->enfantDirectEnVie.push_back(this);
        parent2->enfantDirectEnVie.push_back(this);
    }

    ~Souris()
    {
        std::cout << "TODO : DESTRUCTEUR "<<std::endl;
    }
    Souris (const Souris & copie ) = delete;
    Souris& operator=(const Souris &  copie) = delete;

    bool isOpositeSex (Souris const & other) const { return sex != other.sex;}
    bool isOpositeSex (Souris const  * const other) const { return sex != other->sex;}
    bool isMature () const { return gestionAge.isMature();}
    bool isFuckable (Souris const * const other ) const ;
    bool aPourAncetre (Souris const * const other ) const;
    bool aPourCousinProche (Souris const * const other ) const;
    std::vector<Souris*> getDescendance () const;
    EtatVie growOld (float milliseconds)
    {
        assert(milliseconds>0,"On ne veut pas de souris qui remonte le temps");
        return gestionAge.growOld(milliseconds);
    }

};

#endif // souris_hpp
