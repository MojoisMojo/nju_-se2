#include <circularShifter.h>
#include <vector>
#include <string>
void CircularShifter::setup(const LineStorage &lines)
{
    shifts_ = lines;
    for (int i = 0; i < lines.getLineCount(); ++i)
    {
        Line line = lines.getLine(i);
        for (int j = 0; j < line.size(); ++j)
        {
            shifts_.addEmptyLine();
            for(int k = j; k < (line.size() + j); ++k)
            {
                shifts_.addWord(line[k % line.size()],shifts_.getLineCount() - 1);
            }
        }
    }
}
