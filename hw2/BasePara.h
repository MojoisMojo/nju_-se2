#ifndef BASE_PARA_H
#define BASE_PARA_H
#include "Constant.h"
class BasePara
{
protected:
    ParaType mParaType;
    BasePara *mParaFather;
protected:
    static ParaType string2ParaType(const std::string &);
    virtual std::ostream&print(std::ostream&);
public:
    BasePara();
    BasePara(ParaType, BasePara *);
    
    ParaType getParaType()const;
    BasePara *getParaFather()const;
    
    friend std::ostream&operator<<(std::ostream&,BasePara &);
    ~BasePara();
};

#endif