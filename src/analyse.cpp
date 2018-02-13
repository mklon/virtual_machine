#include "../headers/includes.hpp"

std::list<std::string>	split_string( std::string line ) {
	std::string 			subs;
	std::istringstream 		iss( line );
	std::list<std::string>	substr;
	unsigned long int		i;

	while ( true ) {
		iss >> subs;
		if ( subs.empty() )
			break;
		if (( i = subs.find( ';' )) != std::string::npos ) {
			subs.erase( subs.begin() + i, subs.end() );
			if ( !subs.empty() )
				substr.push_back( subs );
			break;
		}
		else
			substr.push_back( subs );
		subs = "";
	}
	return ( substr );
}

void	file( Lexer &lexer ) {
	std::string line;
	while ( std::getline( *lexer.get_file(), line ))
		create_lexeme( split_string( line ), lexer);
}

void	std_input( Lexer &lexer ) {
	std::string line;
	while ( true) {
		std::getline( std::cin, line );
		if ( line == ";;" )
			break ;
		create_lexeme( split_string( line ), lexer);
	}
}

int     begin( Lexer &lexer ) {

	if ( lexer.get_file() )
		file( lexer );
	else
		std_input( lexer );
	return ( 0 );
}
