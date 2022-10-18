#pragma once
#include <string>


class Range
{
public:
    Range(int from, int to);
    virtual ~Range() {}
    bool isInRange(std::string word);
    std::string toString();

    bool operator<(const Range& ob) const { return from < ob.from; }
    friend bool operator==(const Range& lhs, const Range& rhs);

private:
    int from;
    int to;
};
