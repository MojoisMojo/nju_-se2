#ifndef CONSTANT_H
#define CONSTANT_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include <stdio.h>
typedef std::unordered_map<std::string, std::string> Properties;
typedef std::pair<std::string, std::string> Property;
typedef std::string Content;
typedef enum struct ProcessCode
{
    PROCESS_FAIL,
    PROCESS_END,
    PROCESS_CONTINUE,
    PROCESS_SKIP,
} ProcessCode;

#define PARA_TYPE_NUMBER 2

typedef enum struct ParaType
{
    PARA_MEASUREMENT,
    PARA_CHARACTERISTIC,
    PARA_UNDEFINED,
} ParaType;

static const std::string PARA_TYPE_STRINGS[] = {
    "MEASUREMENT",
    "CHARACTERISTIC",
    "UNDEFINED"};

static const std::string ParaTypeToString(ParaType pType)
{
    return PARA_TYPE_STRINGS[(int)(pType)];
}

#endif