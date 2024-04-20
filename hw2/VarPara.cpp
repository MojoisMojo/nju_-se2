#include "VarPara.h"
VarPara::VarPara(ParaType pType, BasePara *pFather = nullptr)
    : StdPara(pType, pFather),
    mVarType(""),mVarName(""),mVarIdentifier("")
{
    
}

void VarPara::read(std::istream & fin){
    StdPara::read(fin);
    // get Name / Type / Indertifier
    for (auto &[key, value] : mParaProperties)
    {
        if (isVarName(key))
        {
            std::cerr << "name:" << value << "\n";
            mVarName = value;
        }
        else if (isVarIdentfier(key))
        {
            std::cerr << "id:" << value << "\n";
            mVarIdentifier = value;
        }
        else if (isVarType(key))
        {
            std::cerr << "type:" << value << "\n";
            mVarType = value;
        }
    }
}

std::string VarPara::getVarType() const { return mVarType; }
std::string VarPara::getVarName() const { return mVarName; }
std::string VarPara::getVarIdentifier() const { return mVarIdentifier; }

/// @brief 判断token是否包含Name字段
bool VarPara::isVarName(const std::string &token) { return isMatch(token, {"Name", "name"}); }

/// @brief 判断token是否包含Identifier字段
bool VarPara::isVarIdentfier(const std::string &token) { return isMatch(token, {"Identifier", "identidier"}); }

/// @brief 判断token是否包含type字段
bool VarPara::isVarType(const std::string &token) { return isMatch(token, {"Type", "type"}); }

std::ostream&operator<<(std::ostream& os,VarPara& var){
    return var.print(os);
}


VarPara::~VarPara()
{ /* do nothing */
}