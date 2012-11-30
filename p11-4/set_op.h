#include <map>
#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
using namespace std;

template <typename T>
set<T> operator+(const set<T>& lhs, const set<T>& rhs)
{
    set<double> s;
    
    set<double>::iterator fir=lhs.begin();
    set<double>::iterator sec=rhs.begin();
    
    for(;fir!=lhs.end();fir++)
    {
        s.insert(*fir+*sec);
        sec++;
    }
    
    return s;
}
template <typename T>
set<T> operator-(const set<T>& lhs, const set<T>& rhs)
{
    set<double> s;
    set<double>::iterator fir=lhs.begin();
    set<double>::iterator sec=rhs.begin();
    for(;fir!=lhs.end();fir++)
    {
        s.insert(*fir-*sec);
        sec++;
    }
    return s;
}
template <typename T>
set<T> operator*(const set<T>& lhs, const set<T>& rhs)
{
    set<double> s;
    set<double>::iterator fir=lhs.begin();
    set<double>::iterator sec=rhs.begin();
    for(;fir!=lhs.end();fir++)
    {
        s.insert(*fir * *sec);
        sec++;
    }
    
    return s;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s)
{
    os << "{ ";
    set<double>::iterator it=s.begin();
    for(;it!=s.end();it++) os << *it <<" ";
    os <<"}";
    return os;
}
template <typename T>
istream& operator>>(istream& is, set<T>& s)
{
    int i;
    int num;
    double num1;
    is >> num;
    for(i=0;i<num;i++)
    {
        is >> num1;
        s.insert(num1);
    }
}
template <typename T, typename S>
set<T> Cast(const set<S>& s)
{    
    set<T> ret;
    set<int>::iterator it=s.begin();
    for(;it!=s.end();it++)
    ret.insert(static_cast<S>(*it));   
    return ret;   
}
