#ifndef EVENTCOMPARISONNODE_H
#define EVENTCOMPARISONNODE_H
#include "node.h"
#include "comparison.h"

class EventComparisonNode : public Node
{
public:
    EventComparisonNode(Comparison cmp, string str);
};

#endif // EVENTCOMPARISONNODE_H
