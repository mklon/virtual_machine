#include "../headers/includes.hpp"

void	del( std::list<lexeme> &list ) {
	lexeme *lex;

	while ( !list.empty() ) {
		*lex = list.back();
		list.pop_back();
		delete lex;
	}
}

int		main( int argc, char* argv[] ) {
	try {
		Lexer	lexer( argc, argv );
		begin( lexer );
		Parser	parser;
		parser.set_list( lexer.get_list() );
		parser.start();
	}
	catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
	}
	while ( true )
		;
	return 0;
}
