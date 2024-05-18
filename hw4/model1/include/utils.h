#ifndef UTILS_H
#define UTILS_H
#include <globals.h>
#include <string.h>
#include <iostream>
std::string getWord(int shift_index)
{
    if (shift_index < 0 || shift_index >= circular_shifts_[0].size())
    {
        std::cerr << "shift index out of circular_shifts's index\n";
    }
    
    int word_start_index = circular_shifts_[1][shift_index];
    int word_end_index = 
        (shift_index == (circular_shifts_[1].size() - 1))
        ? chars_.size()
        :(circular_shifts_[1][shift_index + 1]);
    return chars_.substr(word_start_index,word_end_index - word_start_index);
}

#endif