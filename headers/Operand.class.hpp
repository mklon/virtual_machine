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
    Factory     factory;


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
			: _type(t), _precision( precision ) {
		std::stringstream   stream;
		if (_type <= INT32) {
			long long   data = std::stoll( value );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
			_value = static_cast<T>( data );
			stream << std::setprecision( this->_precision ) << data;
		}
		else {
			long double  data = std::stold( value );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
			stream << std::setprecision( this->_precision ) << data;
		}
        this->_line = stream.str();
	}

    int getPrecision() const {
        return ( this->_precision );
    }

    type getType() const {
        return ( this->_type );
    }

    std::string const& toString() const {
        return ( this->_line );
    }

    IOperand const* operator+(IOperand const &rhs) const {
        type    type = ( this->_type > rhs.getType() )
                       ? this->_type : rhs.getType();
        int     prec = ( this->_precision > rhs.getPrecision() )
                       ? this->_precision : rhs.getPrecision();
        std::stringstream   stream;

        if (_type <= INT32) {
            long long   data = std::stoll( this->_line )
                               + std::stoll( rhs.toString() );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
            stream << std::setprecision( this->_precision ) << data;
        }
        else {
            long double  data = std::stoll( this->_line )
                                + std::stoll( rhs.toString() );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
            stream << std::setprecision( this->_precision ) << data;
        }
        return ( factory.createOperand( type, stream.str() ));

    }

    IOperand const* operator-(IOperand const &rhs) const {
        type    type = ( this->_type > rhs.getType() )
                       ? this->_type : rhs.getType();
        int     prec = ( this->_precision > rhs.getPrecision() )
                       ? this->_precision : rhs.getPrecision();
        std::stringstream   stream;

        if (_type <= INT32) {
            long long   data = std::stoll( this->_line )
                               - std::stoll( rhs.toString() );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
            stream << std::setprecision( this->_precision ) << data;
        }
        else {
            long double  data = std::stoll( this->_line )
                                - std::stoll( rhs.toString() );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
            stream << std::setprecision( this->_precision ) << data;
        }
        return ( factory.createOperand( type, stream.str() ));
    }

    IOperand const* operator*(IOperand const &rhs) const {
        type    type = ( this->_type > rhs.getType() )
                       ? this->_type : rhs.getType();
        int     prec = ( this->_precision > rhs.getPrecision() )
                       ? this->_precision : rhs.getPrecision();
        std::stringstream   stream;

        if (_type <= INT32) {
            long long   data = std::stoll( this->_line )
                               * std::stoll( rhs.toString() );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
            stream << std::setprecision( this->_precision ) << data;
        }
        else {
            long double  data = std::stoll( this->_line )
                                * std::stoll( rhs.toString() );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
            stream << std::setprecision( this->_precision ) << data;
        }
        return ( factory.createOperand( type, stream.str() ));
    }

    IOperand const* operator/(IOperand const &rhs) const {
        type    type = ( this->_type > rhs.getType() )
                       ? this->_type : rhs.getType();
        int     prec = ( this->_precision > rhs.getPrecision() )
                       ? this->_precision : rhs.getPrecision();
        std::stringstream   stream;

        if ( !std::stoll( rhs.toString() ) )
            throw OperandExp("Overflow!");
        if (_type <= INT32) {
            long long   data = std::stoll( this->_line )
                               / std::stoll( rhs.toString() );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
            stream << std::setprecision( this->_precision ) << data;
        }
        else {
            long double  data = std::stoll( this->_line )
                                / std::stoll( rhs.toString() );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
            stream << std::setprecision( this->_precision ) << data;
        }
        return ( factory.createOperand( type, stream.str() ));
    }

    IOperand const* operator%(IOperand const &rhs) const {
        type    type = ( this->_type > rhs.getType() )
                       ? this->_type : rhs.getType();
        int     prec = ( this->_precision > rhs.getPrecision() )
                       ? this->_precision : rhs.getPrecision();
        std::stringstream   stream;

        if ( !std::stoll( rhs.toString() ) )
            throw OperandExp("Overflow!");
        if (_type <= INT32) {
            long long   data = std::stoll( this->_line )
                               % std::stoll( rhs.toString() );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
            stream << std::setprecision( this->_precision ) << data;
        }
        else {
            long double  data = std::stoll( this->_line )
                                % std::stoll( rhs.toString() );
            if ( !is_size_ok( data ) )
                throw OperandExp("Overflow!");
            _value = static_cast<T>( data );
            stream << std::setprecision( this->_precision ) << data;
        }
        return ( factory.createOperand( type, stream.str() ));
    }

    IOperand const * createOperand( type t, std::string const & value ) const {

    }

    template <typename S>
    bool    is_size_ok( S value ) const {
        if ( this->_type == INT8 ) {
            return ( SCHAR_MIN <= value && value <= SCHAR_MIN );
        }
        else if ( this->_type == INT16 ) {
            return ( SHRT_MIN <= value && value <= SHRT_MAX );
        }
        else if ( this->_type == INT32 ) {
            return ( INT_MIN <= value && value <= INT_MAX );
        }
        else if ( this->_type == FLOAT ) {
            return ( FLT_MIN <= value && value <= FLT_MAX );
        }
        else if ( this->_type == DOUBLE ) {
            return ( DBL_MIN <= value && value <= DBL_MAX );
        }
        else
            return ( false );
    }

	const Operand&  operator=( Operand const &rhs ) {};
	~Operand() {};
};

#endif




