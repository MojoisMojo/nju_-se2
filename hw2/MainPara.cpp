#include "MainPara.h"
#include "VarPara.h"
MainPara::MainPara()
    : StdPara(ParaType::PARA_UNDEFINED, nullptr)
{
}
VarPara *MainPara::search(const std::string &name)
{
    if (mVariblesMap.count(name))
    {
        return mVariblesMap[name];
    }
    return nullptr;
}

bool MainPara::filter(ParaType pType)
{
    return pType == ParaType::PARA_CHARACTERISTIC || pType == ParaType::PARA_MEASUREMENT;
}
bool MainPara::filter(BasePara *para)
{
    VarPara *var = nullptr;
    switch (para->getParaType())
    {
    case ParaType::PARA_CHARACTERISTIC:
        var = (VarPara *)para;
        std::cerr << "here1\n";
        std::cerr << var->getVarType() << "\n";
        if (var->getVarType() == "VALUE")
        {
            std::cerr << "here2\n";
            break;
        }
        std::cerr << "here3\n";
        return false;
    case ParaType::PARA_MEASUREMENT:
        var = (VarPara *)para;
        break;
    default:
        return false;
    }
    mVariblesMap[var->getVarName()] = var;
    return true;
}
void MainPara::processSubPara(std::istream &fin, ParaType subPType)
{
    VarPara *sonPara = new VarPara(subPType, this);
    sonPara->read(fin);  // read
    if (filter(sonPara)) // check
    {
        std::cerr << "Add!\n";
        mSonParas.push_back(sonPara);
    }
    else
    {
        std::cerr << "Delete!\n";
        delete sonPara;
    }
}

MainPara::~MainPara()
{
    ; // do nothing
}