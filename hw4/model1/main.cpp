#include <input.h>
#include <circularShift.h>
#include <output.h>
#include <alphabetizer.h>

#include <vector>

std::string chars_;           // 保存输入
std::vector<int> line_index_; // 保存每一行的索引
// 保存 循环位移后的索引; 第零个是行数,第一个是索引
std::vector<std::vector<int>> circular_shifts_;
std::vector<int> alphabetized_index_; // 保存排序后的索引

int main(int argc, char const *argv[])
{
    input();
    circularShift();
    alphabetized();
    output();
    return 0;
}
