#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

using namespace std;
namespace ariel {
    class Fraction {
        int numerator;
        int denominator;
        public:
            Fraction(int num = 1, int den = 2): numerator(num){  
                if(den != 0) {
                    this->denominator = den;
                } else {
                    throw invalid_argument("Denominator can't be zero");
                    return;
                }
                this->reduceFraction();
            }
            Fraction(double num) {
                this->numerator = int(num * 1000);
                this->denominator = 1000;
                this->reduceFraction();
            }
            void setNumerator(int num) {
                this->numerator = num;
            }
            void setDenominator(int num) {
                this->denominator = num;
            }
            int getNumerator() const{
                return  numerator;
            }
            int getDenominator() const{
                return denominator;
            }
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
            bool isNegative() const;
            /*--------------------------------------*/
            
            /*--------- Stream Operators ---------*/
            friend ostream& operator<<(ostream& output, const Fraction& fract);
            friend istream& operator>>(istream& input, Fraction& fract);
            /*------------------------------------*/

        
            
    };
}
ariel::Fraction doubleToFraction(double other);