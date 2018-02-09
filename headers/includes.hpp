#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../headers/Lexer.class.hpp"
#include <list>


//  main.cpp
int		main( int argc, char* argv[] );

//  analyse.cpp
int						begin( Lexer &lexer );
void					std_input( Lexer &lexer );
void					file( Lexer &lexer );
std::list<std::string>	split_string( std::string line );

// lexeme.cpp
void    create_lexeme( std::list<std::string> substr, Lexer &lexer );


