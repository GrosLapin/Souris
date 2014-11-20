#include "fonction.hpp"

void assert_message(bool condition, std::string messageErreur )
{
    if ( ! condition )
    {
        std::cerr << messageErreur << std::endl;
        exit(5);
    }
}
