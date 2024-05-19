#ifndef ALPHABETIZER_H
#define ALPHABETIZER_H
#include <lineStorage.h>
class Alphabetizer // 排序 ？
{
private:
    LineStorage lines;
public:
    Alphabetizer(const LineStorage &);
    void doAlph();
    Line & getIthLine(int);
    Line getIthLine(int)const;
    const LineStorage & getLineStorage();
};
#endif