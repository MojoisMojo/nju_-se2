#ifndef PARACONTENT_H
#define PARACONTENT_H
#include "Constant.h"
#include "Paragraph.h"

class ParaContent
{
protected:
    Proporty proporties;
    std::vector<Paragraph *> sonParas;
    std::vector<Content> contents;
    virtual void processLine(const std::string &);
    virtual bool filter(const std::string &);

public:
    ParaContent();
    ParaContent(std::istream &);
};
#endif