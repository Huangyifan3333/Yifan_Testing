//
//  Matrix_Root.cpp
//  Yifan's App
//
//  Created by Yifan Huang on 2018-12-25.
//  Copyright © 2018 Yifan Huang. All rights reserved.
//  implemantation Matrix_Root member function as well as the global function ot calcu_Matrix

#include "Matrix_Root.h"
//#include "Complex.h"
//#include <iostream>
using namespace std;

Matrix_Root::Matrix_Root(){
//default constructor
}

//change the root's value of 2 x 2 matrix of real number
void Matrix_Root::set_Matrix_Root(const double& c1, const double& c2){
    n = 2;//two roots
    ptrD_root = new double[n];//create a dynamic root's array of real number
    ptrD_root[0] = c1;//assign the value to root 1
    ptrD_root[1] = c2;//assign the value to root 2
}//end function

//change the root's value of 2 x 2 matrix of complex number
void Matrix_Root::set_Matrix_Root(const Complex& c1, const Complex& c2){
    n = 2;//two roots
    ptrC_root = new Complex[n];//creat a dynamic roots' array of complex type
    ptrC_root[0] = c1;//assign the value to root 1
    ptrC_root[1] = c2;//assign the value to root 2
}//end function

//change the root's value of 3 x 3 matrix of real number
void Matrix_Root::set_Matrix_Root(const double& c1, const double& c2, const double& c3){
    n = 3;//three roots
    ptrD_root = new double[n];// create a dynamic roots' array
    ptrD_root[0] = c1;//assign the value to root 1
    ptrD_root[1] = c2;//assign the value to root 2
    ptrD_root[2] = c3;//assign the value to root 3
}//end function

//change the root's value of 3 x 3 matrix of complex value
void Matrix_Root::set_Matrix_Root(const Complex& c1, const Complex& c2, const Complex& c3){
    n = 3;//three roots
    ptrC_root = new Complex[n];//create a dynamc root's array
    ptrC_root[0] = c1;//assign the value to root 1
    ptrC_root[1] = c2;//assign the value to root 2
    ptrC_root[2] = c3;//assign the value to root 3
}//end function

//change the value of 4 x 4 matrix
void Matrix_Root::set_Matrix_Root(const double& c1, const double& c2, const double& c3, const double& c4){
    n = 4;//four roots
    ptrD_root = new double[n];//dynamic root's array
    ptrD_root[0] = c1;//assign the value to root 1
    ptrD_root[1] = c2;//assign the value to root 2
    ptrD_root[2] = c3;//assign the value to root 3
    ptrD_root[3] = c4;//assign the value to root 4
}//end function

//change root's value of 4 x 4 matrix of complex number
void Matrix_Root::set_Matrix_Root(const Complex& c1, const Complex& c2, const Complex& c3, const Complex& c4){
    n = 4;//four roots
    ptrC_root = new Complex[n];//dynamic root's array
    ptrC_root[0] = c1;//assign the value to root 1
    ptrC_root[1] = c2;//assign the value to root 2
    ptrC_root[2] = c3;//assign the value to root 3
    ptrC_root[3] = c4;//assign the value to root 4
}//end function

//change the value of 5 x 5 matrix
void Matrix_Root::set_Matrix_Root(const double& c1, const double& c2, const double& c3, const double& c4, const double& c5){
    n = 5;//five roots
    ptrD_root = new double[n];//dynamic root's array
    ptrD_root[0] = c1;//assign the value to root 1
    ptrD_root[1] = c2;//assign the value to root 2
    ptrD_root[2] = c3;//assign the value to root 3
    ptrD_root[3] = c4;//assign the value to root 4
    ptrD_root[4] = c5;//assign the value to root 5
}//end funciton

//change root's value of 5 x 5 matrix of complex number
void Matrix_Root::set_Matrix_Root(const Complex& c1, const Complex& c2, const Complex& c3, const Complex& c4, const Complex& c5){
    n = 5;//five roots
    ptrC_root = new Complex[n];//dynamic root's array
    ptrC_root[0] = c1;//assign the value to root 1
    ptrC_root[1] = c2;//assign the value to root 2
    ptrC_root[2] = c3;//assign the value to root 3
    ptrC_root[3] = c4;//assign the value to root 4
    ptrC_root[4] = c5;//assign the value to root 5
}//end function

//change the value of 6 x 6 matrix
void Matrix_Root::set_Matrix_Root
(const double& c1, const double& c2, const double& c3, const double& c4, const double& c5, const double& c6)
{
    n = 6;//six roots
    ptrD_root = new double[n];//dynamic root's array
    ptrD_root[0] = c1;//assign the value to root 1
    ptrD_root[1] = c2;//assign the value to root 2
    ptrD_root[2] = c3;//assign the value to root 3
    ptrD_root[3] = c4;//assign the value to root 4
    ptrD_root[4] = c5;//assign the value to root 5
    ptrD_root[5] = c6;//assign the value to root 6
}//end function

//change root's value of 6 x 6 matrix of complex number
void Matrix_Root::set_Matrix_Root
(const Complex& c1, const Complex& c2, const Complex& c3, const Complex& c4, const Complex& c5, const Complex& c6)
{
    n = 6;//six roots
    ptrC_root = new Complex[n];//dynamic root's array
    ptrC_root[0] = c1;//assign the value to root 1
    ptrC_root[1] = c2;//assign the value to root 2
    ptrC_root[2] = c3;//assign the value to root 3
    ptrC_root[3] = c4;//assign the value to root 4
    ptrC_root[4] = c5;//assign the value to root 5
    ptrC_root[5] = c6;//assign the value to root 6
}//end function

//change the value of 7 x 7 matrix
void Matrix_Root::set_Matrix_Root
(const double& c1, const double& c2, const double& c3, const double& c4, const double& c5, const double& c6, const double& c7)
{
    n = 7;//seven roots
    ptrD_root = new double[n];//dynamic root's array
    ptrD_root[0] = c1;//assign the value to root 1
    ptrD_root[1] = c2;//assign the value to root 2
    ptrD_root[2] = c3;//assign the value to root 3
    ptrD_root[3] = c4;//assign the value to root 4
    ptrD_root[4] = c5;//assign the value to root 5
    ptrD_root[5] = c6;//assign the value to root 6
    ptrD_root[6] = c7;//assign the value to root 7
}//end fuction

//change root's value of 7 x 7 matrix of complex number
void Matrix_Root::set_Matrix_Root(const Complex& c1, const Complex& c2, const Complex& c3, const Complex& c4, const Complex& c5, const Complex& c6, const Complex& c7)
{
    n = 7;//seven roots
    ptrC_root = new Complex[n];//dynamic root's array
    ptrC_root[0] = c1;//assign the value to root 1
    ptrC_root[1] = c2;//assign the value to root 2
    ptrC_root[2] = c3;//assign the value to root 3
    ptrC_root[3] = c4;//assign the value to root 4
    ptrC_root[4] = c5;//assign the value to root 5
    ptrC_root[5] = c6;//assign the value to root 6
    ptrC_root[6] = c7;//assign the value to root 7
}//end function

//change the value of 8 x 8 matrix
void Matrix_Root::set_Matrix_Root
(const double& c1, const double& c2, const double& c3, const double& c4, const double& c5, const double& c6, const double& c7, const double& c8)
{
    n = 8;//eight roots
    ptrD_root = new double[n];//dynamic root's array
    ptrD_root[0] = c1;//assign the value to root 1
    ptrD_root[1] = c2;//assign the value to root 2
    ptrD_root[2] = c3;//assign the value to root 3
    ptrD_root[3] = c4;//assign the value to root 4
    ptrD_root[4] = c5;//assign the value to root 5
    ptrD_root[5] = c6;//assign the value to root 6
    ptrD_root[6] = c7;//assign the value to root 7
    ptrD_root[7] = c8;//assign the value to root 8
}//end functon

//change root's value of 8 x 8 matrix of complex number
void Matrix_Root::set_Matrix_Root
(const Complex& c1, const Complex& c2, const Complex& c3, const Complex& c4, const Complex& c5, const Complex& c6, const Complex& c7, const Complex& c8)
{
    n = 8;//eight roots
    ptrC_root = new Complex[n];//dynamic root's array
    ptrC_root[0] = c1;//assign the value to root 1
    ptrC_root[1] = c2;//assign the value to root 2
    ptrC_root[2] = c3;//assign the value to root 3
    ptrC_root[3] = c4;//assign the value to root 4
    ptrC_root[4] = c5;//assign the value to root 5
    ptrC_root[5] = c6;//assign the value to root 6
    ptrC_root[6] = c7;//assign the value to root 7
    ptrC_root[7] = c8;//assign the valeu to root 8
}//end function

//change the value of 9 x 9 matrix
void Matrix_Root::set_Matrix_Root
(const double& c1,const double& c2,const double& c3,const double& c4,const double& c5,const double& c6,const double& c7,const double& c8,const double& c9)
{
    n = 9;//nine roots
    ptrD_root = new double[n];//dynamic root's array
    ptrD_root[0] = c1;//assign the value to root 1
    ptrD_root[1] = c2;//assign the value to root 2
    ptrD_root[2] = c3;//assign the value to root 3
    ptrD_root[3] = c4;//assign the value to root 4
    ptrD_root[4] = c5;//assign the value to root 5
    ptrD_root[5] = c6;//assign the value to root 6
    ptrD_root[6] = c7;//assign the value to root 7
    ptrD_root[7] = c8;//assign the value to root 8
    ptrD_root[8] = c9;//assign the value to root 9
}//end function

//change root's value of 9 x 9 matrix of complex number
void Matrix_Root::set_Matrix_Root
(const Complex& c1,const Complex& c2,const Complex& c3,const Complex& c4,const Complex& c5,const Complex& c6,const Complex& c7,const Complex& c8,const Complex& c9)
{
    n = 9;//nine roots
    ptrC_root = new Complex[n];//dynamic root's array
    ptrC_root[0] = c1;//assign the value to root 1
    ptrC_root[1] = c2;//assign the value to root 2
    ptrC_root[2] = c3;//assign the value to root 3
    ptrC_root[3] = c4;//assign the value to root 4
    ptrC_root[4] = c5;//assign the value to root 5
    ptrC_root[5] = c6;//assign the value to root 6
    ptrC_root[6] = c7;//assign the value to root 7
    ptrC_root[7] = c8;//assign the valeu to root 8
    ptrC_root[8] = c9;//assign the value to root 9
}//end function

//change the value of 10 x 10 matrix
void Matrix_Root::set_Matrix_Root
(const double& c1, const double& c2, const double& c3, const double& c4, const double& c5, const double& c6, const double& c7, const double& c8, const double& c9, const double& c10)
{
    n = 10;//ten roots
    ptrD_root = new double[n];//dynamic root's array
    ptrD_root[0] = c1;//assign the value to root 1
    ptrD_root[1] = c2;//assign the value to root 2
    ptrD_root[2] = c3;//assign the value to root 3
    ptrD_root[3] = c4;//assign the value to root 4
    ptrD_root[4] = c5;//assign the value to root 5
    ptrD_root[5] = c6;//assign the value to root 6
    ptrD_root[6] = c7;//assign the value to root 7
    ptrD_root[7] = c8;//assign the value to root 8
    ptrD_root[8] = c9;//assign the value to root 9
    ptrD_root[9] = c10;//assign the value to root 10
}//end function

//change root's value of 10 x 10 matrix of complex number
void Matrix_Root::set_Matrix_Root
(const Complex& c1,const Complex& c2,const Complex& c3,const Complex& c4,const Complex& c5,const Complex& c6,const Complex& c7,const Complex& c8,const Complex& c9,const Complex& c10)
{
    n = 10;//ten roots
    ptrC_root = new Complex[n];//dynamic root's array
    ptrC_root[0] = c1;//assign the value to root 1
    ptrC_root[1] = c2;//assign the value to root 2
    ptrC_root[2] = c3;//assign the value to root 3
    ptrC_root[3] = c4;//assign the value to root 4
    ptrC_root[4] = c5;//assign the value to root 5
    ptrC_root[5] = c6;//assign the value to root 6
    ptrC_root[6] = c7;//assign the value to root 7
    ptrC_root[7] = c8;//assign the valeu to root 8
    ptrC_root[8] = c9;//assign the value to root 9
    ptrC_root[9] = c10;//assign the value to root 10
}//end function

ostream& operator<<(ostream& output,const Matrix_Root& root){
    if (root.ptrD_root != nullptr){
        output << "The roots are:" << endl;
        for (int i{0}; i < root.n; ++i){
            output << "X" << i+1  << " = "<< root.ptrD_root[i] << endl;
        }
    }
    else if (root.ptrC_root != nullptr){
        output << "The complex roots are:" << endl;
        for (int i{0}; i < root.n; ++i){
            output << "X" << i+1 << " = " << root.ptrC_root[i] << endl;
        }
    }
    else{
        throw exception();
    }
    return output;
}

Matrix_Root::~Matrix_Root(){
    delete []ptrC_root;//delete the pointer and its memory
    delete []ptrD_root;//delete the memory
}//destructor

/*

//global function to calculate the matrix
//function to calculate the 2 x 2 matrix of real number
Matrix_Root calcu_Matrix
(double& a11, double& a12, double& c1,
 double& a21, double& a22, double& c2)
{
    // each element of first line is devided by a11
    a12 /= a11;
    c1 /= a11;
    a11 /= a11;
    // first line times minus s21 plus second line
    a22 -= a12*(a21);
    c2 -= c1*(a21);
    a21 -= a11*(a21);
    // each element of second line is devided by a22
    c2 /= a22;
    a22 /= a22;
    // second line times ,inus a12 plus the first line
    c1 -= c2*(a12);
    a12 -= a22*(a12);
    Matrix_Root root;//create a object of Matrix_Root type
    root.set_Matrix_Root(c1, c2);//set the roots' value
    cout << "Roots are :" << endl;//print the roots
    cout << "X1: " << root.ptrD_root[0] << "\n" << "X2: " << root.ptrD_root[1] << endl;
    return root;//return roots to be used later
}//end function

//function to calculate the 2 x 2 matrix of complex number
Matrix_Root calcu_Matrix
(Complex& a11, Complex& a12, Complex& c1,
 Complex& a21, Complex& a22, Complex& c2)
{
    // each element of first line is devided by a11
    a12.div_Comp(a11);//a12 = a12/a11
    c1.div_Comp(a11);//c1 = c1/a11
    a11.div_Comp(a11);//a11 = a11/a11
    
    Complex A12{a12};//create a holder
    
    // first line times minus s21 plus second line
    a12.multip_Comp(a21);//a12*a21
    a22.subtr_Comp(a12);//a22 = a22-a12*a21
    c1.multip_Comp(a21);//c1*a21
    c2.subtr_Comp(c1);//c2 = c2-c1*a21
    a11.multip_Comp(a21);//a11*a21
    a21.subtr_Comp(a11);//a21 = a21-a11*a21
    
    // each element of second line is devided by a22
    c2.div_Comp(a22);//c2 = c2/a22
    a22.div_Comp(a22);//a22 = a22/a22
    
    Complex C2{c2};//create c2's replica to be used later
    
    // second line times minus a12 plus the first line
    C2.multip_Comp(A12);//c2*a12
    c1.subtr_Comp(C2);//c1 = c1-c2*a12
    a22.multip_Comp(A12);//a22*a12
    a12.subtr_Comp(a22);//a12 = a12-a22*a12;
    
    // assign c1 and c2 to roots
    Matrix_Root root;//call constructor creating an object
    root.set_Matrix_Root(c1, c2);//assign the values to roots
    
    cout << "the comlex roots are as follow: " << endl;
    //call function to print the roots
    cout << "X1: ";
    root.ptrC_root[0].print_Comp();
    cout << "X2: ";
    root.ptrC_root[1].print_Comp();
    
    return root;//return the object for further operational purpose
}//end fucntion

//function calculating matrix 3 x 3 matrix of real number
Matrix_Root calcu_Matrix
(double& a11, double& a12, double& a13, double& c1,//first row
 double& a21, double& a22, double& a23, double& c2,//second row
 double& a31, double& a32, double& a33, double& c3)//third row
{
    // each element in the first line is divided by a11
    c1 /= a11;
    a13 /= a11;
    a12 /= a11;
    a11 /= a11;
    // elements in the second line add the product of the first line elements and minus a21
    c2 -= c1*(a21);
    a23 -= a13*(a21);
    a22 -= a12*(a21);
    a21 -= a11*(a21);
    // elements in third line add the product pf first line elements and minus a31
    c3 -= c1*(a31);
    a33 -= a13*(a31);
    a32 -= a12*(a31);
    a31 -= a11*(a31);
    // second line elements devided by a22
    c2 /= a22;
    a23 /= a22;
    a22 /= a22;
    // elements in third line add the product of second line's elements and minus a32
    c3 -= c2*(a32);
    a33 -= a23*(a32);
    a32 -= a22*(a32);
    // third line's elements divied by a33
    c3 /= a33;
    a33 /= a33;
    //elements of second lines add the product of third line's elements and minus a23
    c2 -= c3*(a23);
    a23 -= a33*(a23);
    //elements of first lines add the product of third line's elements and minus a13
    c1 -= c3*(a13);
    a13 -= a33*(a13);
    //first line's elements add the product of second lines elements and minus a12
    c1 -= c2*(a12);
    a12 -= a22*(a12);
    
    Matrix_Root root;//create an object
    root.set_Matrix_Root(c1, c2, c3);//set the roots' value
    cout << "Roots are :" << endl;//print the roots
    cout << "X1: " << root.ptrD_root[0] << "\n" << "X2: " << root.ptrD_root[1]
    << "\n" << "X3: " << root.ptrD_root[2] << endl;
    return root;//return roots to be used later
}//end function

//function calculating 3 x 3 matrix of complex number
Matrix_Root calcu_Matrix
(Complex& a11, Complex& a12, Complex& a13, Complex& c1,//first row
 Complex& a21, Complex& a22, Complex& a23, Complex& c2,//second row
 Complex& a31, Complex& a32, Complex& a33, Complex& c3)//third row
{
    // each element in the first line is divided by a11
    c1.div_Comp(a11);//c1 /= a11;
    a13.div_Comp(a11);//a13 /= a11;
    a12.div_Comp(a11);//a12 /= a11;
    a11.div_Comp(a11);//a11 /= a11;
    
    // elements in the second line add the product of the first line elements and minus a21
    Complex* ptr{new Complex(a21)};//create a dynamic value of a21 pointed by ptr
    (*ptr).multip_Comp(c1);//c1*a21
    c2.subtr_Comp(*ptr);//c2 -= c1*(a21);
    (*ptr) = a21;//reset the initial value
    (*ptr).multip_Comp(a13);//a13*a21
    a23.subtr_Comp(*ptr);//a23 -=a13*(a21);
    (*ptr) = a21;//reset the inital value
    (*ptr).multip_Comp(a12);//a12*a21
    a22.subtr_Comp(*ptr);//a22 -= a12*(a21);
    (*ptr) = a21;//reset the initial value
    (*ptr).multip_Comp(a11);//a11*a21
    a21.subtr_Comp(*ptr);//a21 -= a11*(a21);
    delete ptr;//delete the memory
    
    // elements in third line add the product pf first line elements and minus a31
    ptr =  new Complex(a31);//create a dynamic value of a31 pointed by ptr
    (*ptr).multip_Comp(c1);//c1*a31
    c3.subtr_Comp(*ptr);//c3 -= c1*(a31);
    (*ptr) = a31;//reset the initial value
    (*ptr).multip_Comp(a13);//a13*a31
    a33.subtr_Comp(*ptr);//a33 -= a13*(a31);
    (*ptr) = a31;//reset the initial value
    (*ptr).multip_Comp(a12);//a12*a31
    a32.subtr_Comp(*ptr);//a32 -= a12*(a31);
    (*ptr) = a31;//reset the initial value
    (*ptr).multip_Comp(a11);//a11*a31
    a31.subtr_Comp(*ptr);//a31 -= a11*(a31);
    delete ptr;//delete the memory
    
    // second line elements devided by a22
    c2.div_Comp(a22);// c2 /= a22;
    a23.div_Comp(a22);// a23 /= a22;
    a22.div_Comp(a22);// a22 /= a22;
    
    // elements in third line add the product of second line's elements and minus a32
    ptr = new Complex(a32);//create a dynamic value of a32 pointed by ptr
    (*ptr).multip_Comp(c2);//c2*a32
    c3.subtr_Comp(*ptr);//c3 -= c2*(a32);
    (*ptr) = a32;//reset the initial value
    (*ptr).multip_Comp(a23);//a23*a32
    a33.subtr_Comp(*ptr);//a33 -= a23*(a32);
    (*ptr) = a32;//reset the initial value of a32
    (*ptr).multip_Comp(a22);//a22*a32
    a32.subtr_Comp(*ptr);//a32 -= a22*(a32);
    delete ptr;//delete the memory
    
    // third line's elements divied by a33
    c3.div_Comp(a33);//c3 /= a33;
    a33.div_Comp(a33);//a33 /= a33;
    
    //elements of second lines add the product of third line's elements and minus a23
    ptr = new Complex(a23);//create a dynamic value of a23 pointed by ptr
    (*ptr).multip_Comp(c3);//c3*a23
    c2.subtr_Comp(*ptr);//c2 -= c3*(a23);
    (*ptr) = a23;//reset the initial value
    (*ptr).multip_Comp(a33);//a33*a23
    a23.subtr_Comp(*ptr);//a23 -= a33*(a23);
    delete ptr;//delete the memory
    
    //elements of first lines add the product of third line's elements and minus a13
    ptr = new Complex(a13);//create a dynamic value of a13 pointed by ptr
    (*ptr).multip_Comp(c3);//c3*a13
    c1.subtr_Comp(*ptr);//c1 -= c3*(a13)
    (*ptr) = a13;//reset the initial value
    (*ptr).multip_Comp(a33);//a33*a13
    a13.subtr_Comp(*ptr);//a13 -= a33*(a13)
    delete ptr;//delete the memory
    
    //first line's elements add the product of second lines elements and minus a12
    ptr = new Complex(a12);//create a dynamic value of a12 pointed by ptr
    (*ptr).multip_Comp(c2);//c2*a12
    c1.subtr_Comp(*ptr);//c1 -= c2*(a12);
    (*ptr) = a12;// reset value
    (*ptr).multip_Comp(a22);//a22*a12
    a12.subtr_Comp(*ptr);//a12 -= a22*(a12);
    delete ptr;//delete the memory
    
    Matrix_Root root;//create an object
    root.set_Matrix_Root(c1, c2, c3);//set the roots
    cout << "the complex roots are as follow: " << endl;
    //call function to print the roots
    cout << "X1: ";
    root.ptrC_root[0].print_Comp();
    cout << "X2: ";
    root.ptrC_root[1].print_Comp();
    cout << "X3: ";
    root.ptrC_root[2].print_Comp();
    
    return root;//return the value to be used later
}//end function

//function calculating 4 x 4 matrix
Matrix_Root calcu_Matrix
(double& a11, double& a12, double& a13, double& a14, double& c1,//first row
 double& a21, double& a22, double& a23, double& a24, double& c2,//second row
 double& a31, double& a32, double& a33, double& a34, double& c3,//third row
 double& a41, double& a42, double& a43, double& a44, double& c4)//fourth row
{
    //each element of the first line divided by a11
    c1 /= a11;//c1 = c1/a11
    a14 /= a11;//a14 = a14/a11
    a13 /= a11;//a13 = a13/a11
    a12 /= a11;//a12 = a12/a11
    a11 /= a11;//a11 = a11/a11
    //each elements of line 2 plus the products of coresponding of line 1 and minus a21
    c2 -= c1*(a21);//c2 = c2+c1*(-a21)
    a24 -= a14*(a21);//a24 = a24 + a14*(-a21)
    a23 -= a13*(a21);//a23 = a23 + a13*(-a21)
    a22 -= a12*(a21);//a22 = a22 + a12*(-a21)
    a21 -= a11*(a21);//a21 = a21 + a11*(-a21)
    //each elements of line 3 plus the products of coresponding of line 1 and minus a31
    c3 -= c1*a31;//c3 = c3 + c1*(-a31)
    a34 -= a14*a31;//a34 = a34 + a14*(-a31)
    a33 -= a13*a31;//a33 = a33 + a13*(-a31)
    a32 -= a12*a31;//a32 = a32 + a12*(-a31)
    a31 -= a11*a31;//a31 = a31 + a11*(-a31)
    //each elements of line 4 plus the products of coresponding of line 1 and minus a41
    c4 -= c1*a41;//c4 = c4 + c1*(-a41)
    a44 -= a14*a41;//a44 = a44 + a14*(-a41)
    a43 -= a13*a41;//a43 = a43 + a13*(-a41)
    a42 -= a12*a41;//a42 = a42 + a12*(-a41)
    a41 -= a11*a41;//a41 = a41 + a11*(-a41)
    //each element of line 2 divided by a22 except a21 which is 0
    c2 /= a22;//c2 = c2/a22
    a24 /= a22;//a24 = a24/a22
    a23 /= a22;//a23 = a23/a22
    a22 /= a22;//a22 = a22/a22
    //each element of line 3 plus the products of line 2 and minus a32 except a31 which is 0
    c3 -= c2*a32;//c3 = c3 + c2*(-a32)
    a34 -= a24*a32;//a34 = a34 + a24*(-a32)
    a33 -= a23*a32;//a33 = a33 + a23*(-a32)
    a32 -= a22*a32;// a32 = a32 + a22*(-a32)
    //each element of line 4 plus the products of line 2 and minus a42 except a41 which is 0
    c4 -= c2*a42;//c4 = c4 + c2*(-a42)
    a44 -= a24*a42;//a44 = a44 + a24*(-a42)
    a43 -= a23*a42;//a43 = a43 + a23*(-a42)
    a42 -= a22*a42;//a42 = a42 + a22*(-a42)
    //each element of line 3 divided by a33 except a31 and a32 which are 0
    c3 /= a33;//c3 = c3/a33
    a34 /= a33;//a34 = a34/a33
    a33 /= a33;//a33= a33/a33
    //each elememt od line 4 plus the products of coresponding line 3 and minus a43 except a41 and a42
    c4 -= c3*a43;//c4 = c4 + c3*(-a43)
    a44 -= a34*a43;//a44 = a44 + a34*(-a43)
    a43 -= a33*a43;//a43 = a43 + a33*(-a43)
    //line 4 divided by a44 except a43, a42 and a41 which are 0
    c4 /= a44;//c4 = c4/a44
    a44 /= a44;//a44 = a44/a44
    //line 3 plus the products of line 4 and minus a34
    c3 -= c4*a34;//c3 = c3 + c4*(-a34)
    a34 -= a44*a34;//a34 = a34 + a44*(-a34)
    //line 2 plus the products of line 4 and minus a24
    c2 -= c4*a24;//c2 = c2 + c4*(-a24)
    a24 -= a44*a24;//a24 = a24 + a44*(-a24)
    //line 2 plus the products of line 3 and minus a23
    c2 -= c3*a23;//c2 = c2 + c3*(-a23)
    a23 -= a33*a23;//a23 = a23 + a33*(-a23)
    //line 1 plus the rpoducts of line 4 and minus a14
    c1 -= c4*a14;//c1 = c1 + c4*(-a14)
    a14 -= a44*a14;//a14 = a14 + a44*(-a14)
    //line 1 plus the products of line 3 and minus a13
    c1 -= c3*a13;//c1 = c1 + c3*(-a13)
    a13 -= a33*a13;//a13 = a13 + a33*(-a13)
    //line 1 plus the products of line 2 and minus a12
    c1 -= c2*a12;// c1 = c1 + c2*(-a12)
    a12 -= a22*a12;//a12 = a12 + a22*(-a12)
    
    Matrix_Root root;//create a root object
    root.set_Matrix_Root(c1, c2, c3, c4);//set root's value
    cout << "Roots are : " << endl;//print the roots
    cout << "X1 = " << root.ptrD_root[0] << endl;
    cout << "X2 = " << root.ptrD_root[1] << endl;
    cout << "X3 = " << root.ptrD_root[2] << endl;
    cout << "X4 = " << root.ptrD_root[3] << endl;
    
    return root;//return the object to be uesed later
}//end function


//function calculating 4 x 4 matrix of complex type
Matrix_Root calcu_Matrix
(Complex& a11, Complex& a12, Complex& a13, Complex& a14, Complex& c1,//first row
 Complex& a21, Complex& a22, Complex& a23, Complex& a24, Complex& c2,//second row
 Complex& a31, Complex& a32, Complex& a33, Complex& a34, Complex& c3,//third row
 Complex& a41, Complex& a42, Complex& a43, Complex& a44, Complex& c4)//fourth row
{
    //each element of the first line divided by a11
    c1.div_Comp(a11);//c1 = c1/a11
    a14.div_Comp(a11);//a14 = a14/a11
    a13.div_Comp(a11);//a13 = a13/a11
    a12.div_Comp(a11);//a12 = a12/a11
    a11.div_Comp(a11);//a11 = a11/a11
    
    //each elements of line 2 plus the products of coresponding of line 1 and minus a21
    Complex* ptr{new Complex};//create a pointer pointing to a dynamic memory
    *ptr = a21;//assign value to the memory
    (*ptr).multip_Comp(c1);//c1*a21
    c2.subtr_Comp(*ptr);//c2 = c2+c1*(-a21)
    *ptr = a21;//reset the value
    (*ptr).multip_Comp(a14);//a14*a21
    a24.subtr_Comp(*ptr);//a24 = a24 + a14*(-a21)
    *ptr = a21;//reset
    (*ptr).multip_Comp(a13);//a13*a21
    a23.subtr_Comp(*ptr);//a23 = a23 + a13*(-a21)
    *ptr = a21;//reset
    (*ptr).multip_Comp(a12);//a12*a21
    a22.subtr_Comp(*ptr);//a22 = a22 + a12*(-a21)
    *ptr = a21;//reset
    (*ptr).multip_Comp(a11);//a11*a21
    a21.subtr_Comp(*ptr);//a21 = a21 + a11*(-a21)
    
    //each elements of line 3 plus the products of coresponding of line 1 and minus a31
    *ptr = a31;//assign new value to memory
    (*ptr).multip_Comp(c1);//c1*a31
    c3.subtr_Comp(*ptr);//c3 = c3 + c1*(-a31)
    *ptr = a31;//reset
    (*ptr).multip_Comp(a14);//a14*a31
    a34.subtr_Comp(*ptr);//a34 = a34 + a14*(-a31)
    *ptr = a31;//reset
    (*ptr).multip_Comp(a13);//a13*a31
    a33.subtr_Comp(*ptr);//a33 = a33 + a13*(-a31)
    *ptr = a31;//reset
    (*ptr).multip_Comp(a12);//a12*a31
    a32.subtr_Comp(*ptr);//a32 = a32 + a12*(-a31)
    *ptr = a31;//reset
    (*ptr).multip_Comp(a11);//a11*a31
    a31.subtr_Comp(*ptr);//a31 = a31 + a11*(-a31)
    
    //each elements of line 4 plus the products of coresponding of line 1 and minus a41
    *ptr = a41;//assign new value to the memory
    (*ptr).multip_Comp(c1);//c1*a41
    c4.subtr_Comp(*ptr);//c4 = c4 + c1*(-a41)
    *ptr = a41;//reset
    (*ptr).multip_Comp(a14);//a14*a41
    a44.subtr_Comp(*ptr);//a44 = a44 + a14*(-a41)
    *ptr = a41;//reset
    (*ptr).multip_Comp(a13);//a13*a41
    a43.subtr_Comp(*ptr);//a43 = a43 + a13*(-a41)
    *ptr = a41;//reset
    (*ptr).multip_Comp(a12);//a12*a41
    a42.subtr_Comp(*ptr);//a42 = a42 + a12*(-a41)
    *ptr = a41;//reset
    (*ptr).multip_Comp(a11);//a11*a41
    a41.subtr_Comp(*ptr);//a41 = a41 + a11*(-a41)
    
    //each element of line 2 divided by a22 except a21 which is 0
    c2.div_Comp(a22);//c2 = c2/a22
    a24.div_Comp(a22);//a24 = a24/a22
    a23.div_Comp(a22);//a23 = a23/a22
    a22.div_Comp(a22);//a22 = a22/a22
    
    //each element of line 3 plus the products of line 2 and minus a32 except a31 which is 0
    *ptr = a32;//assign new value to the memory
    (*ptr).multip_Comp(c2);//c2*a32
    c3.subtr_Comp(*ptr);//c3 = c3 + c2*(-a32)
    *ptr = a32;//reset
    (*ptr).multip_Comp(a24);//a24*a32
    a34.subtr_Comp(*ptr);//a34 = a34 + a24*(-a32)
    *ptr = a32;//reset
    (*ptr).multip_Comp(a23);//a23*a32
    a33.subtr_Comp(*ptr);//a33 = a33 + a23*(-a32)
    *ptr = a32;//reset
    (*ptr).multip_Comp(a22);//a22*a32
    a32.subtr_Comp(*ptr);// a32 = a32 + a22*(-a32)
    
    //each element of line 4 plus the products of line 2 and minus a42 except a41 which is 0
    *ptr = a42;//assign new value to the memory
    (*ptr).multip_Comp(c2);//c2*a42
    c4.subtr_Comp(*ptr);//c4 = c4 + c2*(-a42)
    *ptr = a42;//reset
    (*ptr).multip_Comp(a24);//a24*a42
    a44.subtr_Comp(*ptr);//a44 = a44 + a24*(-a42)
    *ptr = a42;//reset
    (*ptr).multip_Comp(a23);//a23*a42
    a43.subtr_Comp(*ptr);//a43 = a43 + a23*(-a42)
    *ptr = a42;//reset
    (*ptr).multip_Comp(a22);//a22*a42
    a42.subtr_Comp(*ptr);//a42 = a42 + a22*(-a42)
    
    //each element of line 3 divided by a33 except a31 and a32 which are 0
    c3.div_Comp(a33);//c3 = c3/a33
    a34.div_Comp(a33);//a34 = a34/a33
    a33.div_Comp(a33);//a33= a33/a33
    
    //each elememt od line 4 plus the products of coresponding line 3 and minus a43 except a41 and a42
    *ptr = a43;//assign new value to the memory
    (*ptr).multip_Comp(c3);//c3*a43
    c4.subtr_Comp(*ptr);//c4 = c4 + c3*(-a43)
    *ptr = a43;//reset
    (*ptr).multip_Comp(a34);//a34*a43
    a44.subtr_Comp(*ptr);//a44 = a44 + a34*(-a43)
    *ptr = a43;//reset
    (*ptr).multip_Comp(a33);//a33*a43
    a43.subtr_Comp(*ptr);//a43 = a43 + a33*(-a43)
    
    //line 4 divided by a44 except a43, a42 and a41 which are 0
    c4.div_Comp(a44);//c4 = c4/a44
    a44.div_Comp(a44);//a44 = a44/a44
    
    //line 3 plus the products of line 4 and minus a34
    *ptr = a34;//assign new value to the memory
    (*ptr).multip_Comp(c4);//c4*a34
    c3.subtr_Comp(*ptr);//c3 = c3 + c4*(-a34)
    *ptr = a34;//reset
    (*ptr).multip_Comp(a44);//a44*a34
    a34.subtr_Comp(*ptr);//a34 = a34 + a44*(-a34)
    
    //line 2 plus the products of line 4 and minus a24
    *ptr = a24;//assign new value to the memory
    (*ptr).multip_Comp(c4);//c4*a24
    c2.subtr_Comp(*ptr);//c2 = c2 + c4*(-a24)
    *ptr = a24;//reset
    (*ptr).multip_Comp(a44);//a44*a24
    a24.subtr_Comp(*ptr);//a24 = a24 + a44*(-a24)
    
    //line 2 plus the products of line 3 and minus a23
    *ptr = a23;//assign new value to the memory
    (*ptr).multip_Comp(c3);//c3*a23
    c2.subtr_Comp(*ptr);//c2 = c2 + c3*(-a23)
    *ptr = a23;//reset
    (*ptr).multip_Comp(a33);//a33*a23
    a23.subtr_Comp(*ptr);//a23 = a23 + a33*(-a23)
    
    //line 1 plus the rpoducts of line 4 and minus a14
    *ptr = a14;//assign new value to the memory
    (*ptr).multip_Comp(c4);//c4*a14
    c1.subtr_Comp(*ptr);//c1 = c1 + c4*(-a14)
    *ptr = a14;//reset
    (*ptr).multip_Comp(a44);//a44*a14
    a14.subtr_Comp(*ptr);//a14 = a14 + a44*(-a14)
    
    //line 1 plus the products of line 3 and minus a13
    *ptr = a13;//assign new value to the memory
    (*ptr).multip_Comp(c3);//c3*a13
    c1.subtr_Comp(*ptr);//c1 = c1 + c3*(-a13)
    *ptr = a13;//reset
    (*ptr).multip_Comp(a33);//a33*a13
    a13.subtr_Comp(*ptr);//a13 = a13 + a33*(-a13)
    
    //line 1 plus the products of line 2 and minus a12
    *ptr = a12;//assign new value to the memory
    (*ptr).multip_Comp(c2);//c2*a12
    c1.subtr_Comp(*ptr);// c1 = c1 + c2*(-a12)
    *ptr = a12;//reset
    (*ptr).multip_Comp(a22);//a22*a12
    a12.subtr_Comp(*ptr);//a12 = a12 + a22*(-a12)
    
    delete ptr;//delete the memory
    
    Matrix_Root root;//create a root object
    root.set_Matrix_Root(c1, c2, c3, c4);//assign the value to roots
    cout << "The complex roots are " << endl;
    cout << "X1= " << endl;
    root.ptrC_root[0].print_Comp();//print
    cout << "X2= " << endl;
    root.ptrC_root[1].print_Comp();//print
    cout << "X3= " << endl;
    root.ptrC_root[2].print_Comp();//print
    cout << "X4= " << endl;
    root.ptrC_root[3].print_Comp();//print
    
    return root;//return root to be used later
}//end function
*/
