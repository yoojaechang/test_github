#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Date {
    public:
        Date():year_(0),month_(0),day_(0){}
        Date(int year, int month, int day):year_(year),month_(month),day_(day){}
        void NextDay();
        void NextDay(int n);      
        bool SetDate(int year, int month, int day){
            if (month>12 || month<=0)
                return false;
            else if (month==2 && GetDaysInYear(year)==366 && day>29)
                return false;
            else if (month==2 && GetDaysInYear(year)==365 && day>28)
                return false;
            else if (month<8 && month%2==1 && day>31)
                return false;
            else if (month<8 && month%2==0 && month!=2 && day>30)
                return false;
            
            else if (month>8 && month%2==0 && day>31)
                return false;
            else if (month>8 && month%2==1 && day>30)
                return false;
            else if (day<=0)
                return false;
            year_=year;
            month_=month;
            day_=day;
            return true;
            }
    
        int year() const {return year_;}
        int month() const {return month_;}
        int day() const {return day_;}
    
    private:
// 윤년을 판단하여 주어진 연도에 해당하는 날짜 수(365 또는 366)를 리턴.
         int GetDaysInYear(int year) {
            if(year%400==0) return 366;
            else if(year%400!=0){
                if(year%100==0 || year%4!=0)return 365;
                else {return 366;}
                }
            }
// 해당 날짜가 해당 연도의 처음(1월 1일)부터 며칠째인지를 계산.
         int ComputeDaysFromYearStart(int year, int month, int day){
            int number=0;
            if(GetDaysInYear(year)==366){
                for(int i=1;i<month;++i) {
                    if (i==1||i==3||i==5||i==7||i==8||i==10||i==12){number+=31;}
                    else if(i==2) number+=29;
                    else {number+=30;}
                    }
                }
            else if(GetDaysInYear(year)==365){
                for(int i=1;i<month;++i) {
                    if (i==1||i==3||i==5||i==7||i==8||i==10||i==12){number+=31;}
                    else if(i==2) number+=28;
                    else {number+=30;}
                    }
                }
            }
            
        int year_, month_, day_;
};


struct InvalidDateException {
    
    string input_date;
    InvalidDateException(const string& str) : input_date(str) {}

};
