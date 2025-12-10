#pragma once

#include <iostream>

class Fraction{
    private:
        int numerator=0;
        unsigned int denominator=1;
        void fractionConversion();
        friend Fraction operationPerform(Fraction, Fraction, int);
        friend bool boolOperationPerform(Fraction, Fraction, int);
    public:
        Fraction();
        Fraction(int, int);
        Fraction(const Fraction&);
        Fraction(Fraction&&) noexcept;
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
        Fraction operator! ();
        Fraction operator- ();
        Fraction& operator-- ();
        Fraction& operator++ ();
        Fraction operator--(int);
        Fraction operator++(int);
        
        bool operator== (const Fraction&) const;
        bool operator>= (const Fraction&) const;
        bool operator<= (const Fraction&) const;
        bool operator> (const Fraction&) const;
        bool operator< (const Fraction&) const;
        bool operator!= (const Fraction&) const;

        friend std::istream& operator>>(std::istream&, Fraction&);
        friend std::ostream& operator<<(std::ostream&, const Fraction&);
};