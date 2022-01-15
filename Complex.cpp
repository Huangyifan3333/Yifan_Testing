//
//  Complex.cpp
//  Yifan's App
//
//  Created by Yifan Huang on 2018-12-17.
//  Copyright © 2018 Yifan Huang. All rights reserved.
//

#include "Complex.h"
//#include <iostream>
#include <cmath>
#include <iomanip>
//#include <sstream>
using namespace std;

//default constructor
Complex::Complex():x(0),y(0),degree(0){//set default value of data members
    //x = 0;
    //y = 0;
    //degree = 0;
}// end function

//constructor with real part
Complex::Complex(const double& real):x(real),y(0)
{
    //x = real;
    //y = 0;
    degree = atan2(y, x)*(180/PI);//calculate the phase angle
}//end function

//constructor with initialzing the data value
Complex::Complex(const double& real, const double& imag):x(real),y(imag)
{//initialzie the data members x and y
    //x = real;//real part
    //y = imag;//imaginary part
    degree = atan2(y, x)*(180/PI);//calculate the phase angle
}//end function

//function to change real part only
void Complex::set_Comp(const double& real){
    x = real;//assign real part
    y = 0;
    degree = atan2(y, x)*(180/PI);//calculate the phase angle
}//end function

//function to change data members
void Complex::set_Comp(const double& real, const double& imag){
    x = real;//real part
    y = imag;//imaginary part
    degree = atan2(y,x)*(180/PI);//phase angle
}//end function

//function to add two complex numbers
void Complex::add_Comp(const Complex& a){
    x = x + a.x;//add two real parts from a and b
    y = y + a.y;//add two imaginary parts from a and b
    degree = atan2(y, x)*(180/PI);//phase angle
}//end function

Complex Complex::operator+(const Complex& a){//operator + overload
    return Complex(x+a.x, y+a.y);
}//end function

//function to suntract two complex numbers
void Complex::subtr_Comp(const Complex& a){
    x = x - a.x;//subtract two real parts from a to b
    y = y - a.y;//subtract two imaginary parts from a to b
    degree = atan2(y, x)*(180/PI);//phase angle
}//end function

Complex Complex::operator-(const Complex& a){//operator - overload
    return Complex(x-a.x, y-a.y);
}//end function

void Complex::operator-=(const Complex& a){//operator -= overload
    x = x - a.x;
    y = y - a.y;
    degree = atan2(y,x)*(180/PI);
}//end function

//function to multiply a complex number and a real number
void Complex::multip_Comp(const double& a) {
    x = x*a;//multiply real part
    y = y*a;//multipy imaginary part
    degree = atan2(y,x)*(180/PI);//phase angle
}

//function to multiply two complex numbers
void Complex::multip_Comp(const Complex& a){
    double hold{0};//declare to hold the value
    hold = x*a.x - y*a.y;//calculate the real part of multiplication storing in hold
    y = x*a.y + y*a.x;//calculate the imaginary part of multiplication
    x = hold;//assign the hold value to x
    degree = atan2(y, x)*(180/PI);//phase angle
}//end function

Complex Complex::operator*(const Complex& a){//operator * overload
    return Complex(x*(a.x)-y*(a.y), x*(a.y)+y*(a.x));
}//end function

void Complex::div_Comp(const Complex& a){
    double hold{0};//declare to hold the value
    hold = (x*a.x+y*a.y)/((a.x)*(a.x)+(a.y)*(a.y));//calculate the real part
    y = (-x*a.y+y*a.x)/((a.x)*(a.x)+(a.y)*(a.y));//calculate the imaginary part
    x = hold;//assign the hold value to x
    degree = atan2(y, x)*(180/PI);//phase angle
}//end function

Complex Complex::operator/(const Complex& a){//operator / overload
    return Complex((x*a.x+y*a.y)/((a.x)*(a.x)+(a.y)*(a.y)), (-x*a.y+y*a.x)/((a.x)*(a.x)+(a.y)*(a.y)));
}//end function

void Complex::operator/=(const Complex& a){//operator /= overload
    double hold{0};//declare to hold the value
    hold = (x*a.x+y*a.y)/((a.x)*(a.x)+(a.y)*(a.y));//calculate the real part
    y = (-x*a.y+y*a.x)/((a.x)*(a.x)+(a.y)*(a.y));//calculate the imaginary part
    x = hold;//assign the hold value to x
    degree = atan2(y, x)*(180/PI);//phase angle
}//end function

//return real part of complex numbner
double Complex::real_Comp() const{
    return x;
}//end function

//return imaginary part of complex number
double Complex::imag_Comp() const{
    return y;
}//end function

//return the phase angle
double Complex::angle_Comp() const{
    return degree;
}//end function
  
//print
void Complex::print_Comp() const{
    cout << fixed << setprecision(2) << x << "+" << "j*" << y << endl;
}//end function

//function to compare two Complex numbers
bool Complex::compare_Comp(const Complex& a){
    if ((x==a.x) && (y==a.y))//compare both real part and imaginary part
        return true;
    else
        return false;
}//end function

ostream& operator<<(ostream& output, const Complex& comp){
    output << fixed << setprecision(2) << comp.x << "+" << "j*" << comp.y;
    return output;
}

istream& operator>>(istream& input, Complex& comp){
    string hold;//string format is "a+j*b" or "a+jb" or "a+Jb"
    input >> hold;//input sequence as string type
    bool b{true};
    for (const auto& a:hold){
        if (a=='+'||a=='j'||a=='J'){//check input's format
            b = false;//complex format
            break;
        }
        else
            b = true;//double format
    }
    if (b==false){//if string formatt is complex number
        double x{0},y{0};//temporarily store real and imagine value
        for (size_t i{0}; i < hold.size(); ++i){//go through string
            if (hold[i] == '+'){
                x = stod(hold,&i);//convert character before "+" to double and assign to x
            }
            else if (((hold[i] == 'j')||(hold[i] == 'J')) && (hold[i+1] != '*')){
                y = stod(hold.substr(i+1,hold.size()-i));
                //convert characters after"j or J" to double and assign to y
                comp.set_Comp(x, y);//set complex real and imaginary value
                break;
            }
            else if (((hold[i] == 'j')||(hold[i] == 'J')) && (hold[i+1] == '*')){
                y = stod(hold.substr(i+2,hold.size()-i-1));
                //convert characters after"j* or J*" to double and assign to y
                comp.set_Comp(x, y);//set complex real and imaginary value
                break;
            }
        }
    }
    else{//if string format is double
        comp.set_Comp(stod(hold));//set complex real value
    }
    if ((comp.x == 0) && (comp.y == 0)){
        throw ("Bad input");//throw exception if wrong format of string is used
    }
    return input;
}

istringstream& operator>>(istringstream& iss, Complex& comp){//iss >> Complex
    string hold1;
    hold1 = iss.str();
    hold1.append(" ");
    for (size_t i{0}; i<hold1.size();++i){
        if (hold1[i] == ' '){
            string hold=hold1.substr(0,i);
            bool b{true};
            for (const auto& a:hold){
                if (a=='j'||a=='J'){
                    b = false;
                    break;
                }
                else{
                    b = true;
                }
            }
            if (b==false){//if string formatt is complex number
                double x{0},y{0};//temporarily store real and imagine value
                for (size_t i{0}; i < hold.size(); ++i){//go through string
                    if (hold[i] == '+'){
                        x = stod(hold,&i);//convert character before "+" to double and assign to x
                    }
                    else if (((hold[i] == 'j')||(hold[i] == 'J')) && (hold[i+1] != '*')){
                        y = stod(hold.substr(i+1,hold.size()-i));
                        //convert characters after"j or J" to double and assign to y
                        comp.set_Comp(x, y);//set complex real and imaginary value
                        break;
                    }
                    else if (((hold[i] == 'j')||(hold[i] == 'J')) && (hold[i+1] == '*')){
                        y = stod(hold.substr(i+2,hold.size()-i-1));
                        //convert characters after"j* or J*" to double and assign to y
                        comp.set_Comp(x, y);//set complex real and imaginary value
                        break;
                    }
                }
            }
            else{//if string format is double
                comp.set_Comp(stod(hold));//set complex real value
            }
            hold1 = hold1.substr(i+1,string::npos);
            iss.str(hold1);
            break;
        }
    }
    return iss;
}//end

Complex::~Complex(){
//destructor
}
