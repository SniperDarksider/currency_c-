#include <iostream>
#include "currency.h"
#include <exception>
using namespace std;




currency::currency(signType theSign,unsigned long theDollars,unsigned int theCents)
{
    setValue(theSign,theDollars,theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars,unsigned int theCents)
{
    if(theCents>99)
        throw illegalParameterValue("Cents should be <100");
    sign=theSign;
    dollars=theDollars;
    cents=theCents;
}

void currency::setValue(double theAmount)
{
    if(theAmount<0) {sign=minus1;theAmount=-theAmount;}
    else sign=plus1;
    dollars =(unsigned long) theAmount;
    cents=(unsigned int) ((theAmount+0.001-dollars)*100);
}

currency currency::add(const currency& x) const
{
    long a1,a2,a3;
    currency result;
    a1=dollars*100+cents;
    if(sign==minus1) a1=-a1;

    a2=x.dollars*100+x.cents;
    if(x.sign==minus1) a2=-a2;

    a3=a1+a2;

    if(a3<0) {result.sign=minus1;a3=-a3;}
    else result.sign=plus1;
    result.dollars=a3/100;
    result.cents=a3-result.dollars*100;

    return result;
}


currency& currency::increment(const currency& x)
{
    *this=add(x);
    return *this;
}

void currency::output() const
{
    if (sign==minus1) cout<<'-';
    cout <<'$'<<dollars<<'.';
    if(cents<10) cout<<'0';
    cout<<cents;
}




