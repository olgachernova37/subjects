#include "Zombie.hpp"

int main()
{
    // === HEAP (newZombie) ===
    // Зомбі створюється в heap, живе поки не викличемо delete
    Zombie* heapZombie = newZombie("Heap_Zombie");
    heapZombie->announce();

    // === STACK (randomChump) ===
    // Зомбі створюється в stack, знищується автоматично після виходу з функції
    randomChump("Stack_Zombie");

    // Тут Stack_Zombie вже знищений (побачиш повідомлення деструктора)
    // А Heap_Zombie ще живий!

    // Видаляємо heap зомбі вручну
    delete heapZombie;

    return 0;
}
