#include <iostream>
#include <cctype> 
#include <string>

int main(int argc, char** argv)
{
     //std::cout << "debug";
    if (argc >= 2)
    {
      for (int i=1; i<argc; i++)
      {
        std::string slovo = argv[i];
        for (size_t j=0; j<slovo.length(); j++)
        {
            slovo[j]= std::toupper(slovo[j]);

        }
        std::cout <<slovo;
      }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}
