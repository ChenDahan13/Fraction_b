#include <iostream>
#include <cmath>
#include "Fraction.hpp"
using namespace ariel;
using namespace std;


Fraction doubleToFraction(double num) {
    int newNumer = int(num * 1000);
    Fraction f(newNumer, 1000);
    f.reduceFraction();
    return f;
}

Fraction Fraction::rounded() const {
    int roundedNumerator = round(MAX_DIGITS * static_cast<double>(this->getNumerator()) / this->getDenominator());
    int roundedDenominator = MAX_DIGITS;
    return Fraction(roundedNumerator, roundedDenominator);
}

void Fraction::overFlowCheck(Fraction other) const{
    if(((this->numerator > 250000 || this->denominator > 250000) && (other.numerator > 250000 || other.denominator > 250000)) ||
      ((this->numerator < -250000 || this->denominator > 250000) && (other.numerator > 250000 || other.denominator > 250000)) ||
      ((this->numerator > 250000 || this->denominator < -250000) && (other.numerator > 250000 || other.denominator > 250000)) ||
      ((this->numerator > 250000 || this->denominator > 250000) && (other.numerator < -250000 || other.denominator > 250000)) ||
      ((this->numerator > 250000 || this->denominator > 250000) && (other.numerator > 250000 || other.denominator < -250000)) ||
      ((this->numerator < -250000 || this->denominator < -250000) && (other.numerator > 250000 || other.denominator > 250000))||
      ((this->numerator < -250000 || this->denominator > 250000) && (other.numerator < -250000 || other.denominator > 250000))||
      ((this->numerator < -250000 || this->denominator > 250000) && (other.numerator > 250000 || other.denominator < -250000))||
      ((this->numerator > 250000 || this->denominator < -250000) && (other.numerator < -250000 || other.denominator > 250000))||
      ((this->numerator > 250000 || this->denominator < -250000) && (other.numerator > 250000 || other.denominator < -250000))||
      ((this->numerator > 250000 || this->denominator > 250000) && (other.numerator < -250000 || other.denominator < -250000))||
      ((this->numerator < -250000 || this->denominator < -250000) && (other.numerator < -250000 || other.denominator > 250000))||
      ((this->numerator < -250000 || this->denominator < -250000) && (other.numerator > 250000 || other.denominator < -250000))||
      ((this->numerator < -250000 || this->denominator > 250000) && (other.numerator < -250000 || other.denominator < -250000))||
      ((this->numerator > 250000 || this->denominator < -250000) && (other.numerator < -250000 || other.denominator < -250000))||
      ((this->numerator < -250000 || this->denominator < -250000) && (other.numerator < -250000 || other.denominator < -250000))) {
        throw overflow_error("Operator can't be done");
      }

}

Fraction& Fraction::reduceFraction() {
    int d = __gcd(this->numerator, this->denominator);
    if(d < 0) {
        d *= -1;
    }
    if (d != 0) {
        this->numerator = this->numerator / d;
        this->denominator = this->denominator / d;
    }
    return *this;
}

string Fraction::to_string() {
    return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
}

Fraction Fraction::operator*(const ariel::Fraction& other) const{
    this->overFlowCheck(other);
    Fraction f(this->numerator*other.numerator, this->denominator*other.denominator);
    f.reduceFraction();
    return f;
} 

Fraction Fraction::operator+(const ariel::Fraction& other) const{
    this->overFlowCheck(other);
    int newNumerator = (this->numerator*other.denominator) + (this->denominator*other.numerator);
    int newDenominator = this->denominator*other.denominator;
    Fraction f(newNumerator, newDenominator);
    f.reduceFraction();
    return f;
}

Fraction Fraction::operator-(const ariel::Fraction& other) const {
    this->overFlowCheck(other);
    int newNumerator = (this->numerator*other.denominator) - (this->denominator*other.numerator);
    int newDenominator = this->denominator*other.denominator;
    Fraction f(newNumerator, newDenominator);
    f.reduceFraction();
    return f;
} 

Fraction Fraction::operator/(const ariel::Fraction& other) const{
    this->overFlowCheck(other);
    if(other.numerator == 0) {
        throw runtime_error("Other numerator is zero. Divide is illegal");
    }
    Fraction f(this->numerator*other.denominator, this->denominator*other.numerator);
    f.reduceFraction();
    return f;
} 

bool Fraction::operator>=(const ariel::Fraction& other) const{
    if(this->operator>(other) || this->operator==(other))
        return true;
    return false;
} 

bool Fraction::operator==(const ariel::Fraction& other) const{
    Fraction thisfrac = this->rounded();
    Fraction otherfrac = other.rounded();
    int sum = thisfrac.numerator*otherfrac.denominator - thisfrac.denominator*otherfrac.numerator;
    return (sum == 0) ? true : false;
} 

bool Fraction::operator<=(const ariel::Fraction& other) const{
    if(this->operator<(other) || this->operator==(other))
        return true;
    return false;
} 

bool Fraction::operator>(const ariel::Fraction& other) const{
    int sum = this->numerator*other.denominator - this->denominator*other.numerator;
    return (sum > 0) ? true : false;
} 

bool Fraction::operator<(const ariel::Fraction& other) const{
    int sum = other.numerator*this->denominator - other.denominator*this->numerator;
    return (sum > 0) ? true : false;
} 


// --------- Double --------- // 
Fraction Fraction::operator-(double other) const{
    Fraction f1 = doubleToFraction(other);
    return (this->operator-(f1));
} 

Fraction Fraction::operator+(double other) const{
    Fraction f1 = doubleToFraction(other);
    return (this->operator+(f1));
} 

Fraction Fraction::operator/(double other) const{
    Fraction f1 = doubleToFraction(other);
    return (this->operator/(f1));
} 

Fraction ariel::operator+(double other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1 + f);
}

Fraction ariel::operator-(double other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1 - f);
}

Fraction ariel::operator/(double other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1 / f);
}

bool ariel::operator>=(double other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1 >= f);
}

bool ariel::operator<=(double other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1 <= f);
}

bool ariel::operator>(double other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1 > f);
}

Fraction ariel::operator*(double other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1*f);
    
} 

bool Fraction::operator>=(double other) const{
    Fraction f1 = doubleToFraction(other);
    return (this->operator>=(f1));
} 

bool Fraction::operator>(double other) const{
    Fraction f1 = doubleToFraction(other);
    return (this->operator>(f1));
} 

bool Fraction::operator<(double other) const{
    Fraction f1 = doubleToFraction(other);
    return (this->operator<(f1));
} 


// --------- Int --------- // 
bool ariel::operator<(int other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1 < f);
}

bool ariel::operator>(int other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1 > f);
}

bool ariel::operator>=(int other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1 >= f);
}

bool ariel::operator<=(int other, const Fraction& f) {
    Fraction f1 = doubleToFraction(other);
    return (f1 <= f);
}

bool Fraction::operator<(int other) const{
    Fraction f1 = doubleToFraction(other);
    return (this->operator<(f1));
}

bool Fraction::operator>=(int other) const{
    Fraction f1 = doubleToFraction(other);
    return (this->operator>=(f1));
}

Fraction Fraction::operator+(int other) const{
    Fraction f1(other,1);
    return (this->operator+(f1));
} 

Fraction Fraction::operator-(int other) const{
    Fraction f1(other,1);
    return (this->operator-(f1));
} 


// -------- Self -------- // 
Fraction& Fraction::operator++() {
    int newNumer = this->numerator + this->denominator;
    this->numerator = newNumer;
    this->reduceFraction();
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction f(this->numerator, this->denominator);
    int newNumer = this->numerator + this->denominator;
    this->numerator = newNumer;
    this->reduceFraction();
    return f;
}

Fraction Fraction::operator--(int) {
    Fraction f(this->numerator, this->denominator);
    int newNumer = this->numerator - this->denominator;
    this->numerator = newNumer;
    this->reduceFraction();
    return f;
}

Fraction& Fraction::operator--() {
    int newNumer = this->numerator - this->denominator;
    this->numerator = newNumer;
    this->reduceFraction();
    return *this;
}


// -------- Stream -------- // 
ostream& ariel::operator<<(ostream& output, const Fraction& f) {
    output << f.numerator << "/" << f.denominator;
    return output;
}

istream& ariel::operator>>(istream& input, Fraction& f) {
    int num = 0, den = 0;
    input >> num >> den;
    if(input.fail()) {
        throw runtime_error("Input is not good");
    }
    if(den == 0) {
        throw runtime_error("Denominator can't be zero");
    }
    f = Fraction(num, den);
    return input;
}








