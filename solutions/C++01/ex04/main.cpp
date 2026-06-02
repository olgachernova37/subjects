#include <fstream>
#include <iostream>
#include <istream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string text;
	std::string line;

	std::ifstream text_file(filename.c_str());
	if (!text_file.is_open())
	{
		std::cout << "Error: could not open file " << filename << std::endl;
		return 1;
	}

	while (std::getline(text_file, line))
	{
    	if (!text.empty())
        	text += "\n";
    	text += line;
	}

	text_file.close();

	std::cout<<"Input:    "<< text<< std::endl;
	size_t pos = text.find(s1);
	while (pos != std::string::npos)
		{
		 text.erase(pos, s1.length());
   		 text.insert(pos, s2);
		 pos = text.find(s1, pos + s2.length());
		}

	std::ofstream fileReplace("fileReplace.txt");
	fileReplace<<text<<std::endl;
	std::cout<<"Replaced: "<<text<< std::endl;
	fileReplace.close();
}

