#include <utils.h>
#include <input.h>
#include <circularShifter.h>
#include <output.h>
#include <alphabetizer.h>

void input(LineStorage &);

void output(const LineStorage &);

int main(int argc, char const *argv[])
{
    LineStorage lines;
    input(lines);
    // process
    CircularShifter circularShifter;
    circularShifter.setup(lines);
    Alphabetizer alphabetizer(circularShifter.getShiftsLine());
    alphabetizer.doAlph();
    output(alphabetizer.getLineStorage());
    return 0;
}

void input(LineStorage & lines)
{
    std::string line;
    while(getline(std::cin,line)){
        lines.addLine(splitString(line));
    }
}

void output(const LineStorage & lines)
{
    std::cout << lines;
}
