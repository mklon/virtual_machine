#ifndef FACTORY_CLASS_HPP
# define FACTORY_CLASS_HPP

#include "includes.hpp"
#include "IOperand.class.hpp"

class   Factory {
private:
    IOperand const* createInt8( std::string const & value ) const;
    IOperand const* createInt16( std::string const & value ) const;
    IOperand const* createInt32( std::string const & value ) const;
    IOperand const* createFloat( std::string const & value ) const;
    IOperand const* createDouble( std::string const & value ) const;
public:
    IOperand const * createOperand( type t, std::string const & value ) const;
};

#endif