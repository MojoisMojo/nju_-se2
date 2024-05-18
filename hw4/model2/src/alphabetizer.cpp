#include <Alphabetizer.h>

Alphabetizer::Alphabetizer(const LineStorage & lines)
:lines(lines){

}
void Alphabetizer::doAlph(){
    lines.sortedBy(std::greater<Line>());
}

Line & Alphabetizer::getIthLine(int lineIdx)
{
    return lines.getLine(lineIdx);
}

Line Alphabetizer::getIthLine(int lineIdx) const
{
    return lines.getLine(lineIdx);
}
