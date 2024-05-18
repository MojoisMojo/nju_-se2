#include <output.h>
#include <globals.h>
#include <iostream>
void output(){
    for(int shiftIdx : alphabetized_index_)
    {
        int line_start_index = circular_shifts_[0][shiftIdx];
        
        int circular_line_start_index = line_index_[line_start_index];
        int circular_line_end_index = line_start_index == line_index_.size() - 1 ? chars_.size(): line_index_[line_start_index + 1]; 
        int circular_start_index = circular_shifts_[1][shiftIdx];
        std::string s = 
        chars_.substr(circular_start_index,circular_line_end_index - circular_start_index)\
         + " " + chars_.substr(circular_line_start_index,circular_start_index - circular_line_start_index);
        std::cout << s << "\n";
    }
}