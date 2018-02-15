#ifndef LEXER_CLASS_HPP
# define LEXER_CLASS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <list>

enum	type {
    NON = 0,
    INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE,
};

enum    token {
    EXIT = 0,
    PUSH,
    POP,
    DUMP,
    ASSERT,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    PRINT
};

struct  lexeme {
	token		cmd;
	type 		data_type;
	std::string	value;
};

class   Lexer {
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
    std::ifstream       *_file;
    std::list<lexeme>   _lexemesList;
public:
	Lexer();
	Lexer( Lexer const & rhs );

	std::ifstream	    *get_file();
    std::list<lexeme>   &get_list();

    Lexer( int argc, char *argv[] );
	Lexer &	operator=( Lexer const & rhs );

    void		exception( std::string line );
	void		add_lexeme( lexeme &new_lex );

	~Lexer();
};

#endif
