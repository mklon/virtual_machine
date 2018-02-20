#include "../headers/includes.hpp"

void    error( std::list<std::string> e_list, Lexer &lexer ) {
    int     num = e_list.size();

    while ( !e_list.empty() ) {
        std::cout << e_list.front() << "\n";
        e_list.pop_front();
    }
    lexer.exception( std::to_string( num ) + " errors were generated!" );
}

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
    int                     num = 0;
    std::list<std::string>  error_list;

	while ( std::getline( *lexer.get_file(), line )) {
        num++;
		try {
			create_lexeme(split_string(line), lexer);
		}
		catch ( std::exception &e ) {
            std::string name;

            name = "Line " + std::to_string( num ) +": " + e.what();
            error_list.push_back( name );
		}
	}
    if ( !error_list.empty() )
        error( error_list, lexer );
}

void	std_input( Lexer &lexer ) {
	std::string line;
	int                     num = 0;
	std::list<std::string>  error_list;

	while ( true ) {
		try {
			std::getline(std::cin, line);
			num++;
			if (line == ";;")
				break;
			create_lexeme(split_string(line), lexer);
		}
		catch ( std::exception &e ) {
			std::string name;

            name = "Line " + std::to_string( num ) +": \t" + e.what();
            error_list.push_back( name );
		}
	}
    if ( !error_list.empty() )
        error( error_list, lexer );
}

int     begin( Lexer &lexer ) {

	if ( lexer.get_file() )
		file( lexer );
	else
		std_input( lexer );
	return ( 0 );
}
