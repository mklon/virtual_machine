#include "../headers/includes.hpp"

Lexer::Lexer() {}

Lexer::Lexer( int argc, char **argv ) {
    if ( argc > 2 )
        throw ( LexerExp( "Lexer: too many arguments!" ));
    else if ( argc == 2 ) {
        this->_file->open(argv[1], std::ios_base::in);
        if ( !_file->is_open() )
            throw ( LexerExp( "Lexer: invalid file!" ));
    }
    else
        this->_file = NULL;
}

Lexer::Lexer( Lexer const &rhs ) {
    *this = rhs;
}

Lexer           &Lexer::operator=( Lexer const &rhs ) {

    return (*this);
}

void            Lexer::exception( std::string line ) {
    throw ( LexerExp( line ));
}

std::string     Lexer::erase(std::string line) {
    unsigned long int   i;
    while (( i = line.find(' ') ) <= line.size() )
        line.erase( i, 1 );
    while (( i = line.find('\t') ) <= line.size() )
        line.erase( i, 1 );
    return ( line );
}


std::ifstream   *Lexer::get_file() {
    return ( _file );
}


Lexer::~Lexer() {}











// LexerExp

Lexer::LexerExp::LexerExp() {}


Lexer::LexerExp::LexerExp( const std::string & text ) {
    this->_exptn_msg = text;
}

const   char* Lexer::LexerExp::what() const throw() {
    return ( this->_exptn_msg.c_str() );
}

Lexer::LexerExp::~LexerExp() throw() {}