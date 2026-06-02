CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= zombiehorde
SRC= main.cpp Zombie.cpp zombieHorde.cpp
HEADERS= Zombie.hpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)
clean:
	rm -f $(TARGET)

re: clean all
