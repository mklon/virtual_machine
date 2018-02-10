#include "../headers/includes.hpp"

void	value( std::string &data, Lexer &lexerm, type l_type ) {
	
}

type	data_type( std::string &data, Lexer &lexer ) {
	if ( !data.compare( 0, 5, "int8(" )) {
		data.erase( 0, 4 );
		return ( INT8 );
	}
	else if ( !data.compare( 0, 6, "int16(" )) {
		data.erase( 0, 5 );
		return ( INT16 );
	}
	else if ( !data.compare( 0, 6, "int32(" )) {
		data.erase( 0, 5 );
		return ( INT32 );
	}
	else if ( !data.compare( 0, 6, "float(" )) {
		data.erase( 0, 5 );
		return ( FLOAT );
	}
	else if ( !data.compare( 0, 7, "double(" )) {
		data.erase( 0, 6 );
		return ( DOUBLE );
	}
	else
		lexer.exception( "Wrong type!" );
	return ( NON );
}

void    create_lexeme( std::list<std::string> substr, Lexer &lexer ) {
	std::string	line;

	line = substr.front();
	lexeme	*lex = new lexeme;
	if ( substr.size() == 2 ) {
		substr.pop_front();
		if ( line == "push") {
			lex->cmd = PUSH;
		}
		else if ( line == "assert") {
			lex->cmd = ASSERT;
		}
		else
			lexer.exception( "Unknown command" );
		line = substr.front();
		lex->data_type = data_type( line, lexer );
		std::cout << line << "\n";
	}
	else if ( substr.size() == 1 ) {

	}
	else
		lexer.exception( "Unknown command" );
}