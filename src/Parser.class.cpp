#include "../headers/Parser.class.hpp"

Parser::Parser() {}

Parser::Parser(Parser const &rhs) {
	*this = rhs;
}

Parser::Parser(std::list<lexeme> lexeme) : _lexemesList( lexeme ) {}

void Parser::start() {
	while ( !_lexemesList.empty() ) {
        if ( _lexemesList.front().cmd == EXIT )
            return ;
        
	}
	throw ParserExp("The program doesn’t have an exit instruction!");
}

Parser& Parser::operator=(Parser const &rhs) {
	//!!!!!!!!
	return ( *this );
}

Parser::~Parser() {}

// ParserExp
Parser::ParserExp::ParserExp() {}


Parser::ParserExp::ParserExp( const std::string & text ) {
	this->_exptn_msg = text;
}

const   char* Parser::ParserExp::what() const throw() {
	return ( this->_exptn_msg.c_str() );
}

Parser::ParserExp::~ParserExp() throw() {}