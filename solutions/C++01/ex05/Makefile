CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= harl
SRC= main.cpp Harl.cpp
HEADERS= Harl.hpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)
clean:
	rm -f $(TARGET)

re: clean all
