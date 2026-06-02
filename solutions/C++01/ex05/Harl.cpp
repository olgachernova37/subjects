#include "Harl.hpp"

Harl::Harl();

Harl::~Harl();

void complain( std::string level )
{

}

	void Harl::debug( void )
	{
		std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<< endl;

	}

	void info( void )
	{
		std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger! If you did, I wouldn’t be asking for more!"<< endl;
	}
	void error( void )
	{
		std::cout<<"This is unacceptable! I want to speak to the manager now."<< endl;
	}
 	void warning( void )
	{
		std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for
years, whereas you started working here just last month."<< endl;
	}
	
