#include "enum.hpp"

Sex getRandomSex ()
{
    std::minstd_rand0 generator(std::chrono::system_clock::now().time_since_epoch().count());
    if ( generator () < generator.max()/2)
    {
        return Sex::Femelle;
    }
    return Sex::Male;
}

