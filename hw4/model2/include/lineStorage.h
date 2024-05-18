#ifndef LINE_STORAGE_H
#define LINE_STORAGE_H
#include <string>
#include <vector>
#include <line.h>
#include <functional>
class LineStorage
{
private:
    std::vector<Line> lines;
public:
    char getChar(int, int, int);
    int getCharCount(int, int);
    std::string getWord(int, int);
    int getWordCount(int);
    void sortedBy(std::function<bool(const Line&, const Line&)> cmpFunc);
    Line getLine(int) const;
    Line &getLine(int);
    std::vector<Line>getLines() const;
    int getLineCount() const;
    void addEmptyLine();
    void addWord(std::string,int);
};
#endif