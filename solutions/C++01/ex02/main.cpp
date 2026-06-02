#include <string>
#include <iostream>
int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* ptrBrain = &brain;
	std::string &refBrain = brain;

	std::cout<<"The memory address of the string variable: "<< &brain<<std::endl;
	std::cout<<"The memory address held by stringPTR: "<< ptrBrain<<std::endl;
	std::cout<<"The memory address held by stringREF: "<< &refBrain<<std::endl;

	std::cout << "The value of the string variable: "<< brain<<std::endl;
	std::cout << "The value pointed to by stringPTR: "<< *ptrBrain<<std::endl;
	std::cout << "The value pointed to by stringREF: " << refBrain<<std::endl;



}
