#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace  std;

class Date
{
    int year;
    int month;
    int day;
public:
    Date(int y = 1, int m = 1, int d = 1);
    int GetYear() const{ return year;}
    int GetMonth() const{ return month;}
    int GetDay() const{ return day;}
    friend ostream& operator<<(ostream& os, const Date& dt);
    friend bool operator<(const Date& lhs, const Date& rhs);
    friend bool operator>(const Date& lhs, const Date& rhs);
    friend bool operator==(const Date& lhs, const Date& rhs);
    friend bool operator!=(const Date& lhs, const Date& rhs);
    explicit operator string() const;
    string toString() const;
};

Date ParseDate(istream &is);

#endif // DATE_H
