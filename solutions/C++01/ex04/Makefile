CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
TARGET= replace
SRC= main.cpp


INCLUDES= -I.
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(INCLUDES) -o $(TARGET)
	chmod +x $(TARGET)
clean:
	rm -f $(TARGET)

re: clean all
