#include <input.h>
#include <circularShifter.h>
#include <output.h>
#include <alphabetizer.h>

void input(LineStorage & lines);

void output();

int main(int argc, char const *argv[])
{
    LineStorage lines;
    input();
    // process
    CircularShifter circularShifter;
    circularShifter.setup(lines);
    output();
    return 0;
}

void input(LineStorage & lines)
{

}

void output()
{

}
