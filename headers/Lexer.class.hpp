#ifndef LEXER_CLASS_HPP
# define LEXER_CLASS_HPP

#include <iostream>

class Lexer {
private:
    class LexerExp : public std::exception {
        LexerExp();
        LexerExp( LexerExp const & rhs );

        LexerExp &	operator=( LexerExp const & rhs );
        ~LexerExp();
    };
public:
	Lexer();
	Lexer( Lexer const & rhs );
    Lexer( int argc, char *argv[] );

	Lexer &	operator=( Lexer const & rhs );
	~Lexer();
};

#endif