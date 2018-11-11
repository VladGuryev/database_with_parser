#ifndef NODE_H
#define NODE_H
#include <string>
#include "date.h"
#include <memory>
using namespace  std;

class Node
{
public:
    Node(){}
    virtual ~Node(){}
    virtual bool Evaluate(const Date& date, const string& event) = 0;
};

#endif // NODE_H
