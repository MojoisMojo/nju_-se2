#include <input.h>
#include <iostream>
#include <vector>
#include <globals.h>
void input()
{
    std::string line;
    while(getline(std::cin,line))
    {
        line_index_.push_back(chars_.size());
        chars_ += line;
    }
}
std::string getLine(int line_index)
{
    int start_index = line_index_[line_index];
    int end_index = (line_index == line_index_.size() - 1) ? 
                    chars_.size():
                    line_index_[line_index + 1];
    return chars_.substr(start_index,end_index - start_index);
}
