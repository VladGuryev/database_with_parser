#ifndef LOGICALOPERATIONNODE_H
#define LOGICALOPERATIONNODE_H
#include "node.h"
#include "logicaloperation.h"
#include <memory>

class LogicalOperationNode : public Node
{
public:
    LogicalOperationNode(LogicalOperation, shared_ptr<Node> node1,
                         shared_ptr<Node>node2);
};

#endif // LOGICALOPERATIONNODE_H
