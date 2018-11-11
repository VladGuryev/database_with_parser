#include "eventcomparisonnode.h"

EventComparisonNode::EventComparisonNode(Comparison cmp, string str):
    str_(str), cmp_(cmp){
    /*cout << "EventComparisonNode::constructor: "<< str_ << endl;*/
}

bool EventComparisonNode::Evaluate(const Date &date, const string &event)
{
    if(cmp_ == Comparison::Equal){
      //  cout << "Comparison::Equal:bool=" << (event == str_)<< endl;
      //  cout << "event=" << event << "     str_=" << str_ << endl;
        return  event == str_;
    }
    if(cmp_ == Comparison::NotEqual){
       // cout << "Comparison::NotEqual=" << (event != str_)<< endl;
      //  cout << "event=" << event << "     str_=" << str_ << endl;
        return event != str_;
    }
    return 0;
}
