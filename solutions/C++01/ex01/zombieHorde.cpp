#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[N];  // викликає Zombie() N разів

    // Крок 2: Дати кожному ім'я вручну
    for (int i = 0; i < N; i++)
    {
        horde[i].setname(name);
    }

    return horde;
}
