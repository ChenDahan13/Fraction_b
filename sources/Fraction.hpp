#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>


using namespace std;
namespace ariel {
    const int MAX_DIGITS = 1000;
    class Fraction {
        int numerator;
        int denominator;
        public:
            Fraction(int num = 1, int den = 2);
            Fraction(double num);
            void setNumerator(int num);
            void setDenominator(int num);
            int getNumerator() const;
            int getDenominator() const;
            string to_string();

            /*----------- Fractions Operators ----------*/
            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;
            bool operator==(const Fraction& other) const;
            bool operator>(const Fraction& other) const;
            bool operator<(const Fraction& other) const;
            bool operator<=(const Fraction& other) const;
            /*------------------------------------------*/
            
            /*------------ Int Operators ------------*/
            Fraction operator-(int other) const;
            Fraction operator+(int other) const;
            bool operator<(int other) const;
            bool operator>=(int other) const;
            friend bool operator<(int other, const Fraction& fract);
            friend bool operator>(int other, const Fraction& fract);
            friend bool operator>=(int other, const Fraction& fract);
            friend bool operator<=(int other, const Fraction& fract);
            /*---------------------------------------*/
            
            /*------------ Double Operators ----------*/
            Fraction operator+(double other) const;
            Fraction operator-(double other) const;
            Fraction operator/(double other) const;
            friend Fraction operator*(double other, const Fraction& fract);
            bool operator>(double other) const;
            bool operator<(double other) const;
            bool operator>=(double other) const;
            friend Fraction operator+(double other, const Fraction& fract);
            friend Fraction operator-(double other, const Fraction& fract);
            friend Fraction operator/(double other, const Fraction& fract);
            friend bool operator>(double other, const Fraction& fract);
            friend bool operator<=(double other, const Fraction& fract);
            friend bool operator>=(double other, const Fraction& fract);
            /*----------------------------------------*/
            
            /*----------- Self Operators -----------*/
            Fraction& operator++();
            Fraction operator++(int);
            Fraction& operator--();
            Fraction operator--(int);
            Fraction& reduceFraction();
            /*--------------------------------------*/
            
            /*--------- Stream Operators ---------*/
            friend ostream& operator<<(ostream& output, const Fraction& fract);
            friend istream& operator>>(istream& input, Fraction& fract);
            /*------------------------------------*/

            /*--------- Other ----------*/
            void overFlowCheck(Fraction other) const;
            Fraction rounded() const;
            /*--------------------------*/

        
            
    };
}
ariel::Fraction doubleToFraction(double other);