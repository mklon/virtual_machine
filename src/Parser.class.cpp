#include "../headers/Parser.class.hpp"

Parser::Parser() {
    _command[PUSH] = &Parser::push;
    _command[POP] = &Parser::pop;
    _command[DUMP] = &Parser::dump;
    _command[ASSERT] = &Parser::assert;
    _command[ADD] = &Parser::add;
    _command[SUB] = &Parser::sub;
    _command[MUL] = &Parser::mul;
    _command[DIV] = &Parser::div;
    _command[MOD] = &Parser::mod;
    _command[PRINT] = &Parser::print;
}

Parser::Parser(Parser const &rhs) {
	*this = rhs;
}

void Parser::start() {
	while ( !_lexemesList.empty() ) {
		if ( _lexemesList.front().cmd == EXIT )
			return ;

	}
	throw ParserExp("The program doesn’t have an exit instruction!");
}

void Parser::set_list(std::list<lexeme> new_list) {
    this->_lexemesList = new_list;
}

void    Parser::push() {

}

void    Parser::pop() {

}

void    Parser::dump() {

}

void    Parser::assert() {

}

void    Parser::add() {

}

void    Parser::sub() {

}

void    Parser::mul() {

}

void    Parser::div() {

}

void    Parser::mod() {

}

void    Parser::print() {

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