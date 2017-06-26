#ifndef CURRENCY_H_INCLUDED
#define CURRENCY_H_INCLUDED

#include <iostream>
using namespace std;


enum signType{plus1,minus1};

class illegalParameterValue
{
   public:
      illegalParameterValue():
            message("Illegal parameter value"){}
      illegalParameterValue(char* theMessage)
           {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};


class currency
{
public:
    currency(signType theSign=plus1,unsigned long theDollars=0,unsigned int theCents=0);
    ~currency() {}
    void setValue(signType,unsigned long,unsigned int);
    void setValue(double);
    signType getSign() const {return sign;}
    unsigned long getDollars() const {return dollars;}
    unsigned int getCents() const {return cents;}
    currency add(const currency&) const;
    currency& increment(const currency&);
    void output() const;
private:
    signType sign;
    unsigned long dollars;
    unsigned int cents;
};


#endif // CURRENCY_H_INCLUDED
