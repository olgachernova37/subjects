CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= program
SRC= main.cpp Fixed.cpp
HEADERS= Fixed.hpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)
clean:
	rm -f $(TARGET)

re: clean all
