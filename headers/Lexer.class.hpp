#ifndef LEXER_CLASS_HPP
# define LEXER_CLASS_HPP

#include <iostream>
#include <fstream>
#include <string>

enum    token {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    POP,
    DUMP,
    ASSERT,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    PRINT,
    EXIT
};

struct  lexeme {
	token		cmd;
	std::string	value;
};

class Lexer {
private:
    class LexerExp : public std::exception {
    private:
        std::string     _exptn_msg;
    public:
        LexerExp();
        LexerExp( const std::string & text );
        LexerExp( LexerExp const & rhs );

        LexerExp &	operator=( LexerExp const & rhs );

        virtual const   char *what() const throw();
        virtual ~LexerExp() throw();
    };
    std::ifstream   *_file;
public:
	Lexer();
	Lexer( Lexer const & rhs );

	std::ifstream	*get_file();

	Lexer( int argc, char *argv[] );
	Lexer &	operator=( Lexer const & rhs );

    void        exception( std::string line );
    std::string erase( std::string line );

	~Lexer();
};

#endif
