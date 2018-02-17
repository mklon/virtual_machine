#ifndef PARSER_CLASS_HPP
# define PARSER_CLASS_HPP

#include "Factory.class.hpp"
#include "IOperand.class.hpp"
#include <map>

class   Parser {
private:
	std::list<const IOperand*>           	_stack;
	std::list<lexeme>		            	_lexemesList;
	std::map<token, void (Parser::*)()>		_command;
    Factory                                 _create;

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

	void    start();

    void    push();
    void    pop();
    void    dump();
    void    assert();
    void    add();
    void    sub();
    void    mul();
    void    div();
    void    mod();
    void    print();

    void    set_list( std::list<lexeme> new_list );

	Parser  &operator=( Parser const & rhs );
	~Parser();
};

#endif
