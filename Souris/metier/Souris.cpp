#include "souris.hpp"

const unsigned int Souris::degresCousinLegal = DegresCousin::CousinIssuDeGermain ;

using namespace std;

void Souris::testToi()
{
    Souris * AGrandMere1 =  new Souris("agm"); AGrandMere1->sex = Sex::Femelle ;
    Souris * AGrandPere2 =  new Souris("agp"); AGrandPere2->sex = Sex::Male ;

    Souris * GParent2 = new Souris("p11",AGrandMere1,AGrandPere2); GParent2->sex = Sex::Femelle;
    Souris * RandGP2 =  new Souris("rgp2"); RandGP2->sex = Sex::Male ;

    Souris * GParent1 = new Souris("p11",AGrandMere1,AGrandPere2); GParent1->sex = Sex::Femelle;
    Souris * RandGP1 =  new Souris("rgp1"); RandGP1->sex = Sex::Male ;

    Souris * Parent11=  new Souris("p12",GParent1,RandGP1); Parent11->sex = Sex::Male;
    Souris * RandP1 =  new Souris("rgp1"); RandP1->sex = Sex::Femelle ;
    Souris * Moi = new Souris("rgp1",Parent11,RandP1); Moi->sex = Sex::Male ;
    Souris * MaSoeur = new Souris("rgp1",Parent11,RandP1); MaSoeur->sex = Sex::Femelle ;

    Souris * Parent12=  new Souris("p12",GParent1,RandGP1); Parent12->sex = Sex::Male;
    Souris * RandP2 =  new Souris("rgp1"); RandP2->sex = Sex::Femelle ;
    Souris * cousine = new Souris("rgp1",RandP2,Parent12); cousine->sex = Sex::Femelle ;

    Souris * oncle_degres2=  new Souris("p12",GParent2,RandGP2); oncle_degres2->sex = Sex::Male;
    Souris * tante_degres2 =  new Souris("rgp1"); tante_degres2->sex = Sex::Femelle ;

    Souris * cousine_issue = new Souris("rgp1",oncle_degres2,tante_degres2); cousine_issue->sex = Sex::Femelle ;

    Souris * autre =  new Souris("agp"); autre->sex = Sex::Male ;

    assert_message(! Moi->isFuckable(AGrandMere1),"pas AGM");
    assert_message(! Moi->isFuckable(AGrandPere2),"pas AGP");
    assert_message(! Moi->isFuckable(GParent1),"pas GM");
    assert_message(! Moi->isFuckable(RandGP1),"pas GP");
    assert_message(! Moi->isFuckable(Parent11),"pas P");
    assert_message(! Moi->isFuckable(RandP1),"pas P");
    assert_message(! Moi->isFuckable(MaSoeur),"pas Soeur");
    assert_message(! Moi->isFuckable(Moi),"pas Moi :)");
    assert_message(! Moi->isFuckable(Parent12),"pas tante :)");
    assert_message(! Moi->isFuckable(cousine),"pas cousin :)");
    assert_message( Moi->isFuckable(cousine_issue),"Ok cousine_issue :)");

    cout << "fin moi, debut autre "<< endl;
    assert_message( autre->isFuckable(AGrandMere1),"Ok AGM");
    assert_message(! autre->isFuckable(AGrandPere2),"pas AGP");
    assert_message( autre->isFuckable(GParent1),"Ok GM");
    assert_message(! autre->isFuckable(RandGP1),"pas GP");
    assert_message(! autre->isFuckable(Parent11),"pas P");
    assert_message( autre->isFuckable(RandP1),"Ok M");
    assert_message( autre->isFuckable(MaSoeur),"Ok Soeur");
    assert_message(! autre->isFuckable(autre),"pas Moi :)");
    assert_message(!autre->isFuckable(Parent12),"pas tante :)");
    assert_message( autre->isFuckable(cousine),"Ok cousin :)");
    assert_message( autre->isFuckable(cousine_issue),"Ok cousine_issue :)");
}



bool Souris::aPourCousinProche (Souris const * const other ) const
{
    std::set<Souris*> setParent;
    std::set<Souris*> setEnfant;

    // j'initialise la boucle ce qu'y mevite de garde this dans un vecteur de pointeur (il aime pas ça dans le methode const)
    size_t i = 0;
    if (  i < degresCousinLegal  )
    {
        // je prends tous les prends de tous les enfant
        setEnfant.insert(this->parentsEnVie.begin(),this->parentsEnVie.end());
        i++;
    }

    for ( ; i < degresCousinLegal ; i++ )
    {
        for (auto enfant : setEnfant )
        {
            // je prends tous les prends de tous les enfant
            setParent.insert(enfant->parentsEnVie.begin(),enfant->parentsEnVie.end());
        }
        setEnfant = setParent;
        setParent.clear();
    }

    // a ce point, setEnfant (oui oui on a swap) contient tout les (grand*) parents de this
    std::set<Souris*> setEnRelation;
    for (auto ancetre : setEnfant )
    {
        auto enfantDAncetre = ancetre->getDescendance();
        setEnRelation.insert(enfantDAncetre.begin(),enfantDAncetre.end());
    }

    // si on trouve qqch, c'est qu'on est != en .end() on doit retourner vrais
    return (std::find(setEnRelation.begin(),setEnRelation.end(),other)!=setEnRelation.end());
}


// Par du postulat qu'on pas de truc genre "Ma grand mere est ma mere aussi"
vector<Souris*> Souris::getDescendance () const
{
    vector<Souris*> descendance;
    descendance.insert(descendance.end(),enfantDirectEnVie.begin(),enfantDirectEnVie.end());
    /// Ne faire des modifications sur le tableau qu'on parcours dans un foreach que quand on est sexy (et sur de soi)
    for (Souris* enfant : enfantDirectEnVie )
    {
        auto descendanceEnfant = enfant->getDescendance();
        descendance.insert(descendance.end(),descendanceEnfant.begin(),descendanceEnfant.end());
    }

    return descendance;
}
bool Souris::aPourAncetre (Souris const * const other ) const
{
 if ( parentsEnVie.size() > 0 )
 {
     // other est un parent direct si il est dans la liste des parents en vie
     if ( std::find(parentsEnVie.begin(), parentsEnVie.end(), other) != parentsEnVie.end())
     {
         return true;
     }
     // si c'est pas mon pere, c'est peut etre le pere de mon pere
     for (Souris* unParent : parentsEnVie )
     {
         if ( unParent->aPourAncetre(other) )
         {
             return true;
         }
     }
     // si c'est le parent d'aucun de mes parents, c'est pas un parent !
 }

return false;

}
bool Souris::isFuckable (Souris const * const other ) const
{
 // techniquement il peut le niquer, juste ba ça fera pas des enfants
 if (! isOpositeSex(other)) return false;

 // don't fuck your parent, U sick bastard
 if ( aPourAncetre(other) ) return false;

 // MAIS C'EST TA FILLE SALE PORC
 if (other->aPourAncetre(this)) return false;

 // non au lanister ! ça bloque aussi les tantes ext
 if ( aPourCousinProche(other)) return false;

 // si tu veux te faire ta niece, et ba tu peux pas :o
 if ( other->aPourCousinProche(this)) return false;

 return true;
}
