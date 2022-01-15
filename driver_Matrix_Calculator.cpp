//
//  driver_Matrix_Calculator.cpp
//  Yifan's App
//
//  Created by Yifan Huang on 2019-05-22.
//  Copyright © 2019 Yifan Huang. All rights reserved.
//

#include "matrix_Calculator.h"
#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>
#include <array>
using namespace std;

enum matrix_size{zero=0,one,two,three,four,five,six,seven,eight,nigh,ten};
matrix_size get_size();
int main(){
   
    matrix_size choice = get_size();
    // give the condtion to choose
    if (choice == one||choice ==zero)
        return 0;
    else {
        string S1{"null"};//declare string to store the value
        istringstream iss;//declare istringstream object to store string value
        switch (choice){
            case matrix_size::two://choose 2X2 matrix
                cout << "enter each elements for 2 X 2 matrix" << endl;
                cout << "matrix should be entered like : \n"<< "a11, a12, c1\n" << "a21, a22, c2" << endl;
                cout << "Complex number should be entered like a+j*b or a+jb" << endl;
                array<array<Complex*,3>,2>ptr_Complex2;//declare the 2x2 complex array as matrix elements
                //array<array<double*,3>,2>ptr_double;//declare the 2x2 double array as matrix elements
                for (auto& row: ptr_Complex2){//nested loop on row
                    cout << "Input line:" << endl;
                    for (auto& element: row){//nested loop on column
                        cin >> S1;
                        iss.str(S1);
                        Complex hold_c;
                        iss >> hold_c;
                        element = new Complex(hold_c);
                    }
                }//end nested for loop
                calcu_Matrix
                (*ptr_Complex2[0][0],*ptr_Complex2[0][1],*ptr_Complex2[0][2],
                 *ptr_Complex2[1][0],*ptr_Complex2[1][1],*ptr_Complex2[1][2]);
                for (auto& row:ptr_Complex2){
                    for (auto& element:row){
                        delete element;//delete each pointer in array to release memory
                    }
                }
                break;
            case matrix_size::three://choose 3x3 matrix
                cout << "enter each elements for 3 X 3 matrix" << endl;
                cout << "matrix should be entered like :\n " << "a11, a12, a13, c1\n" << endl;
                cout << "Complex number should be entered like a+j*b or a+jb" << endl;
                array<array<Complex*,4>,3>ptr_Complex3;
                for (auto& row:ptr_Complex3){
                    cout<< "Input line: " << endl;
                    for (auto& element:row){
                        cin >> S1;
                        iss.str(S1);
                        Complex hold_c;
                        iss >> hold_c;
                        element = new Complex(hold_c);
                    }
                }
                calcu_Matrix
                (*ptr_Complex3[0][0],*ptr_Complex3[0][1],*ptr_Complex3[0][2],*ptr_Complex3[0][3],
                 *ptr_Complex3[1][0],*ptr_Complex3[1][1],*ptr_Complex3[1][2],*ptr_Complex3[1][3],
                 *ptr_Complex3[2][0],*ptr_Complex3[2][1],*ptr_Complex3[2][2],*ptr_Complex3[2][3]);
                for (auto& row:ptr_Complex3){
                    for(auto& element:row){
                        delete element;
                    }
                }
                break;
            case matrix_size::four:
                cout << "enter each elements for 4 X 4 matrix" << endl;
                cout << "matrix should be entered like :\n " << "a11, a12, a13, a14, c1\n" << endl;
                cout << "Complex number should be entered like a+j*b or a+jb" << endl;
                array<array<Complex*,5>,4>ptr_Complex4;
                for (auto& row:ptr_Complex4){
                    cout << "Inpiut line: " << endl;
                    for (auto& element:row){
                        cin >> S1;
                        iss.str(S1);
                        Complex hold_c;
                        iss >> hold_c;
                        element = new Complex(hold_c);
                    }
                }
                calcu_Matrix
(*ptr_Complex4[0][0],*ptr_Complex4[0][1],*ptr_Complex4[0][2],*ptr_Complex4[0][3],*ptr_Complex4[0][4],
 *ptr_Complex4[1][0],*ptr_Complex4[1][1],*ptr_Complex4[1][2],*ptr_Complex4[1][3],*ptr_Complex4[1][4],
 *ptr_Complex4[2][0],*ptr_Complex4[2][1],*ptr_Complex4[2][2],*ptr_Complex4[2][3],*ptr_Complex4[2][4],
 *ptr_Complex4[3][0],*ptr_Complex4[3][1],*ptr_Complex4[3][2],*ptr_Complex4[3][3],*ptr_Complex4[3][4]);
                for (auto& row:ptr_Complex4){
                    for(auto& element:row){
                        delete element;
                    }
                }
                break;
            case matrix_size::five:
                cout << "enter each elements for 5 X 5 matrix" << endl;
                cout << "matrix should be entered like :\n " << "a11, a12, a13, a14, a15, c1\n" << endl;
                cout << "Complex number should be entered like a+j*b or a+jb" << endl;
                array<array<Complex*,6>,5>ptr_Complex5;
                for (auto& row:ptr_Complex5){
                    cout << "Input line: " << endl;
                    for (auto& element:row){
                        cin >> S1;
                        iss.str(S1);
                        Complex hold_c;
                        iss >> hold_c;
                        element = new Complex(hold_c);
                    }
                }
                calcu_Matrix
                (*ptr_Complex5[0][0],*ptr_Complex5[0][1],*ptr_Complex5[0][2],*ptr_Complex5[0][3],
                 *ptr_Complex5[0][4],*ptr_Complex5[0][5],
                 *ptr_Complex5[1][0],*ptr_Complex5[1][1],*ptr_Complex5[1][2],*ptr_Complex5[1][3],
                 *ptr_Complex5[1][4],*ptr_Complex5[1][5],
                 *ptr_Complex5[2][0],*ptr_Complex5[2][1],*ptr_Complex5[2][2],*ptr_Complex5[2][3],
                 *ptr_Complex5[2][4],*ptr_Complex5[2][5],
                 *ptr_Complex5[3][0],*ptr_Complex5[3][1],*ptr_Complex5[3][2],*ptr_Complex5[3][3],
                 *ptr_Complex5[3][4],*ptr_Complex5[3][5],
                 *ptr_Complex5[4][0],*ptr_Complex5[4][1],*ptr_Complex5[4][2],*ptr_Complex5[4][3],
                 *ptr_Complex5[4][4],*ptr_Complex5[5][5]);
                for (auto& row:ptr_Complex5){
                    for(auto& element:row){
                        delete element;
                    }
                }
                break;
            case matrix_size::six:
                cout << "enter each elements for 6 X 6 matrix" << endl;
                cout << "matrix should be entered like :\n " << "a11, a12, a13, a14, a15, a16, c1\n" << endl;
                cout << "Complex number should be entered like a+j*b or a+jb" << endl;
                array<array<Complex*,7>,6>ptr_Complex6;
                for (auto& row:ptr_Complex6){
                    cout << "Input line: " << endl;
                    for (auto& element:row){
                        cin >> S1;
                        iss.str(S1);
                        Complex hold_c;
                        iss >> hold_c;
                        element = new Complex(hold_c);
                    }
                }
                calcu_Matrix
                (*ptr_Complex6[0][0],*ptr_Complex6[0][1],*ptr_Complex6[0][2],*ptr_Complex6[0][3],
                 *ptr_Complex6[0][4],*ptr_Complex6[0][5],*ptr_Complex6[0][6],
                 *ptr_Complex6[1][0],*ptr_Complex6[1][1],*ptr_Complex6[1][2],*ptr_Complex6[1][3],
                 *ptr_Complex6[1][4],*ptr_Complex6[1][5],*ptr_Complex6[1][6],
                 *ptr_Complex6[2][0],*ptr_Complex6[2][1],*ptr_Complex6[2][2],*ptr_Complex6[2][3],
                 *ptr_Complex6[2][4],*ptr_Complex6[2][5],*ptr_Complex6[2][6],
                 *ptr_Complex6[3][0],*ptr_Complex6[3][1],*ptr_Complex6[3][2],*ptr_Complex6[3][3],
                 *ptr_Complex6[3][4],*ptr_Complex6[3][5],*ptr_Complex6[3][6],
                 *ptr_Complex6[4][0],*ptr_Complex6[4][1],*ptr_Complex6[4][2],*ptr_Complex6[4][3],
                 *ptr_Complex6[4][4],*ptr_Complex6[5][5],*ptr_Complex6[4][6],
                 *ptr_Complex6[5][0],*ptr_Complex6[5][1],*ptr_Complex6[5][2],*ptr_Complex6[5][3],
                 *ptr_Complex6[5][4],*ptr_Complex6[5][5],*ptr_Complex6[5][6]);
                for (auto& row:ptr_Complex6){
                    for (auto& element: row){
                        delete element;
                    }
                }
                break;
                
            }
                
        }
    

   /* test
    
    //test
    Complex b11(1,1);
    Complex b12(1,2); Complex b13(2,4);Complex b14(5);
    Complex a1(4,4);
    Complex b21(2);
    Complex b22(2); Complex b23(3); Complex b24(10);
    Complex a2(4);
    Complex b31(1,1);
    Complex b32(0,1);
    Complex b33(0,5); Complex b34(1);
    Complex a3(5);
    Complex b41(10,1);
    Complex b42(0,10);
    Complex b43(0,2);
    Complex b44(0,1);
    Complex a4(1,-1);
    
    Matrix_Root root;
    //root = calcu_Matrix(b11, b12, a1, b21, b22, a2);
    
    double a11{1}, a12{2}, a13{4}, a14{8},c1{10},a21{10},a22{2},a23{5},a24{20},c2{105},
    a31{6},a32{9},a33{3},a34{1},c3{20},a41{15},a42{4},a43{2},a44{30},c4{10};
    
    cout << "4 x 4 double: " <<endl;
    calcu_Matrix
    (a11,a12,a13,a14,c1,
     a21,a22,a23,a24,c2,
     a31,a32,a33,a34,c3,
     a41,a42,a43,a44,c4);
    try{
        cout << "2 x 2 Complex: " << endl;
        calcu_Matrix
        (b11, b12, a1,
         b21, b22, a2);
    }catch(runtime_error& a){
        cout << a.what() << endl;
    }catch(logic_error& a){
        cout << a.what()<<endl;
    }catch(bad_alloc& a){
        cout << a.what() <<endl;
    }
    
    Complex x1(1,1); Complex y1(-0.74, -0.45);
    //cout << "test1" <<endl;
    Complex x2(0,1); Complex y2(2.88, 2.59);
    Complex x3(0,5); Complex y3(-0.34, -1.58);
    x1.multip_Comp(y1);
    x2.multip_Comp(y2);
    x3.multip_Comp(y3);
    
    x2.add_Comp(x3);
    x1.add_Comp(x2);
    cout << "c3= " <<endl;
    x1.print_Comp();
    
   
    string a{"2.3+j*9.1 4.5+j*8.1 j*3 10 "};
    istringstream iss;
    Complex comp;
    iss.str(a);
    for (int i{0};i<4;++i){
        iss >> comp;
        cout << comp <<endl;
    }
*/
    
    return 0;
}

matrix_size get_size(){
    // prompt user to choose the size of matrix
    cout << "choose the size of matrix or 1 to exit program" << endl;
    cout << "2 X 2 matrix,  enter 2\n";
    cout << "3 X 3 matrix,  enter 3\n";
    cout << "4 X 4 matrix,  enter 4\n";
    cout << "5 X 5 matrix,  enter 5\n";
    cout << "6 X 6 matrix,  enter 6\n";
    cout << "7 X 7 matrix,  enter 7\n";
    cout << "8 X 8 matrix,  enter 8\n";
    cout << "9 X 9 matrix,  enter 9\n";
    cout << "10 X 10 matrix,  enter 10\n";
    
    unsigned int choice{0}; // declare variable
    do{
    cin >> choice ; // read from input
    }while (choice < static_cast<int>(matrix_size::zero) || choice > static_cast<int>(matrix_size::ten));
    return static_cast<matrix_size>(choice);
    
}//end

