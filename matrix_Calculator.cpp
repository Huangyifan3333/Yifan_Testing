//
//  matrix_Calculator.cpp
//  Yifan's App
//
//  Created by Yifan Huang on 2019-01-10.
//  Copyright © 2019 Yifan Huang. All rights reserved.
//  implementation of the function of matrix_Calculator

#include "Matrix_Root.h"
//#include "Complex.h"
#include "matrix_Calculator.h"
#include <iostream>
using namespace std;


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
    
    /* wrong algorithem
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
     */
}//end fucntion

//function calculating matrix 3x 3 matrix of real number
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
    /*wrong algorithem
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
    */
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
    cout << root;
    /*
    cout << "Roots are : " << endl;//print the roots
    cout << "X1 = " << root.ptrD_root[0] << endl;
    cout << "X2 = " << root.ptrD_root[1] << endl;
    cout << "X3 = " << root.ptrD_root[2] << endl;
    cout << "X4 = " << root.ptrD_root[3] << endl;
    */
    return root;//return the object to be uesed later
}//end function


//function calculating 4 x 4 matrix of complex type
Matrix_Root calcu_Matrix
(Complex& a11, Complex& a12, Complex& a13, Complex& a14, Complex& c1,//first row
 Complex& a21, Complex& a22, Complex& a23, Complex& a24, Complex& c2,//second row
 Complex& a31, Complex& a32, Complex& a33, Complex& a34, Complex& c3,//third row
 Complex& a41, Complex& a42, Complex& a43, Complex& a44, Complex& c4)//fourth row
{
    /*
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
    */
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
    root.set_Matrix_Root(c1, c2, c3, c4);//assign the value to roots
    cout << root;
    /*
    cout << "The complex roots are " << endl;
    cout << "X1= " << endl;
    root.ptrC_root[0].print_Comp();//print
    cout << "X2= " << endl;
    root.ptrC_root[1].print_Comp();//print
    cout << "X3= " << endl;
    root.ptrC_root[2].print_Comp();//print
    cout << "X4= " << endl;
    root.ptrC_root[3].print_Comp();//print
    */
    return root;//return root to be used later
}//end function

Matrix_Root calcu_Matrix//decalre friend of the function calculating 5 x 5 matrix
(double& a11, double& a12, double& a13, double& a14, double& a15, double& c1,//first row
 double& a21, double& a22, double& a23, double& a24, double& a25, double& c2,//second row
 double& a31, double& a32, double& a33, double& a34, double& a35, double& c3,//third row
 double& a41, double& a42, double& a43, double& a44, double& a45, double& c4,//fourth row
 double& a51, double& a52, double& a53, double& a54, double& a55, double& c5)//fifth row
{
    //the first line divided by a11
    c1 /= a11;//c1=c1/a11
    a15 /= a11;//a15 = a15/a11
    a14 /= a11;//a14=a14/a11
    a13 /= a11;//a13 =a13/a11
    a12 /= a11;//a12 = a12/a11
    a11 /= a11;//a11 = 1
    //line2 = line2 +line1*(-a21)
    c2 -= c1*a21;//c2=c2+c1*(-a21)
    a25 -= a15*a21;//a25=a25+a15*(-a21)
    a24 -= a14*a21;//a24=a24+a14*(-a21)
    a23 -= a13*a21;//a23=a23+a13*(-a21)
    a22 -= a12*a21;//a22=a22+a12*(-a21)
    a21 -= a11*a21;//a21=a21+a11*(-a21),a21=0
    //line3 = line3 + line1*(-a31)
    c3 -= c1*a31;//c3=c3+c1*(-a31)
    a35 -= a15*a31;//a35=a35+a15*(-a31)
    a34 -= a14*a31;//a34=a34+a14*(-a31)
    a33 -= a13*a31;//a33=a33+a13*(-a31)
    a32 -= a12*a31;//a32=a32+a12*(-a31)
    a31 -= a11*a31;//a31=a31+a11*(-a31),s31=0
    //line4 = line4 + line1*(-a41)
    c4 -= c1*a41;//c4 = c4 + c1*(-a41)
    a45 -= a15*a41;//a45=a45+a14*(-a41)
    a44 -= a14*a41;//a44=a44+a14*(-a41)
    a43 -= a13*a41;//a43=a43+a13*(-a41)
    a42 -= a12*a41;//a42=a42+a12*(-a41)
    a41 -= a11*a41;//a41=a41+a11*(-a41),a41=0
    //line 5 = line5 + line1*(-a51)
    c5 -= c1*a51;//c5=c5+c1*(-a51)
    a55 -= a15*a51;//a55 = a55+a15*(-a51)
    a54 -= a14*a51;//a54 = a54+a14*(-a51)
    a53 -= a13*a51;//a53 = a53+a13*(-a51)
    a52 -= a12*a51;//a52 = a52+a12*(-a51)
    a51 -= a11*a51;//a51 = a51+a11*(-a51),a51=0
    //line2(a-c2) = line2/a22
    c2 /= a22;//c2=c2/a22
    a25 /= a22;//a25=a25/a22
    a24 /= a22;//a24=a24/a22
    a23 /= a22;//a23=a23/a22
    a22 /= a22;//a22=a22/a22,a22=1
    //line3(a32-c3)=line3+line2(a22-c2)*(-a32)
    c3 -= c2*a32;//c3=c3+c2*(-a32)
    a35 -= a25*a32;//a35=a35+a25*(-a32)
    a34 -= a24*a32;//a34=a34+a24*(-a32)
    a33 -= a23*a32;//a33=a33+a23*(-a32)
    a32 -= a22*a32;//a32=a32+a22*(-a32),a32=0
    //line4(a42-c4)=line4 + line2(a22-c2)*(-a42)
    c4 -= c2*a42;//c4=c4+c2*(-a42)
    a45 -= a25*a42;//a45=a45+a25*(-a42)
    a44 -= a24*a42;//a44=a44+a24*(-a42)
    a43 -= a23*a42;//a43=a43+a238(-a42)
    a42 -= a22*a42;//a42=a42+a228(-a42),a42=0
    //line5(a52-c5) = line5 + line2(a22-c2)*(-a52)
    c5 -= c2*a52;//c5=c5+c28(-a52)
    a55 -= a25*a52;//a55=a55+a25*(-a52)
    a54 -= a24*a52;//a54=a54+a24*(-a52)
    a53 -= a23*a52;//a53=a53+a23*(-a52)
    a52 -= a22*a52;//a52=a52+a22*(-a52),a52=0
    //line3(a33-c3)=line3/a33
    c3 /= a33;//c3=c3/a33
    a35 /= a33;//a35=a35/a33
    a34 /= a33;//a34=a34/a33
    a33 /= a33;//a33=a33/a33,a33=1
    //line4(a43-c4)=line4+line3(a33-c3)*(-a43)
    c4 -= c3*a43;//c4=c4+c3*(-a43)
    a45 -= a35*a43;//a45=a45+a35*(-a43)
    a44 -= a34*a43;//a44=a44+a34*(-a43)
    a43 -= a33*a43;//a43=a43+a338(-a43),a43=0
    //line5(a53-c5)=line5+line3(a33-c3)*(-a53)
    c5 -= c3*a53;//c5=c5+c38(-a53)
    a55 -= a35*a53;//a55=a55+a35*(-a53)
    a54 -= a34*a53;//a54=a54+a34*(-a53)
    a53 -= a33*a53;//a53=a53+a33*(-a53),a53=0
    //line4(a44-c4)=line4/a44
    c4 /= a44;//c4=c4/a44
    a45 /= a44;//a45=a45/a44
    a44 /= a44;//a44=a44/a44, a44=1
    //line5(a54-c5)=line5+line4(a44-c4)*(-a54)
    c5 -= c4*a54;//c5=c5+c4*(-a54)
    a55 -= a45*a54;//a55=a55+a45*(-a54)
    a54 -= a44*a54;//a54=a54+a44*(-a54),a54=0
    //line5(a55-c5)=line5/a55
    c5 /=a55;//c5=c5/a55
    a55 /=a55;//a55=a55/a55,a55=1
    //line4(a45-c4)=line4+line5(a55-c5)*(-a45)
    c4 -= c5*a45;//c4=c4+c5*(-a45)
    a45 -= a55*a45;//a45=a45+a55*(-a45),a45=0
    //line3(a35-c3)=line3+line5(a55-c5)*(-a35)
    c3 -= c5*a35;//c3=c3+c5*(-a35)
    a35 -= a55*a35;//a35=a35+a55*(-a35),a35=0
    //line2(a25-c2)=line2+line5(a55-c5)*(-a25)
    c2 -= c5*a25;//c2=c2+c5*(-a25)
    a25 -= a55*a25;//a25=a25+a55*(-a25),a25=0
    //line1(a15-c1)=line1+line5(a55-c5)*(-a15)
    c1 -= c5*a15;//c1=c1+c5*(-a15)
    a15 -= a55*a15;//a15=a15+a55*(-a15),a15=0
    //line3(a34,c3)=line3+line4(a44,c4)*(-a34)
    c3 -= c4*a34;//c3=c3+c4*(-a34)
    a34 -= a44*a34;//a34=a34+a44*(-a34),a34=0
    //line2(a24,c2)=line2+line4(a44,c4)*(-a24)
    c2 -= c4*a24;//c2=c2+c4*(-a24)
    a24 -= a44*a24;//a24=a24+a44*(-a24),a24=0
    //line1(a14,c1)=line1+line4(a44,c4)*(-a14)
    c1 -= c4*a14;//c1=c1+c4*(-a14)
    a14 -= a44*a14;//a14=a14+a44*(-a14),a14=0
    //line2(a23,c2)=line2+line3(a33,c3)*(-a23)
    c2 -= c3*a23;//c2=c2+c3*(-a23)
    a23 -= a33*a23;//a23=a23+a33*(-a23),a23=0
    //line1(a13,c1)=line1+line3(a33,c3)*(-a13)
    c1 -= c3*a13;//c1=c1+c3*(-a13)
    a13 -= a33*a13;//a13=a13+a33*(-a13),a13=0
    //line1(a12,c1)=line1+line2(a22,c2)*(-a12)
    c1 -= c2*a12;//c1=c1+c2*(-a12)
    a12 -= a22*a12;//a12=a12+a22*(-a12),a12=0

    Matrix_Root root;
    root.set_Matrix_Root(c1,c2,c3,c4,c5);
    cout << root;
    return root;
}//end function

Matrix_Root calcu_Matrix//declare friend of the function calculating 5 x 5 matrix
(Complex& a11, Complex& a12, Complex& a13, Complex& a14, Complex& a15, Complex& c1,//first row
 Complex& a21, Complex& a22, Complex& a23, Complex& a24, Complex& a25, Complex& c2,//second row
 Complex& a31, Complex& a32, Complex& a33, Complex& a34, Complex& a35, Complex& c3,//third row
 Complex& a41, Complex& a42, Complex& a43, Complex& a44, Complex& a45, Complex& c4,//fourth row
 Complex& a51, Complex& a52, Complex& a53, Complex& a54, Complex& a55, Complex& c5)//fifth row
{
    //the first line divided by a11
    c1 /= a11;//c1=c1/a11
    a15 /= a11;//a15 = a15/a11
    a14 /= a11;//a14=a14/a11
    a13 /= a11;//a13 =a13/a11
    a12 /= a11;//a12 = a12/a11
    a11 /= a11;//a11 = 1
    //line2 = line2 +line1*(-a21)
    c2 -= c1*a21;//c2=c2+c1*(-a21)
    a25 -= a15*a21;//a25=a25+a15*(-a21)
    a24 -= a14*a21;//a24=a24+a14*(-a21)
    a23 -= a13*a21;//a23=a23+a13*(-a21)
    a22 -= a12*a21;//a22=a22+a12*(-a21)
    a21 -= a11*a21;//a21=a21+a11*(-a21),a21=0
    //line3 = line3 + line1*(-a31)
    c3 -= c1*a31;//c3=c3+c1*(-a31)
    a35 -= a15*a31;//a35=a35+a15*(-a31)
    a34 -= a14*a31;//a34=a34+a14*(-a31)
    a33 -= a13*a31;//a33=a33+a13*(-a31)
    a32 -= a12*a31;//a32=a32+a12*(-a31)
    a31 -= a11*a31;//a31=a31+a11*(-a31),s31=0
    //line4 = line4 + line1*(-a41)
    c4 -= c1*a41;//c4 = c4 + c1*(-a41)
    a45 -= a15*a41;//a45=a45+a14*(-a41)
    a44 -= a14*a41;//a44=a44+a14*(-a41)
    a43 -= a13*a41;//a43=a43+a13*(-a41)
    a42 -= a12*a41;//a42=a42+a12*(-a41)
    a41 -= a11*a41;//a41=a41+a11*(-a41),a41=0
    //line 5 = line5 + line1*(-a51)
    c5 -= c1*a51;//c5=c5+c1*(-a51)
    a55 -= a15*a51;//a55 = a55+a15*(-a51)
    a54 -= a14*a51;//a54 = a54+a14*(-a51)
    a53 -= a13*a51;//a53 = a53+a13*(-a51)
    a52 -= a12*a51;//a52 = a52+a12*(-a51)
    a51 -= a11*a51;//a51 = a51+a11*(-a51),a51=0
    //line2(a-c2) = line2/a22
    c2 /= a22;//c2=c2/a22
    a25 /= a22;//a25=a25/a22
    a24 /= a22;//a24=a24/a22
    a23 /= a22;//a23=a23/a22
    a22 /= a22;//a22=a22/a22,a22=1
    //line3(a32-c3)=line3+line2(a22-c2)*(-a32)
    c3 -= c2*a32;//c3=c3+c2*(-a32)
    a35 -= a25*a32;//a35=a35+a25*(-a32)
    a34 -= a24*a32;//a34=a34+a24*(-a32)
    a33 -= a23*a32;//a33=a33+a23*(-a32)
    a32 -= a22*a32;//a32=a32+a22*(-a32),a32=0
    //line4(a42-c4)=line4 + line2(a22-c2)*(-a42)
    c4 -= c2*a42;//c4=c4+c2*(-a42)
    a45 -= a25*a42;//a45=a45+a25*(-a42)
    a44 -= a24*a42;//a44=a44+a24*(-a42)
    a43 -= a23*a42;//a43=a43+a238(-a42)
    a42 -= a22*a42;//a42=a42+a228(-a42),a42=0
    //line5(a52-c5) = line5 + line2(a22-c2)*(-a52)
    c5 -= c2*a52;//c5=c5+c28(-a52)
    a55 -= a25*a52;//a55=a55+a25*(-a52)
    a54 -= a24*a52;//a54=a54+a24*(-a52)
    a53 -= a23*a52;//a53=a53+a23*(-a52)
    a52 -= a22*a52;//a52=a52+a22*(-a52),a52=0
    //line3(a33-c3)=line3/a33
    c3 /= a33;//c3=c3/a33
    a35 /= a33;//a35=a35/a33
    a34 /= a33;//a34=a34/a33
    a33 /= a33;//a33=a33/a33,a33=1
    //line4(a43-c4)=line4+line3(a33-c3)*(-a43)
    c4 -= c3*a43;//c4=c4+c3*(-a43)
    a45 -= a35*a43;//a45=a45+a35*(-a43)
    a44 -= a34*a43;//a44=a44+a34*(-a43)
    a43 -= a33*a43;//a43=a43+a338(-a43),a43=0
    //line5(a53-c5)=line5+line3(a33-c3)*(-a53)
    c5 -= c3*a53;//c5=c5+c38(-a53)
    a55 -= a35*a53;//a55=a55+a35*(-a53)
    a54 -= a34*a53;//a54=a54+a34*(-a53)
    a53 -= a33*a53;//a53=a53+a33*(-a53),a53=0
    //line4(a44-c4)=line4/a44
    c4 /= a44;//c4=c4/a44
    a45 /= a44;//a45=a45/a44
    a44 /= a44;//a44=a44/a44, a44=1
    //line5(a54-c5)=line5+line4(a44-c4)*(-a54)
    c5 -= c4*a54;//c5=c5+c4*(-a54)
    a55 -= a45*a54;//a55=a55+a45*(-a54)
    a54 -= a44*a54;//a54=a54+a44*(-a54),a54=0
    //line5(a55-c5)=line5/a55
    c5 /=a55;//c5=c5/a55
    a55 /=a55;//a55=a55/a55,a55=1
    //line4(a45-c4)=line4+line5(a55-c5)*(-a45)
    c4 -= c5*a45;//c4=c4+c5*(-a45)
    a45 -= a55*a45;//a45=a45+a55*(-a45),a45=0
    //line3(a35-c3)=line3+line5(a55-c5)*(-a35)
    c3 -= c5*a35;//c3=c3+c5*(-a35)
    a35 -= a55*a35;//a35=a35+a55*(-a35),a35=0
    //line2(a25-c2)=line2+line5(a55-c5)*(-a25)
    c2 -= c5*a25;//c2=c2+c5*(-a25)
    a25 -= a55*a25;//a25=a25+a55*(-a25),a25=0
    //line1(a15-c1)=line1+line5(a55-c5)*(-a15)
    c1 -= c5*a15;//c1=c1+c5*(-a15)
    a15 -= a55*a15;//a15=a15+a55*(-a15),a15=0
    //line3(a34,c3)=line3+line4(a44,c4)*(-a34)
    c3 -= c4*a34;//c3=c3+c4*(-a34)
    a34 -= a44*a34;//a34=a34+a44*(-a34),a34=0
    //line2(a24,c2)=line2+line4(a44,c4)*(-a24)
    c2 -= c4*a24;//c2=c2+c4*(-a24)
    a24 -= a44*a24;//a24=a24+a44*(-a24),a24=0
    //line1(a14,c1)=line1+line4(a44,c4)*(-a14)
    c1 -= c4*a14;//c1=c1+c4*(-a14)
    a14 -= a44*a14;//a14=a14+a44*(-a14),a14=0
    //line2(a23,c2)=line2+line3(a33,c3)*(-a23)
    c2 -= c3*a23;//c2=c2+c3*(-a23)
    a23 -= a33*a23;//a23=a23+a33*(-a23),a23=0
    //line1(a13,c1)=line1+line3(a33,c3)*(-a13)
    c1 -= c3*a13;//c1=c1+c3*(-a13)
    a13 -= a33*a13;//a13=a13+a33*(-a13),a13=0
    //line1(a12,c1)=line1+line2(a22,c2)*(-a12)
    c1 -= c2*a12;//c1=c1+c2*(-a12)
    a12 -= a22*a12;//a12=a12+a22*(-a12),a12=0
    
    Matrix_Root root;
    root.set_Matrix_Root(c1,c2,c3,c4,c5);
    cout << root;
    return root;
}//end function

Matrix_Root calcu_Matrix//decalre friend of the function calculating 6 x 6 matrix
(double& a11, double& a12, double& a13, double& a14, double& a15, double& a16, double& c1,//first row
 double& a21, double& a22, double& a23, double& a24, double& a25, double& a26, double& c2,//second row
 double& a31, double& a32, double& a33, double& a34, double& a35, double& a36, double& c3,//third row
 double& a41, double& a42, double& a43, double& a44, double& a45, double& a46, double& c4,//fourth row
 double& a51, double& a52, double& a53, double& a54, double& a55, double& a56, double& c5,//fifth row
 double& a61, double& a62, double& a63, double& a64, double& a65, double& a66, double& c6)//sixth row
{
    //line1=line1/a11
    c1 /= a11;//c1=c1/a11
    a16 /= a11;//a16=a16/a11
    a15 /= a11;//a15=a15/a11
    a14 /= a11;//a14=a14/a11
    a13 /= a11;//a13=a13/a11
    a12 /= a11;//a12=a12/a11
    a11 /= a11;//a11=a11/a11, a11=1
    //line2=line2+line1*(-a21)
    c2 -= c1*a21;//c2=c2+c1*(-a21)
    a26 -= a16*a21;//a26=a26+a16*(-a21)
    a25 -= a15*a21;//a25=a25+a15*(-a21)
    a24 -= a14*a21;//a24=a24+a14*(-a21)
    a23 -= a13*a21;//a23=a23+a13*(-a21)
    a22 -= a12*a21;//a22=a22+a12*(-a21)
    a21 -= a11*a21;//a21=a21+a11*(-a21),a21=0
    //line3=line3+line1*(-a31)
    c3 -= c1*a31;//c3=c3+c1*(-a31)
    a36 -= a16*a31;
    a35 -= a15*a31;
    a34 -= a14*a31;
    a33 -= a13*a31;
    a32 -= a12*a31;
    a31 -= a11*a31;//a31=a31+a118(-a31),a31=0
    //line4=line4+line1*(-a41)
    c4 -= c1*a41;//c4=c4=c1*(-a41)
    a46 -= a16*a41;
    a45 -= a15*a41;
    a44 -= a14*a41;
    a43 -= a13*a41;
    a42 -= a12*a41;
    a41 -= a11*a41;//a41=a41+a11*(-a41)a41=0
    //line5=line5+line1*(-a51)
    c5 -= c1*a51;
    a56 -= a16*a51;
    a55 -= a15*a51;
    a54 -= a14*a51;
    a53 -= a13*a51;
    a52 -= a12*a51;
    a51 -= a11*a51;//a51=a51+a11*(-a51),a51=0
    //line6=line6+line1*(-a61)
    c6 -= c1*a61;//c6=c6+c1*(-a61)
    a66 -= a16*a61;
    a65 -= a15*a61;
    a64 -= a14*a61;
    a53 -= a13*a61;
    a62 -= a12*a61;
    a61 -= a11*a61;//a61=a61+a11*(-a61),a61=0
    //line2(a22-c2)=line2/a22
    c2 /= a22;//c2=c2/a22
    a26 /= a22;
    a25 /= a22;
    a24 /= a22;
    a23 /= a22;
    a22 /= a22;//a22=a22/a22, a22=1
    //line3(a32-c2)=line3+line2*(-a32)
    c3 -= c2*a32;//c3=c3+c2*(-a32)
    a36 -= a26*a32;//a36=a36+a26*(-a32)
    a35 -= a25*a32;
    a34 -= a24*a32;
    a33 -= a23*a32;
    a32 -= a22*a32;//a32=a32+a22*(-a32),a32=0
    //line4(a42-c4)=line4+line2*(-a42)
    c4 -= c2*a42;//c4=c4+c2*(-a42)
    a46 -= a26*a42;
    a45 -= a25*a42;
    a44 -= a24*a42;
    a43 -= a23*a42;
    a42 -= a22*a42;//a42=a42+a22*(-a42),a42=0
    //line5(a52-c5)=line5+line28(-a52)
    c5 -= c2*a52;//c5=c45+c2*(-a52)
    a56 -= a26*a52;
    a55 -= a25*a52;
    a54 -= a24*a52;
    a53 -= a23*a52;
    a52 -= a22*a52;//a52=a52*a22*(-a52),a52=0
    //line6(a62-c6)=line6+line2*(-a62)
    c6 -= c2*a62;//c6=c6*c2*(-a62)
    a66 -= a26*a62;
    a65 -= a25*a62;
    a64 -= a24*a62;
    a63 -= a23*a62;
    a62 -= a22*a62;//a62=a62+a22*(-a62),a62=0
    //line3(a33-c3)=line3/a33
    c3 /= a33;//c3=c3/a33
    a36 /= a33;
    a35 /= a33;
    a34 /= a33;
    a33 /= a33;//a33=a33/a33, a33=1
    //line4(a43-c4)=line4+line3*(-a43)
    c4 -= c3*a43;//c4=c4+c3*(-a43)
    a46 -= a36*a43;
    a45 -= a35*a43;
    a44 -= a34*a43;
    a43 -= a33*a43;//a43=a43+a33*(-a43),a43=0
    //line5(a53-c5)=line5+line3*(-a53)
    c5 -= c3*a53;//c5=c5+c3*(-a53)
    a56 -= a36*a53;
    a55 -= a35*a53;
    a54 -= a34*a53;
    a53 -= a33*a53;//a53=a53+a33*(-a53),a53=0
    //line6(a63-c6)=line6+line3*(-a63)
    c6 -= c3*a63;//c6=c6+c3*(-a63)
    a66 -= a36*a63;
    a65 -= a35*a63;
    a64 -= a34*a63;
    a63 -= a33*a63;//a63=a63+a33*(-a63),a63=0
    //line4(a44-c4) = line4/a44
    c4 /= a44;//c4=c4/a44
    a46 /= a44;
    a45 /= a44;
    a44 /= a44;//a44=a44/a44,a44=1
    //line5(a54-c5)=line5+line4*(-a54)
    c5 -= c4*a54;//c5=c5+c4*(-a54)
    a56 -= a46*a54;
    a55 -= a45*a54;
    a54 -= a44*a54;//a54=a54+a44*(-a54),a54=0
    //line6(a64-c6)=line6*line4*(-a64)
    c6 -= c4*a64;//c6=c6+c4*(-a64)
    a66 -= a46*a64;
    a65 -= a45*a64;
    a64 -= a44*a64;//a64=a64+a44*(-a64),a64=0
    //line5(a55-c5)=line5/a55
    c5 /= a55;//c5=c5/a55
    a56 /= a55;
    a55 /= a55;//a55=a55/a55,a55=1
    //line6(a65-c6)=line6+line5*(-a65)
    c6 -= c5*a65;
    a66 -= a56*a65;
    a65 -= a55*a65;//a65=a65+a55*(-a65),a65=0
    //line6(a66-c6)=line6/a66
    c6 /= a66;
    a66 /= a66;//a66=a66/a66,a66=1
    //line5(a56,c5)=line5+line6(a66,c6)*(-a56)
    c5 -= c6*a56;
    a56 -= a66*a56;//a56=a56+a66*(-a56),a56=0
    //line4(a46,c4)=line4+lne6(a66,c6)*(-a46)
    c4 -= c6*a46;
    a46 -= a66*a46;//a46=a46+a66*(-a46),a46=0
    //line3(a36,c4)=line3+line6(a66,c6)*(-a36)
    c3 -= c6*a36;
    a36 -= a66*a36;//a36=a36+a66*(-a36),a36=0
    //line2(a26,c2)=line2+lne6(a66,c60*(-a26)
    c2 -= c6*a26;
    a26 -= a66*a26;//a26=a26+a66*(-a26),a26=0
    //line2(a16,c1)=line1+lne6(a66,c60*(-a16)
    c1 -= c6*a16;
    a16 -= a66*a16;//a16=a16+a66*(-a16),a16=0
    //line4(a45,c4)=line4+line5(a55,c5)*(-a45)
    c4 -= c5*a45;
    a45 -= a55*a45;//a45=a45+a55*(-a45),a45=0
    //line3(a35,c3)=line3+line5(a55,c50*(-a35)
    c3 -= c5*a35;
    a35 -= a55*a35;//a35=a35+a55*(-a35),a35=0
    //line2(a25,c2)=line2+line5*(a55,c5)*(-a25)
    c2 -= c5*a25;
    a25 -= a55*a25;//a25=a25+a55*(-a25),a25=0
    //line1(a15,c1)=line1+line5(a55,c5)*(-a15)
    c1 -= c5*a15;
    a15 -= a55*a15;//a15=a15+a55*(-a15),a15=0
    //line3(a34,c3)=line3+line4(a44,c4)*(-a34)
    c3 -= c4*a34;
    a34 -= a44*a34;//a34=a34+a448(-a34),a34=0
    //line2(a24,c2)=line2+line4(a44,c4)*(-a24)
    c2 -= c4*a24;
    a24 -= a44*a24;//a24=a24+a448(-a24),a24=0
    //line1(a14,c1)=line1+line4(a44,c4)*(-a14)
    c1 -= c4*a14;
    a14 -= a44*a14;//a14=a14+a44*(-a14),a14=0
    //line2(a23,c2)=line2+line3(a33,c3)*(-a23)
    c2 -= c3*a23;
    a23 -= a33*a23;//a23=a23+a33*(-a23),a23=0
    //line1(a13,c1)=line1+line3(a33,c3)*(-a13)
    c1 -= c3*a13;
    a13 -= a33*a13;//a13=a13+a33*(-a13),a13=0
    //line1(a12,c1)=line1+line2(a22,c2)*(-a12)
    c1 -= c2*a12;
    a12 -= a22*a12;//a12=a12+a22*(-a12),a12=0
    
    Matrix_Root root;
    root.set_Matrix_Root(c1,c2,c3,c4,c5,c6);
    cout << root;
    return root;
}//end function

Matrix_Root calcu_Matrix//declare friend of the function calculating 6 x 6 matrix
(Complex& a11, Complex& a12, Complex& a13, Complex& a14, Complex& a15, Complex& a16, Complex& c1,//first row
 Complex& a21, Complex& a22, Complex& a23, Complex& a24, Complex& a25, Complex& a26, Complex& c2,//second row
 Complex& a31, Complex& a32, Complex& a33, Complex& a34, Complex& a35, Complex& a36, Complex& c3,//third row
 Complex& a41, Complex& a42, Complex& a43, Complex& a44, Complex& a45, Complex& a46, Complex& c4,//fourth row
 Complex& a51, Complex& a52, Complex& a53, Complex& a54, Complex& a55, Complex& a56, Complex& c5,//fifth row
 Complex& a61, Complex& a62, Complex& a63, Complex& a64, Complex& a65, Complex& a66, Complex& c6)//sixth row
{
    //line1=line1/a11
    c1 /= a11;//c1=c1/a11
    a16 /= a11;//a16=a16/a11
    a15 /= a11;//a15=a15/a11
    a14 /= a11;//a14=a14/a11
    a13 /= a11;//a13=a13/a11
    a12 /= a11;//a12=a12/a11
    a11 /= a11;//a11=a11/a11, a11=1
    //line2=line2+line1*(-a21)
    c2 -= c1*a21;//c2=c2+c1*(-a21)
    a26 -= a16*a21;//a26=a26+a16*(-a21)
    a25 -= a15*a21;//a25=a25+a15*(-a21)
    a24 -= a14*a21;//a24=a24+a14*(-a21)
    a23 -= a13*a21;//a23=a23+a13*(-a21)
    a22 -= a12*a21;//a22=a22+a12*(-a21)
    a21 -= a11*a21;//a21=a21+a11*(-a21),a21=0
    //line3=line3+line1*(-a31)
    c3 -= c1*a31;//c3=c3+c1*(-a31)
    a36 -= a16*a31;
    a35 -= a15*a31;
    a34 -= a14*a31;
    a33 -= a13*a31;
    a32 -= a12*a31;
    a31 -= a11*a31;//a31=a31+a118(-a31),a31=0
    //line4=line4+line1*(-a41)
    c4 -= c1*a41;//c4=c4=c1*(-a41)
    a46 -= a16*a41;
    a45 -= a15*a41;
    a44 -= a14*a41;
    a43 -= a13*a41;
    a42 -= a12*a41;
    a41 -= a11*a41;//a41=a41+a11*(-a41)a41=0
    //line5=line5+line1*(-a51)
    c5 -= c1*a51;
    a56 -= a16*a51;
    a55 -= a15*a51;
    a54 -= a14*a51;
    a53 -= a13*a51;
    a52 -= a12*a51;
    a51 -= a11*a51;//a51=a51+a11*(-a51),a51=0
    //line6=line6+line1*(-a61)
    c6 -= c1*a61;//c6=c6+c1*(-a61)
    a66 -= a16*a61;
    a65 -= a15*a61;
    a64 -= a14*a61;
    a53 -= a13*a61;
    a62 -= a12*a61;
    a61 -= a11*a61;//a61=a61+a11*(-a61),a61=0
    //line2(a22-c2)=line2/a22
    c2 /= a22;//c2=c2/a22
    a26 /= a22;
    a25 /= a22;
    a24 /= a22;
    a23 /= a22;
    a22 /= a22;//a22=a22/a22, a22=1
    //line3(a32-c2)=line3+line2*(-a32)
    c3 -= c2*a32;//c3=c3+c2*(-a32)
    a36 -= a26*a32;//a36=a36+a26*(-a32)
    a35 -= a25*a32;
    a34 -= a24*a32;
    a33 -= a23*a32;
    a32 -= a22*a32;//a32=a32+a22*(-a32),a32=0
    //line4(a42-c4)=line4+line2*(-a42)
    c4 -= c2*a42;//c4=c4+c2*(-a42)
    a46 -= a26*a42;
    a45 -= a25*a42;
    a44 -= a24*a42;
    a43 -= a23*a42;
    a42 -= a22*a42;//a42=a42+a22*(-a42),a42=0
    //line5(a52-c5)=line5+line28(-a52)
    c5 -= c2*a52;//c5=c45+c2*(-a52)
    a56 -= a26*a52;
    a55 -= a25*a52;
    a54 -= a24*a52;
    a53 -= a23*a52;
    a52 -= a22*a52;//a52=a52*a22*(-a52),a52=0
    //line6(a62-c6)=line6+line2*(-a62)
    c6 -= c2*a62;//c6=c6*c2*(-a62)
    a66 -= a26*a62;
    a65 -= a25*a62;
    a64 -= a24*a62;
    a63 -= a23*a62;
    a62 -= a22*a62;//a62=a62+a22*(-a62),a62=0
    //line3(a33-c3)=line3/a33
    c3 /= a33;//c3=c3/a33
    a36 /= a33;
    a35 /= a33;
    a34 /= a33;
    a33 /= a33;//a33=a33/a33, a33=1
    //line4(a43-c4)=line4+line3*(-a43)
    c4 -= c3*a43;//c4=c4+c3*(-a43)
    a46 -= a36*a43;
    a45 -= a35*a43;
    a44 -= a34*a43;
    a43 -= a33*a43;//a43=a43+a33*(-a43),a43=0
    //line5(a53-c5)=line5+line3*(-a53)
    c5 -= c3*a53;//c5=c5+c3*(-a53)
    a56 -= a36*a53;
    a55 -= a35*a53;
    a54 -= a34*a53;
    a53 -= a33*a53;//a53=a53+a33*(-a53),a53=0
    //line6(a63-c6)=line6+line3*(-a63)
    c6 -= c3*a63;//c6=c6+c3*(-a63)
    a66 -= a36*a63;
    a65 -= a35*a63;
    a64 -= a34*a63;
    a63 -= a33*a63;//a63=a63+a33*(-a63),a63=0
    //line4(a44-c4) = line4/a44
    c4 /= a44;//c4=c4/a44
    a46 /= a44;
    a45 /= a44;
    a44 /= a44;//a44=a44/a44,a44=1
    //line5(a54-c5)=line5+line4*(-a54)
    c5 -= c4*a54;//c5=c5+c4*(-a54)
    a56 -= a46*a54;
    a55 -= a45*a54;
    a54 -= a44*a54;//a54=a54+a44*(-a54),a54=0
    //line6(a64-c6)=line6*line4*(-a64)
    c6 -= c4*a64;//c6=c6+c4*(-a64)
    a66 -= a46*a64;
    a65 -= a45*a64;
    a64 -= a44*a64;//a64=a64+a44*(-a64),a64=0
    //line5(a55-c5)=line5/a55
    c5 /= a55;//c5=c5/a55
    a56 /= a55;
    a55 /= a55;//a55=a55/a55,a55=1
    //line6(a65-c6)=line6+line5*(-a65)
    c6 -= c5*a65;
    a66 -= a56*a65;
    a65 -= a55*a65;//a65=a65+a55*(-a65),a65=0
    //line6(a66-c6)=line6/a66
    c6 /= a66;
    a66 /= a66;//a66=a66/a66,a66=1
    //line5(a56,c5)=line5+line6(a66,c6)*(-a56)
    c5 -= c6*a56;
    a56 -= a66*a56;//a56=a56+a66*(-a56),a56=0
    //line4(a46,c4)=line4+lne6(a66,c6)*(-a46)
    c4 -= c6*a46;
    a46 -= a66*a46;//a46=a46+a66*(-a46),a46=0
    //line3(a36,c4)=line3+line6(a66,c6)*(-a36)
    c3 -= c6*a36;
    a36 -= a66*a36;//a36=a36+a66*(-a36),a36=0
    //line2(a26,c2)=line2+lne6(a66,c60*(-a26)
    c2 -= c6*a26;
    a26 -= a66*a26;//a26=a26+a66*(-a26),a26=0
    //line2(a16,c1)=line1+lne6(a66,c60*(-a16)
    c1 -= c6*a16;
    a16 -= a66*a16;//a16=a16+a66*(-a16),a16=0
    //line4(a45,c4)=line4+line5(a55,c5)*(-a45)
    c4 -= c5*a45;
    a45 -= a55*a45;//a45=a45+a55*(-a45),a45=0
    //line3(a35,c3)=line3+line5(a55,c50*(-a35)
    c3 -= c5*a35;
    a35 -= a55*a35;//a35=a35+a55*(-a35),a35=0
    //line2(a25,c2)=line2+line5*(a55,c5)*(-a25)
    c2 -= c5*a25;
    a25 -= a55*a25;//a25=a25+a55*(-a25),a25=0
    //line1(a15,c1)=line1+line5(a55,c5)*(-a15)
    c1 -= c5*a15;
    a15 -= a55*a15;//a15=a15+a55*(-a15),a15=0
    //line3(a34,c3)=line3+line4(a44,c4)*(-a34)
    c3 -= c4*a34;
    a34 -= a44*a34;//a34=a34+a448(-a34),a34=0
    //line2(a24,c2)=line2+line4(a44,c4)*(-a24)
    c2 -= c4*a24;
    a24 -= a44*a24;//a24=a24+a448(-a24),a24=0
    //line1(a14,c1)=line1+line4(a44,c4)*(-a14)
    c1 -= c4*a14;
    a14 -= a44*a14;//a14=a14+a44*(-a14),a14=0
    //line2(a23,c2)=line2+line3(a33,c3)*(-a23)
    c2 -= c3*a23;
    a23 -= a33*a23;//a23=a23+a33*(-a23),a23=0
    //line1(a13,c1)=line1+line3(a33,c3)*(-a13)
    c1 -= c3*a13;
    a13 -= a33*a13;//a13=a13+a33*(-a13),a13=0
    //line1(a12,c1)=line1+line2(a22,c2)*(-a12)
    c1 -= c2*a12;
    a12 -= a22*a12;//a12=a12+a22*(-a12),a12=0
    
    Matrix_Root root;
    root.set_Matrix_Root(c1,c2,c3,c4,c5,c6);
    cout << root;
    return root;
}//end function
