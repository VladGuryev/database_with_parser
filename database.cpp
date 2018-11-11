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
    } else {
        list<string> event;
        event.push_back(new_event);
        this->dataBaseStorage[date] = event;
    }
}

void Database::Print(ostream& outStream) const{
    outStream << "----------" << "START" << "--------" <<  endl;
    printDB(this->dataBaseStorage);
    outStream << "----------" << "END" << "----------" <<  endl;
}

int Database::RemoveIf(function<bool (const Date &, const string &)> predicat){
    int kol = 0;
    map<Date, list<string>>::iterator  current = dataBaseStorage.begin();
    map<Date, list<string>>::iterator  end = dataBaseStorage.end();

    while(current != end){
        eventsOnDate::iterator it = stable_partition(current->second.begin(), current->second.end(),
                [current, predicat](const string p){return predicat(current->first, p);});
        kol += distance(current->second.begin(), it);
        current->second.erase(current->second.begin(),it);
        current++;
    }

    return kol;
}

vector<string>
Database::FindIf(function<bool (const Date &, const string &)> predicat)
{
    vector<string> entries;

    for (const pair<Date, eventsOnDate>& item : dataBaseStorage) {
        for (const string& event : item.second) {
            if (predicat(item.first, event)){
                string entry = item.first.toString() + " " + event;
                entries.push_back(entry);
            }
        }
    }
    return entries;
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

