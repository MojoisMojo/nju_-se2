#ifndef BASE_PARA_H
#define BASE_PARA_H
#include "Constant.h"
#include "Utils.h"
class BasePara
{
protected:
    ParaType mParaType;
    BasePara *mParaFather;
protected:
    static bool isBegin(const std::string &);
    static bool isEnd(const std::string &);
    static ParaType string2ParaType(const std::string &);
    virtual std::ostream&print(std::ostream&);
public:
    BasePara(ParaType, BasePara *);
    virtual void read(std::istream &);
    ParaType getParaType()const;
    BasePara *getParaFather()const;
    
    friend std::ostream&operator<<(std::ostream&,BasePara &);
    ~BasePara();
};

#endif