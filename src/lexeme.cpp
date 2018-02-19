#include "../headers/includes.hpp"

void		err_val( Lexer &lexer, lexeme *lex ) {
	delete lex;
	lexer.exception( "Invalid value!" );
}

void		err( Lexer &lexer, lexeme *lex ) {
	delete lex;
	lexer.exception( "Invalid command!" );
}

std::string	value( std::string &line, Lexer &lexer, type l_type, lexeme *lex ) {
	if ( line[0] != '(' || line[line.size() - 1] != ')')
		err_val( lexer, lex );
	line.erase( 0, 1);
	line.erase( line.size() - 1, 1);
	if ( line.find_first_not_of( "+-.0123456789" ) != std::string::npos )
		err_val( lexer, lex );
	if ( l_type == INT8 || l_type == INT16 || l_type == INT32 )
		if ( line.find( '.' ) != std::string::npos )
			err_val( lexer, lex );
	if ( line.find( '+', 1 ) != std::string::npos ||
		 line.find( '-', 1 ) != std::string::npos ||
		 line[0] == '.')
		err_val( lexer, lex );
	unsigned long int	i;
	if ( l_type == FLOAT || l_type == DOUBLE )
		if (( i = line.find( '.' )) != std::string::npos
			&& line.find('.', i + 1) != std::string::npos)
			err_val( lexer, lex );
	return ( line );
}

type		data_type( std::string &data, Lexer &lexer, lexeme *lex ) {
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
	else {
		delete lex;
		lexer.exception( "Wrong type!" );
	}
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
			err( lexer, lex );
		line = substr.front();
		lex->data_type = data_type( line, lexer, lex );
		lex->value = value( line , lexer, lex->data_type, lex );
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
			err( lexer, lex );
	}
	else if (  substr.size() == 0 ) {
		delete lex;
		return ;
	}
	else
		err( lexer, lex );
	lexer.add_lexeme( *lex );
	delete lex;
}