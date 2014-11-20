#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <utility>
#include <string> // pour le to_string... mais ça marche pas merci 4.7.1
#include <algorithm>

using namespace std;


#include <boost/geometry.hpp>
#include <boost/geometry/geometries/register/point.hpp>
#include <boost/geometry/geometries/register/ring.hpp>

BOOST_GEOMETRY_REGISTER_POINT_2D(sf::Vector2f, float, cs::cartesian, x, y) ;
BOOST_GEOMETRY_REGISTER_POINT_2D(sf::Vector2i, int, cs::cartesian, x, y) ;
BOOST_GEOMETRY_REGISTER_RING(std::vector<sf::Vector2f>);


#include "metier/Souris.hpp"
#include "metier/Terrain.hpp"

int main( int argc, char *argv[])
{
    Souris::testToi();
    Terrain::TestToi();

    exit(5);

    /*bool enVie = true;
    while (temps < tempsMax  && enVie )
    {
        sf::Time tempsEcoulay = timer.getElapsedTime();
        timer.restart();

    }
*/
}

