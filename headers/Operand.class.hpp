#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

#include "IOperand.class.hpp"
#include "includes.hpp"
#include <iomanip>


template <typename T>
class Operand : public IOperand {
private:
	type        _type;
	int         _precision;
	T           _value;
	std::string _line;

    class OperandExp : public std::exception {
    private:
        std::string     _exptn_msg;
    public:
        OperandExp() {};
        OperandExp( const std::string & text ) : _exptn_msg( text ) {};
        OperandExp( OperandExp const & rhs ) {};

        OperandExp &	operator=( OperandExp const & rhs ) {};

        virtual const   char *what() const throw() {
            return ( _exptn_msg.c_str() );
        };
        virtual ~OperandExp() throw() {};
    };
public:
	Operand() {};
	Operand( Operand const &rhs ) {};

	Operand( type t, std::string value, int precision )
			: _type(t), _value(value), _precision(precision) {
		std::stringstream   stream;
		if (_type <= INT32) {
			long long   data = std::stoll( this->_value );
            if ( !is_size_ok() )
                throw OperandExp("Overflow!");
			_value = static_cast<T>( data );
			stream << std::setprecision( this->_precision ) << data;
		}
		else {
			long double  data = std::stold( this->_value );
            if ( !is_size_ok() )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
			stream << std::setprecision( this->_precision ) << data;
		}
        this->_line = stream.str();
	}

    int Operand::getPrecision() const {
        return ( this->_precision );
    }

    type Operand::getType() const {
        return ( this->_type );
    }

    std::string const& Operand::toString() const {
        return ( this->_line );
    }

    IOperand const* Operand::operator+(IOperand const &rhs) const {

    }

    IOperand const* Operand::operator-(IOperand const &rhs) const {

    }

    IOperand const* Operand::operator*(IOperand const &rhs) const {

    }

    IOperand const* Operand::operator/(IOperand const &rhs) const {

    }

    IOperand const* Operand::operator%(IOperand const &rhs) const {

    }

    IOperand const * createOperand( type t, std::string const & value ) const {

    }

    template <typename T>
    bool    is_size_ok() {
        if ( this->_type == INT8 ) {
            return ( SCHAR_MIN <= this->_value && this->_value <= SCHAR_MIN );
        }
        else if ( this->_type == INT16 ) {
            return ( SHRT_MIN <= this->_value && this->_value <= SHRT_MAX );
        }
        else if ( this->_type == INT32 ) {
            return ( INT_MIN <= this->_value && this->_value <= INT_MAX );
        }
        else if ( this->_type == FLOAT ) {
            return ( FLT_MIN <= this->_value && this->_value <= FLT_MAX );
        }
        else if ( this->_type == DOUBLE ) {
            return ( DBL_MIN <= this->_value && this->_value <= DBL_MAX );
        }
        else
            return ( false );
    }

	const Operand&  operator=( Operand const &rhs );
	~Operand();
};

#endif




