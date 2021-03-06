#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

#include "IOperand.class.hpp"
#include "includes.hpp"
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cmath>

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
		OperandExp( OperandExp const & rhs ) {
			*this = rhs;
		};

		OperandExp &	operator=( OperandExp const & rhs ) {
			this->_exptn_msg = rhs._exptn_msg;
			return ( *this );
		};

		virtual const   char *what() const throw() {
			return ( _exptn_msg.c_str() );
		};
		virtual ~OperandExp() throw() {};
	};
public:
	Operand() {};
	Operand( Operand const &rhs ) {
		*this = rhs;
	};

	Operand( type t, std::string value, int precision )
			: _type(t), _precision( precision ) {
		std::stringstream   stream;
		if (_type <= INT32) {
			long long   data = std::stoll( value );
			if ( !is_size_ok( data, t ) )
				throw OperandExp("Data type overflow!");
			_value = static_cast<T>( data );
			stream << std::setprecision( this->_precision ) << data;
		}
		else {
			long double  data = std::stold( value );
			if ( !is_size_ok( data, t ) )
				throw OperandExp("Data type overflow!");
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

		if ( type <= INT32) {
			long long   data = std::stoll( this->_line )
							   + std::stoll( rhs.toString() );
			if ( !is_size_ok( data, type ) )
				throw OperandExp("Data type overflow!");
			stream << std::setprecision( prec ) << data;
		}
		else {
			long double  data = std::stold( this->_line )
								+ std::stold( rhs.toString() );
			if ( !is_size_ok( data, type ) )
				throw OperandExp("Data type overflow!");
			stream << std::setprecision( prec ) << data;
		}
		return ( factory.createOperand( type, stream.str() ));

	}

	IOperand const* operator-(IOperand const &rhs) const {
		type    type = ( this->_type > rhs.getType() )
					   ? this->_type : rhs.getType();
		int     prec = ( this->_precision > rhs.getPrecision() )
					   ? this->_precision : rhs.getPrecision();
		std::stringstream   stream;

		if ( type <= INT32) {
			long long   data = std::stoll( this->_line )
							   - std::stoll( rhs.toString() );
			if ( !is_size_ok( data, type ) )
				throw OperandExp("Data type overflow!");
			stream << std::setprecision( prec ) << data;
		}
		else {
			long double  data = std::stold( this->_line )
								- std::stold( rhs.toString() );
			if ( !is_size_ok( data, type ) )
				throw OperandExp("Data type overflow!");
			stream << std::setprecision( prec ) << data;
		}
		return ( factory.createOperand( type, stream.str() ));
	}

	IOperand const* operator*(IOperand const &rhs) const {
		type    type = ( this->_type > rhs.getType() )
					   ? this->_type : rhs.getType();
		int     prec = ( this->_precision > rhs.getPrecision() )
					   ? this->_precision : rhs.getPrecision();
		std::stringstream   stream;

		if ( type <= INT32) {
			long long   data = std::stoll( this->_line )
							   * std::stoll( rhs.toString() );
			if ( !is_size_ok( data, type ) )
				throw OperandExp("Data type overflow!");
			stream << std::setprecision( prec ) << data;
		}
		else {
			long double  data = std::stold( this->_line )
								* std::stold( rhs.toString() );
			if ( !is_size_ok( data, type ) )
				throw OperandExp("Data type overflow!");
			stream << std::setprecision( prec ) << data;
		}
		return ( factory.createOperand( type, stream.str() ));
	}

	IOperand const* operator/(IOperand const &rhs) const {
		type    type = ( this->_type > rhs.getType() )
					   ? this->_type : rhs.getType();
		int     prec = ( this->_precision > rhs.getPrecision() )
					   ? this->_precision : rhs.getPrecision();
		std::stringstream   stream;

		if ( !std::stold( rhs.toString() ) )
			throw OperandExp("Division by 0!");
		if ( type <= INT32) {
			long long   data = std::stoll( this->_line )
							   / std::stoll( rhs.toString() );
			if ( !is_size_ok( data, type ) )
				throw OperandExp("Data type overflow!");
			stream << std::setprecision( prec ) << data;
		}
		else {
			long double  data = std::stold( this->_line )
								/ std::stold( rhs.toString() );
			if ( !is_size_ok( data, type ) )
				throw OperandExp("Data type overflow!");
			stream << std::setprecision( prec ) << data;
		}
		return ( factory.createOperand( type, stream.str() ));
	}

	IOperand const* operator%(IOperand const &rhs) const {
		type    type = ( this->_type > rhs.getType() )
					   ? this->_type : rhs.getType();
		int     prec = ( this->_precision > rhs.getPrecision() )
					   ? this->_precision : rhs.getPrecision();
		std::stringstream   stream;

		if ( !std::stold( rhs.toString() ) )
			throw OperandExp("Mod by 0!");
		if ( type <= INT32) {
			long long   data = std::stoll( this->_line )
							   % std::stoll( rhs.toString() );
			if ( !is_size_ok( data, type ) )
				throw OperandExp("Data type overflow!");
			stream << std::setprecision( prec ) << data;
		}
		else {
			long double  data = std::fmod(std::stold( this->_line ),
										  std::stold( rhs.toString() ));
			if ( !is_size_ok( data, type ) )
				throw OperandExp("Data type overflow!");
			stream << std::setprecision( prec ) << data;
		}
		return ( factory.createOperand( type, stream.str() ));
	}

	template <typename S>
	bool    is_size_ok( S value, type t ) const {
		if ( t == INT8 ) {
			return ( SCHAR_MIN <= value && value <= SCHAR_MAX );
		}
		else if ( t == INT16 ) {
			return ( SHRT_MIN <= value && value <= SHRT_MAX );
		}
		else if ( t == INT32 ) {
			return ( INT_MIN <= value && value <= INT_MAX );
		}
		else if ( t == FLOAT ) {
			return ( -FLT_MAX <= value && value <= FLT_MAX );
		}
		else if ( t == DOUBLE ) {
			return ( -DBL_MAX <= value && value <= DBL_MAX );
		}
		else
			return ( false );
	}

	const Operand&  operator=( Operand const &rhs ) {
		this->_line = rhs._line;
		this->_precision = rhs._precision;
		this->_type = rhs._type;
		this->_value = rhs._value;
		this->factory = rhs.factory;
		return ( *this );
	};
	~Operand() {};
};

#endif
