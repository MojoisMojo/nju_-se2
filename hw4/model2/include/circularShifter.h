#ifndef CIRCULAR_SHIFTER_H
#define CIRCULAR_SHIFTER_H
#include <lineStorage.h>
class CircularShifter
{
private:
    LineStorage shifts_;

public:
    void setup(const LineStorage &lines);
    const LineStorage & getShiftsLine();
};
#endif