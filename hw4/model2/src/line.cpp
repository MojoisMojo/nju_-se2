#include <line.h>

// // 得到第几个单词的第几个字母
// char Line::getChar(int positionIdx, int wordIdx)
// {
//     try
//     {
//         return words[wordIdx][positionIdx];
//     }
//     catch (...)
//     {
//         std::cerr << "wordIdx/positionIdx out of range\n";
//         return 0;
//     }
// }

// // 得到第几个单词的字母数
// int Line::getCharCount(int wordIdx)
// {
//     try
//     {
//         return words[wordIdx].size();
//     }
//     catch (...)
//     {
//         std::cerr << "wordIdx out of range\n";
//         return 0;
//     }
// }

// // 得到第几个单词
// std::string Line::getWord(int wordIdx)
// {
//     try
//     {
//         return words[wordIdx];
//     }
//     catch (...)
//     {
//         std::cerr << "wordIdx out of range\n";
//         return "";
//     }
// }

// // 得到单词数
// int Line::getWordCount()
// {
//     return words.size();
// }

// bool Line::operator>(const Line &other)
// {
//     return this->words > other.words;
// }

// bool Line::operator>=(const Line &other)
// {
//     return this->words > other.words;
// }

// bool Line::operator<(const Line &other)
// {
//     return this->words < other.words;
// }

// bool Line::operator<=(const Line &other)
// {
//     return this->words <= other.words;
// }
