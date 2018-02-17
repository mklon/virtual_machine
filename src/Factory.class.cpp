#include "../headers/includes.hpp"

Factory::Factory() {
	_method[INT8] = &Factory::createInt8;
	_method[INT16] = &Factory::createInt16;
	_method[INT32] = &Factory::createInt32;
	_method[FLOAT] = &Factory::createFloat;
	_method[DOUBLE] = &Factory::createDouble;
}

Factory::Factory(Factory const &rhs) {
	*this = rhs;
}

IOperand const* Factory::createInt8( std::string const &value ) const {
	return ( new Operand<char>( INT8, value, 0 ) );
}

IOperand const* Factory::createInt16( std::string const &value ) const {
	return ( new Operand<short int>( INT16, value, 0 ) );
}

IOperand const* Factory::createInt32( std::string const &value ) const {
	return ( new Operand<int>( INT32, value, 0 ) );
}

IOperand const* Factory::createFloat( std::string const &value ) const {
	return ( new Operand<float>( FLOAT, value, 7 ) );
}

IOperand const* Factory::createDouble( std::string const &value ) const {
	return ( new Operand<double>( DOUBLE, value, 14 ) );
}

IOperand const* Factory::createOperand( type t, std::string const &value ) const {
    return ( ((this->*_method.at( (int)t ))( value )) );
}

Factory&        Factory::operator=( Factory const &rhs ) {
	this->_method = rhs._method;
	return ( *this );
}

Factory::~Factory() {}