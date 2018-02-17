#ifndef INCLUDES_HPP
# define INCLUDES_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Lexer.class.hpp"
#include "Parser.class.hpp"
#include "Factory.class.hpp"
#include "IOperand.class.hpp"
#include "Operand.class.hpp"
#include <list>
#include <map>
#include <climits>
#include <cfloat>


//  main.cpp
int		main( int argc, char* argv[] );

//  analyse.cpp
int						begin( Lexer &lexer );
void					std_input( Lexer &lexer );
void					file( Lexer &lexer );
std::list<std::string>	split_string( std::string line );

// lexeme.cpp
void                    create_lexeme( std::list<std::string> substr, Lexer &lexer );
type		            data_type( std::string &data, Lexer &lexer );
std::string             value( std::string &line, Lexer &lexer, type l_type );


#endif