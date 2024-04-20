#ifndef VAR_PARA_H
#define VAR_PARA_H
#include "StdPara.h"
class VarPara : public StdPara
{
protected:
    std::string mVarName;
    std::string mVarIdentifier;
    std::string mVarType;

protected:
    static bool isVarName(const std::string &);
    static bool isVarIdentfier(const std::string &);
    static bool isVarType(const std::string &);

    // ProcessCode processLine(const std::string &) override; 不需要重写
    // virtual bool filter(ParaType) override;
    // virtual bool filter(BasePara *) override;
    friend std::ostream&operator<<(std::ostream&,VarPara&);
    // virtual std::ostream&print(std::ostream&)override; 不需要重写

public:
    virtual void read(std::istream &) override;
    VarPara(ParaType, BasePara *);
    std::string getVarType() const;
    std::string getVarName() const;
    std::string getVarIdentifier() const;
    ~VarPara();
};
#endif