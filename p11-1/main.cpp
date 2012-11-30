#include "world_clock.h"

int main() 
{
    WorldClock clock;
    string cmd;
    
    clock.ig["GMT"]=0;

    while (cmd != "quit") 
    {
        cin >> cmd;
        try 
        {
            if (cmd == "set") 
            {
                cin >> clock;
                cout << clock << endl;
            } 
            
            else if (cmd == "tick") 
            {
                int tick = 1;
                cin >> tick;
                clock.Tick(tick);
                cout << clock << endl;
            } 
            
            else if (cmd == "set_timezone") 
            {
                string name;
                cin >> name;
                clock.SetTimezone(name);
            }
            
            else if (cmd == "add_timezone_info")
            {
                string name;
                int time_difference;
                cin >> name >> time_difference;
                clock.AddTimezoneInfo(name, time_difference);
            }
        } 
        catch (InvalidTimeException& e) 
        {
            cout << "Invalid time: " << e.input_time << endl;
        }
    }
return 0;
}
