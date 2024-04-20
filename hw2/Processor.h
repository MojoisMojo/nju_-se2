#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "MainPara.h"
class Processor
{
protected:
    MainPara * mMainPara;
    void read(std::istream &);

public:
    Processor();
    void processFile();
    void processInstructions();
    ~Processor();
};
#endif