#pragma once

#include <ios>

class Fraction{
    private:
        int numerator;
        unsigned int denominator;
        void fractionConversion();
        friend Fraction operationPerform(Fraction, Fraction, int);
    public:
        Fraction(int, int);
        Fraction(const Fraction&);
        ~Fraction();
        
        friend void bringToSameDenom(Fraction&, Fraction&);
        double fracToDouble(Fraction &);
        
        Fraction operator+ (const Fraction&) const;
        Fraction operator- (const Fraction&) const;
        Fraction operator* (const Fraction&) const;
        Fraction operator/ (const Fraction&) const;

        Fraction& operator+= (const Fraction&);
        Fraction& operator-= (const Fraction&);
        Fraction& operator*= (const Fraction&);
        Fraction& operator/= (const Fraction&);
        Fraction& operator= (const Fraction&);
        Fraction& operator! ();
        Fraction& operator- ();
        Fraction& operator-- ();
        Fraction& operator++ ();
        Fraction& operator--(int);
        Fraction& operator++(int);
        
        bool operator== (const Fraction&) const;
        bool operator>= (const Fraction&) const;
        bool operator<= (const Fraction&) const;
        bool operator> (const Fraction&) const;
        bool operator< (const Fraction&) const;
        bool operator!= (const Fraction&) const;

        friend std::ifstream& operator>>(const std::ifstream&, Fraction);
};