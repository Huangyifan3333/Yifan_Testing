//
//  Matrix_Root.h
//  Yifan's App
//
//  Created by Yifan Huang on 2018-12-25.
//  Copyright © 2018 Yifan Huang. All rights reserved.
//
#include "Complex.h"
#include <iostream>
using namespace std;

#ifndef Matrix_Root_h
#define Matrix_Root_h
class Matrix_Root{
    friend class Complex;//declare Complex as a friend
    
    friend Matrix_Root calcu_Matrix//decalre friend of the function calculating 2 x 2 matrix
    (double&, double&, double&,//first row
     double&, double&, double&);//second row
    
    friend Matrix_Root calcu_Matrix//declare friend of the function calculating 2 x 2 matrix
    (Complex&, Complex&, Complex&,//first row
     Complex&, Complex&, Complex&);//second row
    
    friend Matrix_Root calcu_Matrix//decalre friend of the function calculating 3 x 3 matrix
    (double&, double&, double&, double&,//first row
     double&, double&, double&, double&,//second row
     double&, double&, double&, double&);//third row
    
    friend Matrix_Root calcu_Matrix//declare friend of the function calculating 3 x 3 matrix
    (Complex&, Complex&, Complex&, Complex&,//first row
     Complex&, Complex&, Complex&, Complex&,//second row
     Complex&, Complex&, Complex&, Complex&);//third row
    
    friend Matrix_Root calcu_Matrix//decalre friend of the function calculating 4 x 4 matrix
    (double&, double&, double&, double&, double&,//first row
     double&, double&, double&, double&, double&,//second row
     double&, double&, double&, double&, double&,//third row
     double&, double&, double&, double&, double&);//fourth row
    
    friend Matrix_Root calcu_Matrix//declare friend of the function calculating 4 x 4 matrix
    (Complex&, Complex&, Complex&, Complex&, Complex&,//first row
     Complex&, Complex&, Complex&, Complex&, Complex&,//second row
     Complex&, Complex&, Complex&, Complex&, Complex&,//third row
     Complex&, Complex&, Complex&, Complex&, Complex&);//fourth row
    
    friend Matrix_Root calcu_Matrix//decalre friend of the function calculating 5 x 5 matrix
    (double&, double&, double&, double&, double&, double&,//first row
     double&, double&, double&, double&, double&, double&,//second row
     double&, double&, double&, double&, double&, double&,//third row
     double&, double&, double&, double&, double&, double&,//fourth row
     double&, double&, double&, double&, double&, double&);//fifth row
    
    friend Matrix_Root calcu_Matrix//declare friend of the function calculating 5 x 5 matrix
    (Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//first row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//second row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//third row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fourth row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&);//fifth row
    
    friend Matrix_Root calcu_Matrix//decalre friend of the function calculating 6 x 6 matrix
    (double&, double&, double&, double&, double&, double&, double&,//first row
     double&, double&, double&, double&, double&, double&, double&,//second row
     double&, double&, double&, double&, double&, double&, double&,//third row
     double&, double&, double&, double&, double&, double&, double&,//fourth row
     double&, double&, double&, double&, double&, double&, double&,//fifth row
     double&, double&, double&, double&, double&, double&, double&);//sixth row
    
    friend Matrix_Root calcu_Matrix//declare friend of the function calculating 6 x 6 matrix
    (Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//first row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//second row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//third row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fourth row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fifth row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&);//sixth row
    
    friend Matrix_Root calcu_Matrix//decalre friend of the function calculating 7 x 7 matrix
    (double&, double&, double&, double&, double&, double&, double&, double&,//first row
     double&, double&, double&, double&, double&, double&, double&, double&,//second row
     double&, double&, double&, double&, double&, double&, double&, double&,//third row
     double&, double&, double&, double&, double&, double&, double&, double&,//fourth row
     double&, double&, double&, double&, double&, double&, double&, double&,//fifth row
     double&, double&, double&, double&, double&, double&, double&, double&,//sixth row
     double&, double&, double&, double&, double&, double&, double&, double&);//seventh row
    
    friend Matrix_Root calcu_Matrix//declare friend of the function calculating 7 x 7 matrix
    (Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//first row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//second row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//third row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fourth row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fifth row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//sixth row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&);//seventh row
    
    friend Matrix_Root calcu_Matrix//decalre friend of the function calculating 8 x 8 matrix
    (double&, double&, double&, double&, double&, double&, double&, double&, double&,//first row
     double&, double&, double&, double&, double&, double&, double&, double&, double&,//second row
     double&, double&, double&, double&, double&, double&, double&, double&, double&,//third row
     double&, double&, double&, double&, double&, double&, double&, double&, double&,//fourth row
     double&, double&, double&, double&, double&, double&, double&, double&, double&,//fifth row
     double&, double&, double&, double&, double&, double&, double&, double&, double&,//sixth row
     double&, double&, double&, double&, double&, double&, double&, double&, double&,//seventh row
     double&, double&, double&, double&, double&, double&, double&, double&, double&);//eighth row
    
    friend Matrix_Root calcu_Matrix//declare friend of the function calculating 8 x 8 matrix
    (Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//first row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//second row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//third row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fourth row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fifth row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//sixth row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//seventh row
     Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&);//eighth row
    
    friend Matrix_Root calcu_Matrix//decalre friend of the function calculating 9 x 9 matrix
    (double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//first row
     double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//second row
     double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//third row
     double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//fourth row
     double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//fifth row
     double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//sixth row
     double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//seventh row
     double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//eighth row
     double&, double&, double&, double&, double&, double&, double&, double&, double&, double&);//ninth row
    
    friend Matrix_Root calcu_Matrix//declare friend of the function calculating 9 x 9 matrix
    (Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//first row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//second row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//third row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//fourth row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//fifth row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//sixth row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//seventh row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//eighth row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&);//nineth row
    
    friend Matrix_Root calcu_Matrix//decalre friend of the function calculating 10 x 10 matrix
    (double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,//first row
     double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,//second row
     double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,//third row
     double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,//fourth row
     double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,//fifth row
     double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,//sixth row
     double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,//seventh row
     double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,//eighth row
     double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,//ninth row
     double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&);//tenth row
    
    friend Matrix_Root calcu_Matrix//declare friend of the function calculating 10 x 10 matrix
    (Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,
     //first row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,
     //second row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,
     //third row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,
     //fourth row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,
     //fifth row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,
     //sixth row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,
     //seventh row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,
     //eighth row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,
     //nineth row
     Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&);
    //tenth row
    
    friend ostream& operator<<(ostream&,const Matrix_Root&);//output "<<" overload
    
private:
    int n{0};//declare an int varibale
    double* ptrD_root{nullptr};//decalre a pointer of double type
    Complex* ptrC_root{nullptr};//declare a pointer of Complex type
    
public:
    Matrix_Root();//default constructor
    void set_Matrix_Root(const double&, const double&);//change the root's value of 2 x 2 matrix
    void set_Matrix_Root(const Complex&, const Complex&);//change root's value of 2 x 2 matrix
    void set_Matrix_Root(const double&, const double&, const double&);//change the value of 3 x 3 matrix
    void set_Matrix_Root(const Complex&, const Complex&, const Complex&);//change root's value of 3 x 3 matrix
    void set_Matrix_Root(const double&, const double&, const double&, const double&);//change the value of 4 x 4 matrix
    void set_Matrix_Root(const Complex&, const Complex&, const Complex&, const Complex&);
    //change root's value of 4 x 4 matrix
    void set_Matrix_Root(const double&, const double&, const double&, const double&, const double&);
    //change the value of 5 x 5 matrix
    void set_Matrix_Root(const Complex&, const Complex&, const Complex&, const Complex&, const Complex&);
    //change root's value of 5 x 5 matrix
    void set_Matrix_Root(const double&, const double&, const double&, const double&, const double&, const double&);
    //change the value of 6 x 6 matrix
    void set_Matrix_Root(const Complex&, const Complex&, const Complex&, const Complex&, const Complex&, const Complex&);
    //change root's value of 6 x 6 matrix
    void set_Matrix_Root(const double&, const double&, const double&, const double&, const double&, const double&, const double&);
    //change the value of 7 x 7 matrix
    void set_Matrix_Root(const Complex&, const Complex&, const Complex&, const Complex&, const Complex&, const Complex&, const Complex&);
    //change root's value of 7 x 7 matrix
    void set_Matrix_Root(const double&, const double&, const double&, const double&, const double&, const double&, const double&, const double&);
    //change the value of 8 x 8 matrix
    void set_Matrix_Root(const Complex&, const Complex&, const Complex&, const Complex&, const Complex&, const Complex&, const Complex&, const Complex&);
    //change root's value of 8 x 8 matrix
    void set_Matrix_Root(const double&, const double&, const double&, const double&, const double&, const double&, const double&, const double&, const double&);
    //change the value of 9 x 9 matrix
    void set_Matrix_Root(const Complex&,const Complex&,const Complex&,const Complex&,const Complex&,const Complex&,const Complex&,const Complex&,const Complex&);
    //change root's value of 9 x 9 matrix
    void set_Matrix_Root
    (const double&, const double&, const double&, const double&, const double&, const double&, const double&, const double&, const double&, const double&);
    //change the value of 10 x 10 matrix
    void set_Matrix_Root
    (const Complex&,const Complex&,const Complex&,const Complex&,const Complex&,const Complex&,const Complex&,const Complex&,const Complex&,const Complex&);
    //change root's value of 10 x 10 matrix
   
~Matrix_Root();//destructor
};

#endif /* Matrix_Root_h */
