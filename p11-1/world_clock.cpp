#include "world_clock.h"

ostream& operator<<(ostream& os, WorldClock& c)
{
    int q=c.hour();
    int w=c.minute();
    int e=c.second();
  
    
    if( e >= 60 ){
        w = w + e/60;
        
        e = e-60*(e/60);
    }
    if( w >= 60 ){
        q = q + w/60;
        w = w-60*(w/60);
    }
    if( q>= 24 ){
        q = q % 24;
    }
    
    while(1){
        if( e < 0 ){
            e=e+60;
            w--;
        }
        
        if( w < 0 ){
            w=w+60;
            q--;
        }
        if( q < 0 ){
            q = 24+q;
        }
        
        if( q>=0 && w>=0 && e>=0 )
        break;
    }

    c.hour_ = q;
    c.min_ = w;
    c.sec_ = e;
    
    os<<q<<":"<<w<<":"<<e; 
    
    if(c.ig[c.last]!=0){
        cout<<" (+"<<c.ig[c.last]<<")";
    }  
    return os;
}

istream& operator>>(istream& is, WorldClock& c) 
{
    char txt[100];
    string a;
    string b;
    string d;
    
    is >> txt;

    char *token[3];
    
    token[0] = strtok(txt,":");
    token[1] = strtok(NULL,":");
    token[2] = strtok(NULL,":");
    
    a = token[0];
    b = token[1];
    d = token[2];
    a =a+":"+b+":"+d;
    
    
    int h,m,s;
    h = atoi(token[0]);
    m = atoi(token[1]);
    s = atoi(token[2]);
    
    if( h<0 || h>=24 ){
        InvalidTimeException k(a);
        throw k;
    }
    
    if( m<0 || m>=60 ){
        InvalidTimeException k(a);
        throw k;
    }
    
    if( s<0 || s>=60 ){
        InvalidTimeException k(a);
        throw k;
    }
    
    c.hour_ = h;
    c.min_ = m;
    c.sec_ = s;
    

}
