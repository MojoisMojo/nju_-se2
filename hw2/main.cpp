#include "Processor.h"
int main()
{
    freopen("../debug.txt","w+",stderr);
    Processor processor;
    processor.processFile();
    processor.processInstructions();
    return 0;
}