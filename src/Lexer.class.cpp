#include "../headers/Lexer.class.hpp"

Lexer::Lexer() {}

Lexer::Lexer( int argc, char **argv ) {
    if ( argc > 2 )
        throw ( LexerExp( "Lexer: too many arguments!" ));
    else if ( argc == 2 ) {
        this->_file.open(argv[1], std::ios_base::in);
        if ( !_file.is_open() )
            throw ( LexerExp( "Lexer: invalid file!" ));
    }

}

Lexer::LexerExp::LexerExp() {}


Lexer::LexerExp::LexerExp( const std::string & text ) {
    this->_exptn_msg = text;
}

const   char* Lexer::LexerExp::what() const throw() {
    return ( this->_exptn_msg.c_str() );
}

Lexer::LexerExp::~LexerExp() throw() {}

Lexer::Lexer( Lexer const &rhs ) {}

Lexer&  Lexer::operator=( Lexer const &rhs ) {

}

void    Lexer::begin() {
}

Lexer::~Lexer() {}