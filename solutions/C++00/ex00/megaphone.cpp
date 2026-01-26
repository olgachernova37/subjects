#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    
    if (argc == 2)
    {
        int i =0;
        int j =1;
        while(j<=argc)
        {
            std::cout << "debug";
            while(argv[j][i] != '\0')
            {
                if(islower(argv[1][i]))
                {
                    argv[1][j] = (char)toupper(argv[i][j]);
                }
                i++;
            }  
            i=0;
            j++;   
            std::cout << argv[j];
        }    
    }
    return (0);
}
