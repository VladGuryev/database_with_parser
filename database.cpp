#include "database.h"

//template <typename T1, typename T2>
//void PrintSet(pair<T1, set<T2>> item) {
//  for (const T2& event : item.second) {
//    cout << item.first << " " << event  << endl;
//  }
//}

template <typename T1, typename T2>
void printMap(const map<T1, set<T2>>& map) {
  for (const auto& item : map) {
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
        set<string> key_set = dataBaseStorage.at(date);
        key_set.insert(new_event);
        this->dataBaseStorage[date] = key_set;
        //cout << date << endl;
    } else {
        set<string> event;
        event.insert(new_event);
        this->dataBaseStorage[date] = event;
       // cout << date << endl;
    }
}

void Database::Print(ostream& outStream) const{
    outStream << "----------" << "START" << "--------" <<  endl;
    printMap(this->dataBaseStorage);
    outStream << "----------" << "END" << "----------" <<  endl;
}

string &Database::Last(const Date &date) const
{

}

