#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    std::ifstream file(argv[1]);
    for(std::string word; file>>word;)
    {
        std::cout<<word<<std::endl;
    }
    return 0;
}
