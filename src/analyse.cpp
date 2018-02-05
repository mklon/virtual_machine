#include "../headers/includes.hpp"

void    create_lexeme( std::string line ) {
    //std::cout << line << "|" << std::endl;

}

int     begin( Lexer &lexer ) {
    std::string line;

    if ( lexer.get_file() ) {
        while ( std::getline( *lexer.get_file(), line ))
            std::cout << line << std::endl;
    }
    else
        while ( line != "end" ) {
            std::getline( std::cin, line );
            line = lexer.erase( line );
            create_lexeme( line );
        }
    return ( 0 );
}
