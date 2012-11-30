#include "datd.h"
void Date::NextDay(){
    if (month_<8 && month_%2==1){
        if (day_<31)
            day_++;
        else{
            month_++;
            day_=1;
        }
    }
    else if (month_==2){
        if (GetDaysInYear(year_)==366){
            if (day_<29)
                day_++;
            else{
                month_++;
                day_=1;
            }
    }
    else if (GetDaysInYear(year_)==365){
      if (day_<28)
        day_++;
      else{
        month_++;
        day_=1;
      }
    }
  }

  else if (month_<8 && month_%2==0){
    if (day_<30)
      day_++;
    else{
      month_++;
      day_=1;
    }
  }

  else if (month_>=8 && month_%2==0){
    if (day_<31)
      day_++;
    else{
      month_++;
      day_=1;
    }
  }

  else if (month_>=8 && month_%2==1){
    if (day_<30)
      day_++;
    else{
      month_++;
      day_=1;
    }
  }

  if (month_==13){
    month_=1;
    year_++;
  }
    }
void Date::NextDay(int n){

  for (int i=0;i<n;i++){
  if (month_<8 && month_%2==1){
    if (day_<31)
      day_++;
    else{
      month_++;
      day_=1;
    }
  }

  else if (month_==2){
    if (GetDaysInYear(year_)==366){
      if (day_<29)
        day_++;
      else{
        month_++;
        day_=1;
      }
    }
    else if (GetDaysInYear(year_)==365){
      if (day_<28)
        day_++;
      else{
        month_++;
        day_=1;
      }
    }
  }

  else if (month_<8 && month_%2==0){
    if (day_<30)
      day_++;
    else{
      month_++;
      day_=1;
    }
  }

  else if (month_>=8 && month_%2==0){
    if (day_<31)
      day_++;
    else{
      month_++;
      day_=1;
    }
  }

  else if (month_>=8 && month_%2==1){
    if (day_<30)
      day_++;
    else{
      month_++;
      day_=1;
    }
  }

  if (month_==13){
    month_=1;
    year_++;
  }
  }
  
  for (int i=0;i>n;i--){
    if (day_!=1)
      day_--;
    else{
      if (month_==2 || month_==4 || month_==6 || month_==8 || month_==9 || month_==11){
        day_=31;
        month_--;
      }

      else if (month_==1){
        day_=31;
        month_=12;
        year_--;
      }

      else if (month_==3){
        if (GetDaysInYear(year_)==366)
          day_=29;
        else
          day_=28;

        month_=2;
      }

      else if (month_==5 || month_==7 || month_==10 || month_==12){
        day_=30;
        month_--;
      }
    }
  }

}
