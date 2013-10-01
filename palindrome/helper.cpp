#include <iostream>
#include <fstream>
#include <unistd.h>

int main(int argc, char* argv[]) 
{
    if (argc < 2) 
    {
        std::cout << "usage: a.txt" << std::endl;
        return 0;
    }

    if (access(argv[1], R_OK) != 0) 
    {
        std::cout << argv[1] << " is not available"<< std::endl;
        return 0;
    }

    std::ifstream OriFile(argv[1]);
    std::ofstream NewFile;
    std::string strLine;
    int nu = 1;
    int i;

    NewFile.open("new.dict.txt", std::ofstream::out | std::ofstream::app);

    while (std::getline(OriFile, strLine)) 
    {
        std::cout << nu << ": " << strLine << std::endl;
        NewFile << strLine << '\n';
        
        for (i = 0; i < 2; i++)
            std::getline(OriFile, strLine);
        
        nu++;
    }
    
    return 0;
}
