CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98 
TARGET= crappyPhonebook
SRC= crappyPhonebook.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	chmod +x $(TARGET)
clean:
	rm -f $(TARGET)	

re: clean all