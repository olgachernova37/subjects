#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <

class Harl
{
	private:
		 void debug( void );
		 void info( void );
		 void error( void );
 		 void warning( void );


	public:
		void complain( std::string level );

}

#endif
