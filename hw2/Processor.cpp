#include "Processor.h"
Processor::Processor()
    : mMainPara(nullptr)
{
}

void Processor::processFile()
{
    // try to read the file
    std::cout << "请输入文件相对路径:";
    std::string filePath;
    while (std::cin >> filePath)
    {
        std::fstream fin("./" + filePath);
        if (fin)
        {
            read(fin);
            fin.close();
            break;
        }
        std::cout << "请输入文件相对路径:";
    }
    std::cin.clear();
}

void Processor::read(std::istream &fin)
{
    std::string line;
    while (getline(fin, line))
    {
        myTrim(line);
        std::stringstream sline(line);
        std::string token1, token2;
        if (sline >> token1 >> token2)
            if (token1 == "/begin" && token2 == "MODULE")
            {
                break;
            }
    }
    mMainPara = new MainPara();
    mMainPara->read(fin);
}

void Processor::processInstructions()
{
    std::cin.clear();
    std::string ins;
    std::cout << "请输入需要查找的变量名,输入quit()或Ctrl+Z结束查询:\n";
    while (getline(std::cin, ins))
    {
        if (ins == "quit()")
        {
            break;
        }
        VarPara *v = mMainPara->search(ins);
        if (v)
        {
            std::cout << "您查询的变量为:\n"
                      << (*v);
        }
        else
        {
            std::cout << "未知变量\n";
        }
    }
}

Processor::~Processor()
{
    if (mMainPara)
    {
        delete mMainPara;
        mMainPara = nullptr;
    }
}
