#ifndef EMPTYNODE_H
#define EMPTYNODE_H
#include "node.h"

class EmptyNode : public Node
{
public:
    EmptyNode();
    bool Evaluate(const Date& date, const string& event) override;
};

#endif // EMPTYNODE_H
