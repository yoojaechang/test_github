#include <string>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>
using namespace std;
class WorldClock 
{
    private:
        // ���⿡ �ð� ���� ��� ���� ����. (GMT �ð��� ���)
        // Timezone ���� ������ �Ʒ� ������ ����. ������ �ð� �����θ� ���.
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
        // �߸��� �� �Է½� false �����ϰ� ���� �ð��� �ٲ��� ����.
        bool SetTime(int hour, int minute, int second){}
        static bool LoadTimezoneFromFile(const string& file_path){}
        // �߸��� �� �Է½� false �����ϰ� ���� �ð��� �ٲ��� ����.
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
// hh:mm:ss �������� �����. ǥ�ؽð� �ƴ� ��� (+xx) �������� ������ ǥ��.
// ����� �Է� ������ >> operator�� InvalidDateException�� �߻��� �� ����.
ostream& operator<<(ostream& os,  WorldClock& c);
istream& operator>>(istream& is, WorldClock& c); // hh:mm:ss �� �Է¹���.
