#include "Constant.h"
#include "Paragraph.h"
#include "ParaContent.h"
#include "VarContent.h"
Paragraph::Paragraph(std::istream& is, ParaType ptype, Paragraph * father = nullptr)
:ptype(ptype),father(father),content(nullptr)
{
    switch (ptype)
    {
    case ParaType::PARA_UNDEFINED:
        throw("Should Not Create A Undefined Paragraph!");
    default:
        break;
    }
    content = new VarContent(is);
}
