#ifndef DATECOMPARISONNODE_H
#define DATECOMPARISONNODE_H
#include "comparison.h"
#include "date.h"
#include "node.h"

class DateComparisonNode: public Node
{
public:
    DateComparisonNode(Comparison cmp, Date date);
};

#endif // DATECOMPARISONNODE_H
