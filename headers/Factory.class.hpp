#ifndef FACTORY_CLASS_HPP
# define FACTORY_CLASS_HPP

#include "IOperand.class.hpp"
#include <map>

class   Factory {
private:
    std::map<int, IOperand const * ( Factory::* )( std::string const & value ) const>   _method;

    IOperand const* createInt8( std::string const & value ) const;
    IOperand const* createInt16( std::string const & value ) const;
    IOperand const* createInt32( std::string const & value ) const;
    IOperand const* createFloat( std::string const & value ) const;
    IOperand const* createDouble( std::string const & value ) const;
public:
    Factory();
    Factory( Factory const & rhs );

    Factory   &operator=( Factory const & rhs );

    IOperand const * createOperand( type t, std::string const & value ) const;

    ~Factory();
};

#endif