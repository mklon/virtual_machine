#ifndef LEXER_CLASS_HPP
# define LEXER_CLASS_HPP

#include <fstream>

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
    std::ifstream   _file;
public:
	Lexer();
	Lexer( Lexer const & rhs );
    Lexer( int argc, char *argv[] );
	Lexer &	operator=( Lexer const & rhs );

    void    begin();

	~Lexer();
};

#endif
