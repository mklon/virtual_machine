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
	while ( std::getline( *lexer.get_file(), line )) {

	}

}

void	std_input( Lexer &lexer ) {
	std::string line;
	while ( line != ";;" ) {
		std::getline( std::cin, line );
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
