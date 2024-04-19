#ifndef PARACONTENT_H
#define PARACONTENT_H
#include "Constant.h"
#include "Paragraph.h"

class ParaContent
{
protected:
    Proporty paraProporties;
    std::vector<Paragraph *> paraSonParas;
    std::vector<Content> paraContents;
    virtual ProcessCode processLine(const std::string &);
    virtual bool filter(ParaType);

public:
    ParaContent();
    ParaContent(std::istream &);
    ~ParaContent();
};
#endif