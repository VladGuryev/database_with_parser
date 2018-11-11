#include "logicaloperationnode.h"

LogicalOperationNode::LogicalOperationNode(LogicalOperation op,
                                           shared_ptr<Node> left,
                                           shared_ptr<Node> right):
    op_(op), left_(left), right_(right) { }

bool LogicalOperationNode::Evaluate(const Date &date, const string &event)
{
    if (op_ == LogicalOperation::And) {
         return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    }
    else if (op_ == LogicalOperation::Or) {
          return left_->Evaluate(date, event) || right_->Evaluate(date, event);
    }
    return 0;
}
