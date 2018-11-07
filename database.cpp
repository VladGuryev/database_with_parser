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
        list<string> key_as_list = dataBaseStorage.at(date);
        bool exist = binary_search(key_as_list.begin(),key_as_list.end(), new_event);
        if(!exist){
            key_as_list.push_back(new_event);
            this->dataBaseStorage[date] = key_as_list;
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

string Database::Last(const Date &date)
{

     map<Date, list<string>>::iterator events =
             this->dataBaseStorage.lower_bound(date);

     if(date < begin(dataBaseStorage)->first){
         return "No entries";
     }

     if((date == events->first) || (events == begin(dataBaseStorage))){
        return string(events->first) + " " + events->second.back();
     }
     else {
        return string(prev(events)->first) + " " + prev(events)->second.back();
     }
}

