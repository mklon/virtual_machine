#include "../headers/includes.hpp"

Lexer::Lexer() {}

Lexer::Lexer( int argc, char **argv ) {
    if ( argc > 2 )
        throw ( LexerExp( "Too many arguments!" ));
    else if ( argc == 2 ) {
        std::ifstream *file = new std::ifstream;
        this->_file = file;
		this->_file->open(argv[1], std::ios_base::in);
		if ( !_file->is_open() )
			throw ( LexerExp( "Invalid file!" ));
    }
    else
        this->_file = NULL;
}

Lexer::Lexer( Lexer const &rhs ) {
    *this = rhs;
}

Lexer				&Lexer::operator=( Lexer const &rhs ) {
    this->_lexemesList = rhs._lexemesList;
    this->_file = rhs._file;
    return (*this);
}

void				Lexer::exception( std::string line ) {
    throw ( LexerExp( line ));
}

void				Lexer::add_lexeme( lexeme &new_lex ) {
	this->_lexemesList.push_back( new_lex );
}

std::ifstream		*Lexer::get_file() {
    return ( _file );
}

std::list<lexeme>	&Lexer::get_list() {
    return ( _lexemesList );
}

Lexer::~Lexer() {}


// LexerExp
Lexer::LexerExp::LexerExp() {}


Lexer::LexerExp::LexerExp( const std::string & text ) {
    this->_exptn_msg = text;
}

Lexer::LexerExp::LexerExp(LexerExp const &rhs) {
    *this = rhs;
}

const   char* Lexer::LexerExp::what() const throw() {
    return ( this->_exptn_msg.c_str() );
}

Lexer::LexerExp& Lexer::LexerExp::operator=(LexerExp const &rhs) {
    this->_exptn_msg = rhs._exptn_msg;
    return ( *this );
}

Lexer::LexerExp::~LexerExp() throw() {}
