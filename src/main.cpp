#include <iostream>
#include "../headers/Lexer.class.hpp"

int		main( int argc, char* argv[] ) {
    try {
		Lexer	lexer( argc, argv);
        lexer.begin();
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}