#ifndef NODE_H
#define NODE_H
#include <string>
#include "date.h"
#include <memory>
using namespace  std;

class Node
{
public:
    Node();
    bool Evaluate(const Date& date, const string& event);
};

#endif // NODE_H
