CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= account
SRC= Account.cpp tests.cpp
HEADERS= Account.hpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

re: clean all
