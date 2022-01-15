//
//  Complex.h
//  Yifan's App
//
//  Created by Yifan Huang on 2018-12-17.
//  Copyright © 2018 Yifan Huang. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

#ifndef Complex_h
#define Complex_h

class Complex{
    friend class Matrix_Root;//declare Rational class as friend of Complex class
    friend ostream& operator<<(ostream&, const Complex&);//overload output << complex number
    friend istream& operator>>(istream&, Complex&);//overload input >> complex number
    friend istringstream& operator>>(istringstream&, Complex&);//overload istringstream object >> complex
private:
    double x;
    double y;
    double degree;
    double PI = 3.141592653;//define pi number

public:
    Complex();//default constructor
    Complex(const double&);//constructor taking real part only
    Complex(const double&, const double&);//constructor with parameters(real + imagine)
    void set_Comp(const double&);//set new real part only
    void set_Comp(const double&, const double&);//set new real and imaginary part
    void add_Comp(const Complex&);//addition of two complex numbers
    Complex operator+(const Complex&);//operator + overload
    void subtr_Comp(const Complex&);//suntraction of two compex numbers
    Complex operator-(const Complex&);//operator - overload
    void operator-=(const Complex&);//operator -= overload
    void multip_Comp(const double&);//multiplication between complex and real number
    void multip_Comp(const Complex&);//multiplication of two complex numbers
    Complex operator*(const Complex&);//operator * overload
    void div_Comp(const Complex&);//division of two complex numbers
    Complex operator/(const Complex&);//operator / overload
    void operator/=(const Complex&);//operator /= overload
    double real_Comp() const;//take the real part of complex numbers
    double imag_Comp() const;//take the imaginary part of complex numbers
    double angle_Comp() const;//take the phase angle 
    void print_Comp() const;//print complex number
    bool compare_Comp(const Complex&);//compare two complex numbers and return noolean value
    
~Complex();//destructor
};//end of class



#endif /* Complex_h */
