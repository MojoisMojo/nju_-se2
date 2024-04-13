#ifndef PARACONTENT_H
#define PARACONTENT_H
#include "Constant.h"
#include "Paragraph.h"

class ParaContent{
protected:
    Proporty proporty;
    std::vector<Paragraph *> sonParas;
public:
    ParaContent();
    ParaContent(std::istream&);
};
#endif