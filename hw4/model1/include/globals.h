#define GLOBALS_H

#include <vector>
#include <string>


extern std::string chars_; // 保存输入
extern std::vector<int> line_index_; // 保存每一行的索引
// 保存 循环位移后的索引; 第零个是行数,第一个是索引
extern std::vector<std::vector<int>> circular_shifts_; 
extern std::vector<int> alphabetized_index_; // 保存排序后的索引

#endif