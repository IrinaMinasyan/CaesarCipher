#include <string>
#include "caesarcipher.h"

File::File():shifting{3}
{
    fin.open("code.txt");
    ret.open("decode.txt");
    if(fin.is_open())
    {
        std::cout << "The file is opened" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}
File::~File()
{
    fin.close();
    ret.close();
}


void File::decode()
{
    std::string res = "";
    if(!(fin.eof()))
    {
        std::string line;
        getline(fin, line);
        for(int i=0; i<=line.length(); ++i)
        {
            if(line[i] >= 'a' && line[i] <= 'z')
            {
                res += char(int(line[i]+shifting-'a')%26 + 'a');
            }
            else if(line[i] >= 'A' && line[i] <= 'Z')
            {
                res += char(int(line[i]+shifting-'A')%26 + 'A');
            }
            else
            {
                res += char(line[i]);
            }
        }
    }
    ret << res << std::endl;
}

 

int main()
{
    File obj;
    obj.decode();
}
