#include "../headers/includes.hpp"

void    create_lexeme( std::list<std::string> substr, Lexer &lexer ) {
	std::string	cmd;

	cmd = substr.front();
	if ( cmd == "push") {
		std::cout << "it's push" << "\n";
	}
	else if ( cmd == "pop" ) {
		std::cout << "it's pop" << "\n";
	}
	else
		lexer.exception( "Unknown command" );
}