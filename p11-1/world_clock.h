#include <string>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>
using namespace std;
class WorldClock 
{
    private:
        // 여기에 시각 관련 멤버 변수 정의. (GMT 시간을 사용)
        // Timezone 관련 정보는 아래 변수에 저장. 시차는 시간 단위로만 계산.
        int time_difference_;
        //static map<string, int> timezone_;
    
    public:
        string last;
        map<string,int> ig;
        int hour_;
        int min_;
        int sec_;
        WorldClock(){
            time_difference_=0;
            hour_=0;
            min_=0;
            sec_=0;
            }
        WorldClock(int hour, int minute, int second){
            hour_ = hour;
            min_ = minute;
            sec_ = second;
            }
        void Tick(int seconds){
            int c_h,c_m,c_s;
            c_h = seconds/3600;
            seconds = seconds%3600;
            c_m = seconds/60;
            seconds = seconds%60;
            c_s = seconds;
            hour_ += c_h;
            min_ += c_m;
            sec_ += c_s;
            }
        // 잘못된 값 입력시 false 리턴하고 원래 시간은 바뀌지 않음.
        bool SetTime(int hour, int minute, int second){}
        static bool LoadTimezoneFromFile(const string& file_path){}
        // 잘못된 값 입력시 false 리턴하고 원래 시간은 바뀌지 않음.
        void AddTimezoneInfo(const string& city, int diff){
            ig[city] = diff;
            }
        
        bool SetTimezone(const string& timezone){
            hour_ = hour_ + ig[timezone] - ig[last];
            if( ig[timezone] == 0){
                cout<<(hour_)%24<<":"<<min_<<":"<<sec_<<endl;
                last = timezone;
                return true;
            }
    
            cout<<(hour_)%24<<":"<<min_<<":"<<sec_<<" (+"<<ig[timezone]<<")"<<endl;
            last = timezone;
            return true;
        }
        int hour() const{
            return hour_;
            }
        int minute() const{
            return min_;
            }
        int second() const{
            return sec_;
            }
        int time_difference() const { return time_difference_; }
};

struct InvalidTimeException 
{
    string input_time;
    InvalidTimeException(const string& str)
    {
        input_time= str;
    }
    
};
// hh:mm:ss 형식으로 입출력. 표준시가 아닌 경우 (+xx) 형식으로 시차를 표시.
// 사용자 입력 오류시 >> operator는 InvalidDateException을 발생할 수 있음.
ostream& operator<<(ostream& os,  WorldClock& c);
istream& operator>>(istream& is, WorldClock& c); // hh:mm:ss 로 입력받음.
