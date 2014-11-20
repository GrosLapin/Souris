#ifndef INFODEPLACEMENT
#define INFODEPLACEMENT

template<class Point2D>
struct InfoDeplacement
{
    // a ou on est actuellement
    Point2D coordonnee;

    // offset en X et Y
    Point2D vecteurDirection;

    // un coeficient mutiplicateur
    double vitesse;
};
#endif // INFODEPLACEMENT
