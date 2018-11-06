#include "database.h"
#include <algorithm>

void printDB(const map<Date, list<string>>& map) {
  for (const pair<Date, list<string>>& item : map) {
    for (const auto& event : item.second) {
      cout << item.first << " " << event  << endl;
    }
  }
}

Database::Database()
{

}

void Database::Add(const Date &date, const string &new_event)
{
    if (this->dataBaseStorage.count(date) > 0) {
        list<string> key_set = dataBaseStorage.at(date);
        bool exist = binary_search(key_set.begin(),key_set.end(), new_event);
        if(!exist){
            key_set.push_back(new_event);
            this->dataBaseStorage[date] = key_set;
        }
        //cout << date << endl;
    } else {
        list<string> event;
        event.push_back(new_event);
        this->dataBaseStorage[date] = event;
       // cout << date << endl;
    }
}

void Database::Print(ostream& outStream) const{
    outStream << "----------" << "START" << "--------" <<  endl;
    printDB(this->dataBaseStorage);
    outStream << "----------" << "END" << "----------" <<  endl;
}

string Database::Last(const Date &date) const
{
     map<Date, list<string>>::const_iterator events =
             this->dataBaseStorage.lower_bound(date);
     const auto& r = *events;
       //cout << r.first;
    if(events != dataBaseStorage.end()){
        if(!(r.first < date) && !(date < r.first)){ //equality
            list<string> v = dataBaseStorage.at(date);
            cout << r.first << " " << v.back();
        } else {


        }
    }  else
        return {"No entries"};

}

