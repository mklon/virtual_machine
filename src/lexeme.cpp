#include "../headers/includes.hpp"

std::string	value( std::string &line, Lexer &lexer, type l_type ) {
	if ( line[0] != '(' || line[line.size() - 1] != ')')
		lexer.exception( "Invalid command!" );
	line.erase( 0, 1);
	line.erase( line.size() - 1, 1);
	if ( line.find_first_not_of( "+-.0123456789" ) != std::string::npos )
		lexer.exception( "Invalid value!" );
	if ( l_type == INT8 || l_type == INT16 || l_type == INT32 )
		if ( line.find( '.' ) != std::string::npos )
			lexer.exception( "Invalid value!" );
	if ( line.find( '+', 1 ) != std::string::npos ||
		 line.find( '-', 1 ) != std::string::npos )
		lexer.exception( "Invalid value!" );
	return ( line );
}

type		data_type( std::string &data, Lexer &lexer ) {
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

void		create_lexeme( std::list<std::string> substr, Lexer &lexer ) {
	std::string	line;

    if ( substr.empty() )
        return ;
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
			lexer.exception( "Invalid command" );
		line = substr.front();
		lex->data_type = data_type( line, lexer );
		lex->value = value( line , lexer, lex->data_type );
	}
	else if ( substr.size() == 1 ) {
        lex->data_type = NON;
        lex->value = "";
		if ( line == "pop") {
			lex->cmd = POP;
		}
		else if ( line == "dump") {
			lex->cmd = DUMP;
		}
		else if ( line == "add" ) {
			lex->cmd = ADD;
		}
		else if ( line == "sub" ) {
			lex->cmd = SUB;
		}
		else if ( line == "mul" ) {
			lex->cmd = MUL;
		}
		else if ( line == "div" ) {
			lex->cmd = DIV;
		}
		else if ( line == "mod" ) {
			lex->cmd = MOD;
		}
		else if ( line == "print" ) {
			lex->cmd = PRINT;
		}
		else if ( line == "exit" ) {
			lex->cmd = EXIT;
		}
		else
			lexer.exception( "Invalid command" );
	}
	else if (  substr.size() == 0 ) {
		delete lex;
		return ;
	}
	else
		lexer.exception( "Invalid command" );
	lexer.add_lexeme( *lex );
}