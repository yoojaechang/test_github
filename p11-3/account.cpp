#include "account.h"

Account :: Account(const string& name, unsigned int balance, double interest_rate)
{
    name_ = name;
    balance_ = balance;
    interest_rate_ = interest_rate;
}


unsigned int Account:: ComputeExpectedBalance(unsigned int n_years_later) const
{
    unsigned int expect = balance_;
    unsigned int init = balance_*interest_rate_;        
    expect = expect + init * n_years_later;
    return expect;
}

SavingAccount :: SavingAccount(const string& name, int balance, double interest_rate) : Account(name,balance,interest_rate)
{
}

unsigned int SavingAccount :: ComputeExpectedBalance(unsigned int n_years_later) const //: Account(name,balance,interest_rate)
{
    unsigned int init;
    float expect=balance_;
    for(int i=0;i<n_years_later;i++)
    {
        expect = expect*(1+interest_rate_);
    }
    return expect;
}

Account* CreateAccount(const string& type,const string& name, unsigned int balance, double interest_rate)
{
    Account* acc;
    if(type == "normal"){
        acc = new Account (name,balance,interest_rate);
        return acc;
    }
    else if(type == "saving"){
        acc = new SavingAccount (name,balance,interest_rate);
        return acc;
    }
}
