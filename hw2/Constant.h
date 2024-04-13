#ifndef CONSTANT_H
#define CONSTANT_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
typedef std::unordered_map<std::string,std::string> Proporty;
typedef enum struct ParaType{
    PARA_MEASUREMENT,
    PARA_CHARACTERISTIC,
    PARA_UNDEFINED,
}ParaType;

static const std::string PARA_TYPE_STRING[] = {
    "MEASUREMENT",
    "CHARACTERISTIC",
    "UNDEFINED"
};

static const std::string ParaTypeToString(ParaType ptype){
    return PARA_TYPE_STRING[(int)(ptype)];
}

#endif