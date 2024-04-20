#include "VarPara.h"
#include "Utils.h"
#include "Constant.h"
VarPara::VarPara(std::istream &fin, ParaType pType, BasePara *pFather = nullptr)
    : StdPara(fin, pType, pFather) // do nothing
{
    // get Name / Type / Indertifier
    for (auto &[key, value] : mParaProporties)
    {
        if (isVarName(key))
        {
            mVarName = value;
        }
        else if (isVarIdentfier(key))
        {
            mVarIdentifier = value;
        }
        else if (isVarType(key))
        {
            mVarType = value;
        }
    }
}

/// @brief 筛选子段落
/// @param paraType 子段落类型
/// @return 如果通过筛选返回true，否则返回false
bool VarPara::filter(ParaType paraType) { return true; }

std::string VarPara::getVarType() const { return mVarType; }
std::string VarPara::getVarName() const { return mVarName; }
std::string VarPara::getVarIdentifier() const { return mVarIdentifier; }

/// @brief 判断token是否包含Name字段
bool VarPara::isVarName(const std::string &token) { return isMatch(token, {"Name", "name"}); }

/// @brief 判断token是否包含Identifier字段
bool VarPara::isVarIdentfier(const std::string &token) { return isMatch(token, {"Identifier", "identidier"}); }

/// @brief 判断token是否包含type字段
bool VarPara::isVarType(const std::string &token) { return isMatch(token, {"Type", "type"}); }

VarPara::~VarPara()
{ /* do nothing */
}