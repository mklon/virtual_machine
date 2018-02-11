#include "../headers/includes.hpp"

int		main( int argc, char* argv[] ) {
    try {
		Lexer	lexer( argc, argv );
        begin( lexer );
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}
