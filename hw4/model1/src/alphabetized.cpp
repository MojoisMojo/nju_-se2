#include <alphabetized.h>
#include <globals.h>
#include <algorithm>
#include <utils.h>
void alphabetized()
{
    alphabetized_index_.resize(circular_shifts_[0].size());
    for (int i = 0; i < alphabetized_index_.size(); ++i)
    {
        alphabetized_index_[i] = i;
    }
    std::sort(alphabetized_index_.begin(), alphabetized_index_.end(),
              [&](int i, int j)
              {
                  return getWord(i) < getWord(j);
              }); // 我们这里假设不存在一样的词汇, 如果有的话enmmmmm，需要比较的就多了O
}
