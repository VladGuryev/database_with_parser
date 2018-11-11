#ifndef LOGICALOPERATIONNODE_H
#define LOGICALOPERATIONNODE_H
#include "node.h"
#include "logicaloperation.h"
#include <memory>

class LogicalOperationNode : public Node
{
public:
    LogicalOperation op_;
    shared_ptr<Node> left_, right_;
    LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left,
                         shared_ptr<Node> right);
    bool Evaluate(const Date& date, const string& event) override;
};

#endif // LOGICALOPERATIONNODE_H
