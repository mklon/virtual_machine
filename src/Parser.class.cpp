#include "../headers/includes.hpp"

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
		lexeme l = _lexemesList.front();
		lexeme l1 = _lexemesList.front();

		(this->*_command.at( _lexemesList.front().cmd ))();
		_lexemesList.pop_front();
	}
	throw ParserExp("The program doesn’t have an exit instruction!");
}

void Parser::set_list( std::list<lexeme> new_list ) {
	this->_lexemesList = new_list;
}

void    Parser::push() {
	_stack.push_back( _create.createOperand( _lexemesList.front().data_type, _lexemesList.front().value ) );
}

void    Parser::pop() {
	if ( _stack.empty() )
		throw ParserExp( "Trying to pop empty stack!" );
	_stack.pop_back();
}

void    Parser::dump() {
	if ( _stack.empty() )
		throw ParserExp( "Trying to dump empty stack!" );
	std::list<const IOperand*>::iterator it = _stack.end();
	while ( it-- != _stack.begin() )
		std::cout << (*it)->toString() << "\n";
}

void    Parser::assert() {
	if ( _stack.empty() )
		throw ParserExp( "Trying to assert empty stack!" );
	if ( _stack.back()->getType() != _lexemesList.front().data_type ||
		_stack.back()->toString() != _lexemesList.front().value)
        throw ParserExp( "The assert instruction was failed!" );
}

void    Parser::add() {
    if ( _stack.size() < 2 )
        throw ParserExp( "Too less values in the stack to add!" );
    const IOperand* first = _stack.back();
    _stack.pop_back();
    const IOperand* second = _stack.back();
    _stack.pop_back();
    const IOperand* result = *first + *second;
    _stack.push_back( result );
    delete( first );
    delete( second );
}

void    Parser::sub() {
    /*const IOperand* first;
    const IOperand* second;
    const IOperand* result;

    *first = *_stack.back();
    _stack.pop_back();
    *second = *_stack.back();
    _stack.pop_back();
    result = *first - *second;
    _stack.push_back( result );

    delete( first );
    delete( second );*/
}

void    Parser::mul() {
	std::cout << "mull" << "\n";
}

void    Parser::div() {
	std::cout << "div" << "\n";
}

void    Parser::mod() {
	std::cout << "mod" << "\n";
}

void    Parser::print() {
	std::cout << "print" << "\n";
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