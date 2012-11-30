#include "date.h"
ostream& operator<<(ostream& os, const Date& c){
    
    os<<c.year()<<'.'<<c.month()<<'.'<<c.day();

    return os;
    
    }

istream& operator>>(istream& is, Date& c){
    int year, month, day;
    string a;
    is>>a;
    int i, j, k;
  for (i=0;i<a.size();i++)
    if (a[i]=='.'){
      j=i;
      break;
    }
  for (i=j+1;i<a.size();i++)
    if (a[i]=='.'){
      k=i;
      break;
    }

  year=atoi((a.substr(0,j)).c_str());
  month=atoi((a.substr(j+1,k)).c_str());
  day=atoi((a.substr(k+1,a.size())).c_str());

  if (!c.SetDate(year, month, day))
    throw InvalidDateException(a);

  return is;
}


int main() {
    Date date;
    string cmd;
    while (cmd != "quit") {
        cin >> cmd;
        try {
                if (cmd == "set") {
                    cin >> date;
                    cout << date << endl;
                } 
                else if (cmd == "next_day") {
                    date.NextDay();
                    cout << date << endl;
                } 
                else if (cmd == "next") {
                    int n_days = 0;
                    cin >> n_days;
                    date.NextDay(n_days);
                    cout << date << endl;
                }
            } 
        catch (InvalidDateException& e) {
            cout << "Invalid date: " << e.input_date << endl;
        }
    }
return 0;
}
