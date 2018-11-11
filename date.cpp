#include "date.h"
#include <iomanip>
#include <vector>

Date::Date(int y, int m, int d): year(y), month(m), day(d) { }

Date ParseDate(istream &is)
{
    string str;
    is >> str;
    string::size_type i = 0;
    vector<string> v_s;
    string el, p;

    if(str.empty())
        return {};

    while(i < str.size()){
        el.push_back(str[i]);
        if (el.compare(string("-"))  != 0){
            p.push_back(str[i]);
        } else {
            v_s.push_back(p);
            p.erase();
        }
        if(i == str.size() - 1)
            v_s.push_back(p);
        i++;
        el.pop_back();
    }

    int year = stoi(v_s.at(0));
    int month = stoi(v_s.at(1));
    int day = stoi(v_s.at(2));
    Date date(year, month, day);
    return date;
}

ostream& operator<<(ostream& os, const Date& dt){
    os <<  dt.toString();
    return os;
}

bool operator<(const Date& lhs, const Date& rhs){
    if(lhs.GetYear() < rhs.GetYear()){
        return true;
    } else if (lhs.GetYear() == rhs.GetYear()) {
        if(lhs.GetMonth() < rhs.GetMonth()){
            return true;
        } else if (lhs.GetMonth() == rhs.GetMonth()){
            return (lhs.GetDay() < rhs.GetDay());
        } else {
            return false;
        }
    } else {
       return false;
    }
}

bool operator>(const Date& lhs, const Date& rhs){
    return (rhs < lhs);
}

bool operator==(const Date& lhs, const Date& rhs){
    return (!(lhs < rhs) && !(rhs < lhs));
}

bool operator!=(const Date& lhs, const Date& rhs){
    return !(lhs == rhs);
}


string Date::toString() const
{
    auto addenda = [](string& str, int index = 1){
        if(index == 0){
            while(str.size() < 4){
                str.insert (str.begin(), '0');
            }
        } else {
            while(str.size() < 2){
                str.insert (str.begin(), '0');
            }
        }
    };
    string year = std::to_string(this->GetYear());
    addenda(year, 0);
    string month = std::to_string(this->GetMonth());
    addenda(month);
    string day= std::to_string(this->GetDay());
    addenda(day);
    string out = year + "-" + month + "-" + day;
    return out;
}

Date::operator string() const
{
    return this->toString();
}





