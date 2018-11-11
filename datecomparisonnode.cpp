#include "datecomparisonnode.h"

DateComparisonNode::DateComparisonNode(Comparison cmp, Date date):
     date_(date), cmp_(cmp){}

bool DateComparisonNode::Evaluate(const Date &date, const string &event)
{

    if (cmp_ == Comparison::Equal){
        return date_ == date;
    }
    if (cmp_ == Comparison::Greater){
        return date > date_;
    }
    if (cmp_ == Comparison::GreaterOrEqual){
        return (date > date_) || (date_ == date);
    }
    if (cmp_ == Comparison::Less){
        return (date < date_);
    }
    if (cmp_ == Comparison::LessOrEqual){
        return (date < date_) || (date_ == date);
    }
    if (cmp_ == Comparison::NotEqual){
        return date_ != date;
    }

}
