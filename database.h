#ifndef DATEBASE_H
#define DATEBASE_H
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include "date.h"
#include "node.h"
using namespace std;


class Database
{
private:
  map<Date, list<string> > dataBaseStorage;
public:
    Database();
    void Add(const Date& date, const string& new_event);
    bool DeleteEvent(const Date& date, const string& event);
    unsigned int  DeleteDate(const Date& date);
    set<string> Find(const Date& date) const;
    void Print(ostream& outStream) const;
    template<typename Func> int RemoveIf(Func f){}
    template<typename Func> vector<string> FindIf(Func f){}
    string Last(const Date& date) ;
};

#endif // DATEBASE_H

