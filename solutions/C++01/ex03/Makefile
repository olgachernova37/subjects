CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= violence
SRC= main.cpp Weapon.cpp
HEADERS= Weapon.hpp

INCLUDES= -I.
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(INCLUDES) -o $(TARGET)
	chmod +x $(TARGET)
clean:
	rm -f $(TARGET)

re: clean all
