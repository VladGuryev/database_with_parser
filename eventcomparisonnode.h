#ifndef EVENTCOMPARISONNODE_H
#define EVENTCOMPARISONNODE_H
#include "node.h"
#include "comparison.h"

class EventComparisonNode : public Node
{
    string str_;
    Comparison cmp_;
public:
    EventComparisonNode(Comparison cmp, string str);
    bool Evaluate(const Date& date, const string& event) override;
};

#endif // EVENTCOMPARISONNODE_H
