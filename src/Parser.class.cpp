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
    bool    flag = true;
    std::list<lexeme>::iterator it = _lexemesList.end();
    while ( it-- != _lexemesList.begin() )
        if ( (*it).cmd == EXIT ) {
            flag = false;
            break ;
        }
    if ( flag )
        throw ParserExp("The program doesn’t have an exit instruction!");

    while ( !_lexemesList.empty() ) {
		if ( _lexemesList.front().cmd == EXIT )
			return ;
		lexeme l = _lexemesList.front();
		lexeme l1 = _lexemesList.front();

		(this->*_command.at( _lexemesList.front().cmd ))();
		_lexemesList.pop_front();
	}
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
	const IOperand* next;

	next = _stack.back();
	_stack.pop_back();
	delete next;
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

    std::list<const IOperand*>::iterator    it = _stack.end();

    const IOperand* result = *_stack.back() + **(--(--it));
	const IOperand* next;

	next = _stack.back();
	_stack.pop_back();
	delete next;
	next = _stack.back();
	_stack.pop_back();
	delete next;
    _stack.push_back( result );
}

void    Parser::sub() {
    if ( _stack.size() < 2 )
        throw ParserExp( "Too less values in the stack to sub!" );

    std::list<const IOperand*>::iterator    it = _stack.end();

    const IOperand* result = *_stack.back() - **(--(--it));
	const IOperand* next;

	next = _stack.back();
	_stack.pop_back();
	delete next;
	next = _stack.back();
	_stack.pop_back();
	delete next;
    _stack.push_back( result );
}

void    Parser::mul() {
    if ( _stack.size() < 2 )
        throw ParserExp( "Too less values in the stack to mul!" );

    std::list<const IOperand*>::iterator    it = _stack.end();

    const IOperand* result = *_stack.back() * **(--(--it));
	const IOperand* next;

	next = _stack.back();
    _stack.pop_back();
	delete next;
	next = _stack.back();
	_stack.pop_back();
	delete next;
    _stack.push_back( result );
}

void    Parser::div() {
    if ( _stack.size() < 2 )
        throw ParserExp( "Too less values in the stack to div!" );

    std::list<const IOperand*>::iterator    it = _stack.end();

    const IOperand* result = *_stack.back() / **(--(--it));
	const IOperand* next;

	next = _stack.back();
	_stack.pop_back();
	delete next;
	next = _stack.back();
	_stack.pop_back();
	delete next;
    _stack.push_back( result );
}

void    Parser::mod() {
    if ( _stack.size() < 2 )
        throw ParserExp( "Too less values in the stack to mod!" );

    std::list<const IOperand*>::iterator    it = _stack.end();

    const IOperand* result = *_stack.back() % **(--(--it));
	const IOperand* next;

	next = _stack.back();
	_stack.pop_back();
	delete next;
	next = _stack.back();
	_stack.pop_back();
	delete next;
    _stack.push_back( result );
}

void    Parser::print() {
    if ( _stack.empty() )
        throw ParserExp( "Trying to prints empty stack!" );
	if ( _stack.back()->getType() != INT8 )
        throw ParserExp( "Wrong type for print!" );
    std::cout << static_cast<char>( std::stoi(_stack.back()->toString()) ) << "\n";
}

Parser& Parser::operator=(Parser const &rhs) {
	this->_lexemesList = rhs._lexemesList;
    this->_stack = rhs._stack;
    this->_create = rhs._create;
    this->_command = rhs._command;
	return ( *this );
}

Parser::~Parser() {

	const IOperand* next;

	while ( !_stack.empty() ) {
		next = _stack.back();
		_stack.pop_back();
		delete next;
	}

}



// ParserExp
Parser::ParserExp::ParserExp() {}


Parser::ParserExp::ParserExp( const std::string & text ) {
	this->_exptn_msg = text;
}

Parser::ParserExp::ParserExp( ParserExp const &rhs ) {
    *this = rhs;
}

const   char* Parser::ParserExp::what() const throw() {
	return ( this->_exptn_msg.c_str() );
}

Parser::ParserExp& Parser::ParserExp::operator=(ParserExp const &rhs) {
    this->_exptn_msg = rhs._exptn_msg;
    return ( *this );
}

Parser::ParserExp::~ParserExp() throw() {}