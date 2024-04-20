#include "Processor.h"
#include "VarPara.h"
Processor::Processor()
{
}

void Processor::processParagraph()
{
}

void Processor::read()
{
    // try to read the file
    std::string filePath;
    while (std::cin >> filePath)
    {
    }
    std::cin.clear();
}

void Processor::processInstructions()
{
    std::string ins;
    std::cout << "请输入需要查找的变量名,输入quit()或Ctrl+Z结束查询:\n";
    while (getline(std::cin, ins))
    {
        if(ins == "quit()"){break;}
        if(mVariblesMap.count(ins)){
            std::cout << "你查询的变量为:\n";
        }
    }
}
/// @brief 筛选子段落 
/// @param pType 子段落类型
/// @return 如果通过筛选返回true，否则返回false
bool Processor::filter(ParaType pType)
{
    return pType == ParaType::PARA_CHARACTERISTIC || pType == ParaType::PARA_MEASUREMENT;
}
/// @brief 筛选子段落
/// @param para 子段落
/// @return 如果通过筛选返回true，否则返回false
bool Processor::filter(BasePara * para)
{
    
    switch (para->getParaType())
    {
    case ParaType::PARA_CHARACTERISTIC:
        VarPara * var = (VarPara *)para;
        if(var->getVarType() == "VALUE"){
            return true;
        }
        return false;
    case ParaType::PARA_MEASUREMENT:
        return true;
    default:
        return false;
    }
}

Processor::~Processor()
{
}
