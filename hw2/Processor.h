#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Constant.h"
#include "BasePara.h"
class Processor
{
protected:
    std::unordered_map<std::string, BasePara *> mVariblesMap;
    bool filter(ParaType);
    bool filter(BasePara *);
    void processParagraph();

public:
    Processor();
    void read();
    void processInstructions();
    ~Processor();
};
#endif