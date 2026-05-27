#include "Zombie.hpp"

int main()
{
	int N =5;
	std::string name = "Joe";
	Zombie* zombieHorde(N, name);
	for(int i=0; i<N; i++)
	{
		delete Zombie[i];
	}
    return 0;
}
