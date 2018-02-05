#include "../headers/includes.hpp"

int     begin( Lexer &lexer ) {
    unsigned long int   i;
    std::string line;
    std::ifstream   sf("fsd");

    if ( lexer.get_file() ) {

        while ( std::getline( *lexer.get_file(), line ))
            std::cout << line << std::endl;

    }
    else
        while ( line != "end" ) {
            std::getline( std::cin, line );
            line = lexer.erase( line );
            std::cout << line << "|" << std::endl;
        }
    return ( 0 );
}
