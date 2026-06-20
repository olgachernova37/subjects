CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= program
SRC= main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
HEADERS= AMateria.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp \
         ICharacter.hpp IMateriaSource.hpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)

clean:
	rm -f $(TARGET)

re: clean all
