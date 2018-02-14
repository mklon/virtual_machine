#ifndef PARSER_HPP
# define PARSER_HPP

#include "includes.hpp"
#include "IOperand.class.hpp"

class   Parser {
private:
	std::list<IOperand*>	_stack;
	std::list<lexeme>		_lexemesList;

	class ParserExp : public std::exception {
	private:
		std::string		_exptn_msg;
	public:
		ParserExp();
		ParserExp( const std::string & text );
		ParserExp( ParserExp const & rhs );

		ParserExp &	operator=( ParserExp const & rhs );

		virtual const   char *what() const throw();
		virtual ~ParserExp() throw();
	};
public:
	Parser();
	Parser( Parser const & rhs );
    Parser( std::list<lexeme> lexeme );

	void    start();

	Parser  &operator=( Parser const & rhs );
	~Parser();
};

#endif
