#ifndef TERRAINPoint2D
#define TERRAIN

class Terrain
{
private :
    std::vector<sf::Vector2f> limiteTerrain;
public :
    static void TestToi()
    {
        Terrain test;
        assert_message(test.isPositionValide({0,0}),"0 0 devrait etre bon");
        assert_message(test.isPositionValide({0,50}),"0 50 devrait etre bon");
        assert_message(test.isPositionValide({50,50}),"50 50 devrait etre bon");
        assert_message(test.isPositionValide({50,0}),"0 50 devrait etre bon");
        assert_message(test.isPositionValide({10,10}),"10 10 devrait etre bon");

        assert_message( !test.isPositionValide({-10,10}),"-10 10 devrait etre faux");
        assert_message( !test.isPositionValide({10,-10}),"10 -10 devrait etre faux");
        assert_message( !test.isPositionValide({-10,-10}),"-10 -10 devrait etre faux");
        assert_message( !test.isPositionValide({60,-60}),"60 -60 devrait etre faux");

    }
    Terrain()
    {
        limiteTerrain = {{0,0},{0,50},{50,50},{50,0}};
        boost::geometry::correct(limiteTerrain);
    }
    Terrain(std::vector<sf::Vector2f> listPoints)
    {
        limiteTerrain = listPoints;
        boost::geometry::correct(limiteTerrain);
    }
    bool isPositionValide(sf::Vector2f pointATester)
    {
        // si on est pas disjoint, on est dedans :D
        return ! boost::geometry::disjoint(pointATester,limiteTerrain);
    }

    // retourne un point dans le terrain
    sf::Vector2f getPositionValide(sf::Vector2f pointDepart, sf::Vector2f pointArriveATester)
    {
        cout << "TODO";
        exit(5);
        return pointArriveATester;
    }


};

#endif // TERRAIN
