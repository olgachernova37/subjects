#include <iostream>
#include <cctype> 
using namespace std;

int main(int argc, char** argv)
{
     //std::cout << "debug";
    if (argc >= 2)
    {
        int i =0;
        int j =1;
        while(j<argc)
        {
           
            while(argv[j][i] != '\0')
            {
                if(islower(argv[j][i]))
                {
                    argv[j][i] = (char)toupper(argv[j][i]);
                }
                i++;
            }  
            i=0;
            std::cout << argv[j];
            std::cout << " ";
            j++;   
        }    
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}
