CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98 
TARGET= megaphone
SRC= megaphone.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)
clean:
	rm -f $(TARGET)	

re: clean all

PHONY: all clean re