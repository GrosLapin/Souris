#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <memory>
#include <fstream>
using namespace std;
template <typename T>
void sous_concanate(std::ostringstream& stm,const T& valeur)
{
    stm << valeur;
}

template <typename U, typename... T>
void sous_concanate(std::ostringstream& stm,const U& head,const T&... tail)
{
    stm << head;
    sous_concanate(stm,tail...);
}

template <class... Types>
std::string concanate(const Types&... values)
{
    std::ostringstream stm ;
    sous_concanate(stm, values... );
    return stm.str();
}
using namespace std;
class loadFromIterable
{
    public:
    template<class Iterable>
    loadFromIterable (Iterable contenor)
    {
        decltype(contenor.begin()) it = contenor.begin();
        for ( it; it != contenor.end() ; it++ )
        {
            int i = (*it);
            cout << i << endl;
        }
    }
};
class B;
class A;
class C
{
public :
    void addA(B* a)
    {

    }

};
class A
{
    public :
    static void generate (C* c)
    {

    }
    A (C* c) {
       linkwithC(c);
    }
    virtual void linkwithC(C* c) = 0 ;
};
class B : public A
{
    public :
     B (C* c) :        A::A(c) {

    }
     virtual void linkwithC(C* c) {
         cout << "ok";
     } ;
};

int main ()
{ /*
    set<string> test = { "1","2"};
    loadFromIterable b(test);*/
    C* c = new C();
    A* b = new B(c);
 /*
    vector<int> a = {1,2};
    vector<int> b;
    b.insert(b.end(),a.begin(),a.end());
    b.push_back(0);
    a.push_back(5);
    b.insert(b.end(),a.begin(),a.end());
    for ( int i : b )
        std::cout << i << std::endl;
    return 0;*/
}
