//
//  matrix_Calculator.h
//  Yifan's App
//
//  Created by Yifan Huang on 2018-12-29.
//  Copyright © 2018 Yifan Huang. All rights reserved.
//  Global function implementation to calculate matrix N X N, including both real number and complex number

#include "Matrix_Root.h"
//#include "Complex.h"
//#include <iostream>
//using namespace std;

#ifndef matrix_Calculator_h
#define matrix_Calculator_h


//function to calculate the 3 x 3 matrix of real number
Matrix_Root calcu_Matrix
(double&, double&, double&,
 double&, double&, double&);

//function to calculate the 3 x 3 matrix of complex number
Matrix_Root calcu_Matrix
(Complex&, Complex&, Complex&,
 Complex&, Complex&, Complex&);

//function calculating matrix 3 x 3 matrix of real number
Matrix_Root calcu_Matrix
(double&, double&, double&, double&,//first row
 double&, double&, double&, double&,//second row
 double&, double&, double&, double&);//third row

//function calculating 3 x 3 matrix of complex number
Matrix_Root calcu_Matrix
(Complex&, Complex&, Complex&, Complex&,//first row
 Complex&, Complex&, Complex&, Complex&,//second row
 Complex&, Complex&, Complex&, Complex&);//third row

//function calculating 4 x 4 matrix
Matrix_Root calcu_Matrix
(double&, double&, double&, double&, double&,//first row
 double&, double&, double&, double&, double&,//second row
 double&, double&, double&, double&, double&,//third row
 double&, double&, double&, double&, double&);//fourth row


//function calculating 4 x 4 matrix of complex type
Matrix_Root calcu_Matrix
(Complex&, Complex&, Complex&, Complex&, Complex&,//first row
 Complex&, Complex& , Complex&, Complex&, Complex&,//second row
 Complex&, Complex&, Complex&, Complex&, Complex&,//third row
 Complex&, Complex&, Complex&, Complex&, Complex&);//fourth row

Matrix_Root calcu_Matrix//decalre friend of the function calculating 5 x 5 matrix
(double&, double&, double&, double&, double&, double&,//first row
 double&, double&, double&, double&, double&, double&,//second row
 double&, double&, double&, double&, double&, double&,//third row
 double&, double&, double&, double&, double&, double&,//fourth row
 double&, double&, double&, double&, double&, double&);//fifth row

Matrix_Root calcu_Matrix//declare friend of the function calculating 5 x 5 matrix
(Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//first row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//second row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//third row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fourth row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&);//fifth row

Matrix_Root calcu_Matrix//decalre friend of the function calculating 6 x 6 matrix
(double&, double&, double&, double&, double&, double&, double&,//first row
 double&, double&, double&, double&, double&, double&, double&,//second row
 double&, double&, double&, double&, double&, double&, double&,//third row
 double&, double&, double&, double&, double&, double&, double&,//fourth row
 double&, double&, double&, double&, double&, double&, double&,//fifth row
 double&, double&, double&, double&, double&, double&, double&);//sixth row

Matrix_Root calcu_Matrix//declare friend of the function calculating 6 x 6 matrix
(Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//first row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//second row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//third row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fourth row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fifth row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&);//sixth row

Matrix_Root calcu_Matrix//decalre friend of the function calculating 7 x 7 matrix
(double&, double&, double&, double&, double&, double&, double&, double&,//first row
 double&, double&, double&, double&, double&, double&, double&, double&,//second row
 double&, double&, double&, double&, double&, double&, double&, double&,//third row
 double&, double&, double&, double&, double&, double&, double&, double&,//fourth row
 double&, double&, double&, double&, double&, double&, double&, double&,//fifth row
 double&, double&, double&, double&, double&, double&, double&, double&,//sixth row
 double&, double&, double&, double&, double&, double&, double&, double&);//seventh row

Matrix_Root calcu_Matrix//declare friend of the function calculating 7 x 7 matrix
(Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//first row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//second row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//third row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fourth row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fifth row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//sixth row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&);//seventh row

Matrix_Root calcu_Matrix//decalre friend of the function calculating 8 x 8 matrix
(double&, double&, double&, double&, double&, double&, double&, double&, double&,//first row
 double&, double&, double&, double&, double&, double&, double&, double&, double&,//second row
 double&, double&, double&, double&, double&, double&, double&, double&, double&,//third row
 double&, double&, double&, double&, double&, double&, double&, double&, double&,//fourth row
 double&, double&, double&, double&, double&, double&, double&, double&, double&,//fifth row
 double&, double&, double&, double&, double&, double&, double&, double&, double&,//sixth row
 double&, double&, double&, double&, double&, double&, double&, double&, double&,//seventh row
 double&, double&, double&, double&, double&, double&, double&, double&, double&);//eighth row

Matrix_Root calcu_Matrix//declare friend of the function calculating 8 x 8 matrix
(Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//first row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//second row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//third row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fourth row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//fifth row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//sixth row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&,//seventh row
 Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&, Complex&);//eighth row

Matrix_Root calcu_Matrix//decalre friend of the function calculating 9 x 9 matrix
(double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//first row
 double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//second row
 double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//third row
 double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//fourth row
 double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//fifth row
 double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//sixth row
 double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//seventh row
 double&, double&, double&, double&, double&, double&, double&, double&, double&, double&,//eighth row
 double&, double&, double&, double&, double&, double&, double&, double&, double&, double&);//ninth row

Matrix_Root calcu_Matrix//declare friend of the function calculating 9 x 9 matrix
(Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//first row
 Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//second row
 Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//third row
 Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//fourth row
 Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//fifth row
 Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//sixth row
 Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//seventh row
 Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,//eighth row
 Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&,Complex&);//nineth row

Matrix_Root calcu_Matrix//decalre friend of the function calculating 10 x 10 matrix
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

Matrix_Root calcu_Matrix//declare friend of the function calculating 10 x 10 matrix
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

#endif /* matrix_Calculator_h */
