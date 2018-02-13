#include "../headers/includes.hpp"

void    cat_lexemes( std::list<lexeme> lxm ) {
	int     n = 0;

    while ( !lxm.empty() ) {
		std::cout << ++n << "'st lexeme: " << "\n";
		std::cout << "\ttoken > " << lxm.front().cmd << "\n";
		std::cout << "\ttype > " << lxm.front().data_type << "\n";
		std::cout << "\tvalue > " << lxm.front().value << "\n";
		lxm.pop_front();
	}
}

int		main( int argc, char* argv[] ) {
	try {
		Lexer	lexer( argc, argv );
		begin( lexer );
		cat_lexemes( lexer.get_list() );
	}
	catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
