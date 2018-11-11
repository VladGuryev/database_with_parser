#ifndef DATECOMPARISONNODE_H
#define DATECOMPARISONNODE_H
#include "comparison.h"
#include "date.h"
#include "node.h"

class DateComparisonNode: public Node
{
    Date date_;
    Comparison cmp_;
public:
    DateComparisonNode(Comparison cmp, Date date);
    bool Evaluate(const Date& date, const string& event) override;
};

#endif // DATECOMPARISONNODE_H
