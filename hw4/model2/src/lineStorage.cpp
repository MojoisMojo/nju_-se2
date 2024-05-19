#include <lineStorage.h>
#include <algorithm>

// 得到第几行第几个单词的第几个字母
char LineStorage::getChar(int positionIdx, int wordIdx, int lineIdx)
{
    try
    {
        return lines[lineIdx][wordIdx][positionIdx];
    }
    catch (...)
    {
        std::cerr << "lineIdx out of range\n";
        return 0;
    }
}

// 得到第几行的第几个单词的字母数
int LineStorage::getCharCount(int wordIdx, int lineIdx)
{
    try
    {
        return lines[lineIdx][wordIdx].size();
    }
    catch (...)
    {
        std::cerr << "lineIdx out of range\n";
        return 0;
    }
}

// 得到第几行的第几个单词
std::string LineStorage::getWord(int wordIdx, int lineIdx)
{
    try
    {
        return lines[lineIdx][wordIdx];
    }
    catch (...)
    {
        std::cerr << "lineIdx out of range\n";
        return "";
    }
}

// 得到第几行的单词数
int LineStorage::getWordCount(int lineIdx)
{
    try
    {
        return lines[lineIdx].size();
    }
    catch (...)
    {
        std::cerr << "lineIdx out of range\n";
        return 0;
    }
}

void LineStorage::sortedBy(std::function<bool(const Line &, const Line &)> cmpFunc)
{
    std::sort(lines.begin(), lines.end(), cmpFunc);
}

Line LineStorage::getLine(int lineIdx) const
{
    return lines[lineIdx];
}

Line &LineStorage::getLine(int lineIdx)
{
    return lines[lineIdx];
}
std::vector<Line> LineStorage::getLines() const
{
    return lines;
}

int LineStorage::getLineCount() const
{
    return lines.size();
}

void LineStorage::addEmptyLine()
{
    lines.push_back(Line());
}

void LineStorage::addLine(const Line &line)
{
    lines.push_back(line);
}

void LineStorage::addWord(std::string word, int idx)
{
    lines[idx].push_back(word);
}

std::ostream &operator<<(std::ostream &outs, const LineStorage &lineStorage)
{
    for (auto &line : lineStorage.getLines())
    {
        for (auto &word : line)
        {
            outs << word << " ";
        }
        outs << "\n";
    }
    return outs;
}
