#ifndef PARAGRAPH_H
#define PARAGRAPH_H
#include "Constant.h"
class ParaContent;
class Paragraph{
protected:
    ParaType ptype;
    Paragraph * father;
    ParaContent * content;
public:
    Paragraph(std::istream&, ParaType, Paragraph *);
};

#endif