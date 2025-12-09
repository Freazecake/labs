#include "Fraction.h"

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom)
{      
    fractionConversion(); 
}

Fraction::Fraction(const Fraction& other) : numerator(other.numerator),\
                                      denominator(other.denominator)
{
}

Fraction::~Fraction()
{
}

void Fraction::fractionConversion(){
    if(denominator==0){
        denominator=1; // idk what to do when denominator equals 0
    }
    if (denominator>numerator){
        numerator%=denominator;
    }
}

unsigned int denomNOD(unsigned int a, unsigned int b){
    unsigned int m = a > b ? a : b;
    unsigned int n = a < b ? a : b;
    while (n > 0)
    {
        int temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

unsigned int denomNOK(unsigned int a, unsigned int b){
    unsigned int c = denomNOD(a, b);
    return (a*b)/c;
}

void bringToSameDenom(Fraction& f1, Fraction& f2){
    unsigned int NOK = denomNOK(f1.denominator, f2.denominator);
    f1.numerator *= NOK/f1.denominator;
    f1.denominator = NOK;
    f2.numerator *= NOK/f2.denominator;
    f2.denominator = NOK;
}

double Fraction::fracToDouble(Fraction &frac){
    return static_cast<double>(frac.numerator) / frac.denominator;
}

Fraction operationPerform(Fraction a, Fraction b, int operators){
    switch (operators)
    {
    case 1:
        bringToSameDenom(a, b);
        a.numerator+=b.numerator;
        return a;
        break;
    case 2:
        bringToSameDenom(a, b);
        a.numerator-=b.numerator;
        return a;
        break;
    case 3:
        a.numerator*=b.numerator;
        a.denominator*=b.denominator;
        return a;
        break;
    case 4:
        a.numerator*=b.denominator;
        a.denominator*=b.numerator;
        return a;
        break;
    }
}

Fraction Fraction::operator+ (const Fraction& other) const{
    Fraction temp(*this);
    return operationPerform(temp, other, 1);
}

Fraction Fraction::operator- (const Fraction& other) const{
    Fraction temp(*this);
    return operationPerform(temp, other, 2);
}

Fraction Fraction::operator* (const Fraction& other) const{
    Fraction temp(*this);
    return operationPerform(temp, other, 3);
}

Fraction Fraction::operator/ (const Fraction& other) const{
    Fraction temp(*this);
    return operationPerform(temp, other, 4);
}

Fraction& Fraction::operator+= (const Fraction& other){
    Fraction temp(*this);
    *this=operationPerform(temp, other, 1);
    this->fractionConversion();
    return *this;
}

Fraction& Fraction::operator-= (const Fraction& other){
    Fraction temp(*this);
    *this=operationPerform(temp, other, 2);
    this->fractionConversion();
    return *this;
}

Fraction& Fraction::operator*= (const Fraction& other){
    Fraction temp(*this);
    *this=operationPerform(temp, other, 3);
    this->fractionConversion();
    return *this;
}

Fraction& Fraction::operator/= (const Fraction& other){
    Fraction temp(*this);
    *this=operationPerform(temp, other, 4);
    this->fractionConversion();
    return *this;
}

Fraction& Fraction::operator= (const Fraction& other){
    numerator=other.numerator;
    denominator=other.denominator;
    return *this;
}

Fraction& Fraction::operator! (){
    unsigned int temp{numerator};
    numerator=denominator;
    denominator=temp;
    return *this;
}

Fraction& Fraction::operator- (){
    numerator*=-1;
    return *this;
}

Fraction& Fraction::operator-- (){
    
    return *this;
}