#include "Zombie.hpp"

int main()
{
	int N =5;
	std::string name = "Joe";
	Zombie* horde = zombieHorde(N, name);
	for(int i = 0; i < N; i++)
	{
		horde[i].announce();  // спочатку announce
	}
	delete[] horde;
    return 0;
}
