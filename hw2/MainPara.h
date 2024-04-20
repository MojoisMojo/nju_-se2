#ifndef MAIN_PARA_H
#define MAIN_PARA_H
#include "VarPara.h"
class MainPara:public StdPara{
protected:
    std::unordered_map<std::string, VarPara *> mVariblesMap;
public:
    MainPara();
    ~MainPara();
    // virtual void read(std::istream &);
    VarPara* search(const std::string &);
    virtual bool filter(ParaType) override;
    virtual bool filter(BasePara *) override;
    virtual void processSubPara(std::istream&,ParaType);
};
#endif