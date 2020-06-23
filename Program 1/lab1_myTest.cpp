//
//  lab1_myTest.cpp
//  Program 1
//
//  Created by Josiah Zacharias on 1/7/20 to more thoroughly test poly.cpp
//  Copyright © 2020 Josiah Zacharias. All rights reserved.
//

#include "poly.h"
#include <iostream>
using namespace std;

int main() {

    Poly A(5, 7), B(3, 4), C(2), D(A), X, Y;
    Poly A2, B2, Z1, Z2;
 cout << boolalpha;
    // set polynomials A and B to desired values
    // A = +5x^7 -4x^3 +10x -2
    // B = +3x^4 +1x^3
    cout << "Enter terms for polynomial A.  Enter a coefficient " << endl
    << "then exponent for each term. Enter -1 -1 to terminate." << endl;
    //    cin >> A;                      // or use a bunch of setCoeff
    A.setCoeff(5, 7);
    A.setCoeff(10, 1);
    A.setCoeff(-4, 3);
    A.setCoeff(-2, 0);

    cout << "Enter terms for polynomial B.  Enter a coefficient " << endl
    << "then exponent for each term. Enter -1 -1 to terminate." << endl;
    //    cin >> B;                     // or use a bunch of setCoeff
    B.setCoeff(3, 4);
    B.setCoeff(1, 3);

    // outputs exactly what is in quotes: "A = +5x^7 -4x^3 +10x -2"
    cout << "A =" << A << endl;
    // outputs exactly what is in quotes: "B = +3x^4 +1x^3"
    cout << "B =" << B << endl << endl;

    A2 = A;
    B2 = B;
    C = A + B;
    cout << "Compute C = A + B: " << C << endl << endl;

    cout << ((A == B) ? "A == B" : "A is not == B") << endl;
    cout << ((A != B) ? "A is not == B" : "A == B") << endl << endl;
    
    cout << ((A == A2) ? "A == A2" : "A is not == A2") << endl;
    cout << ((A != A2) ? "A is not == A2" : "A == A2") << endl << endl;

    Z1 = A2 - B2;
    cout << "Compute  Z1 = A2 - B2: " << Z1 << endl;
    Z2 = B2 - A2;
    cout << "Compute  Z2 = B2 - A2: " << Z2 << endl << endl;

    cout << "Compute  D = A * B - 15" << endl;
    cout << "Before: D =" << D << endl;
    D = A * B - 15;
    cout << "After:  D =" << D << endl << endl;

    cout << "Test assignment operators" << endl;
    X = C = D = D;
    Y += A -= B *= A;
    cout << "X =" << X << endl;
    cout << "Y =" << Y << endl << endl;

    cout << "Get and Set coefficient" << endl;
    int coeff = D.getCoeff(0);
    cout << "coeff of subscript 0 of D is: " << coeff << endl;
    cout << "Doing getCoeff for term -20000" << endl;
    coeff = D.getCoeff(-20000);              // handle value out of range
    D.setCoeff(50, 0);                        // set x^0 coeff to 50
    D.setCoeff(50, 20000);                    // set x^20000 coeff to 50
    cout << "D =" << D << endl << endl;


    Poly F(5, -5);
    cout << "F =" << F << endl;
    cout << "F == A?: " << (F == A) << endl;            // Test boolean ==
    cout << "F != A?: " << (F != A) << endl << endl;    // Test boolean !=
    
    cout << endl << "New Polynomial p1" << endl << endl;
      Poly p1;          // Test default constructor
                              // Valgrind confirms functioning destructor

      // Testing Member functions
     
      cout << "successful setCoeff (1, 1) to p1: " << p1.setCoeff( 1, 1 ) << endl;  // Test changeCoefficient
      cout << "successful setCoeff  (4, 4) to p1: " << p1.setCoeff( 4, 4 ) << endl;  // Which also tests insert
      cout << "successful setCoeff (2.2, 2) to p1: " << p1.setCoeff( 2.2, 2 ) << endl;
      cout << "successful setCoeff  (1,1) to p1: " << p1.setCoeff( -3.8, 3 ) << endl << endl;
    
      cout << "coefficient of power 3 Term in p1 is: " // Test coefficient retrieval
              << p1.getCoeff(3) << endl;
      cout << "p1 = " << p1 << endl << endl;           // Test output operator

      cout << "successful setCoeff(0, 2) to p1: " // Test zero coefficient
              << p1.setCoeff( 0, 2 ) << endl;
      cout << "p1 = " << p1 << endl;                   // Test output of zero coeff
      cout << "coefficient of power 2 Term in p1 is: " << p1.getCoeff(2) << endl << endl;                                   // Test coefficient retrieval of zero

      // Testing Copy and Assignment= Operator
      Poly p5;
      p5.setCoeff( 0, 0 );
      cout << "p5 = " << p5 << endl;
      cout << "set p2 = p5" << endl;
      Poly p2 = p5;             // Test copy constructor, assignment= , and clear for empty
      cout << "p2 = " << p2 << endl << endl;
      
      // Testing boolean functions
      p2 = p2;                        // Test for self-assignment
      cout << "set p2 = p1" << endl;
      p2 = p1;                        // Test copy constructor, assignment= , and clear for non-empty
      cout << "p1 = " << p1 << endl;
      cout << "p2 = " << p2 << endl;
      cout << "p2 == p1?: " << (p2 == p1) << endl;            // Test boolean ==
      cout << "p2 != p1?: " << (p2 != p1) << endl << endl;    // Test boolean !=
      
      cout << "successful setCoeff (9.5, 2) to p2: " // Making p1 and p2 not equal
              << p2.setCoeff( 9.5, 2 ) << endl;
      cout << "p1 = " << p1 << endl;
      cout << "p2 = " << p2 << endl;
      cout << "p2 == p1?: " << (p2 == p1) << endl;  // Test boolean == again
      cout << "p2 != p1?: " << (p2 != p1) << endl << endl;          // Test boolean != again


      // Testing arithmetic operators
      Poly p3 = p1 + p2;
      Poly p7 = p1 + p5;
      Poly p4 = p5 - p2;
      Poly p6 = p1 - p2;
      cout << "p1 + p2 = " << p3 << endl;         // Test normal addition
      cout << "p1 + p5 = " << p7 << endl;         // Test addition with empty Polynomial
      cout << "p1 - p2 = " << p6 << endl;         // Test normal subtraction
      cout << "p5 - p2 = " << p4 << endl <<endl;  // Test substraction with empty Polynomial
      
      // Testing Assignment Operators
      cout << "p2 += p1 : " << (p2 += p1) << endl; // Test normal addition
      cout << "p2 += p5 : " << (p2 += p5) << endl; // Test addition with empty Polynomial
      cout << "p2 -= p1 : " << (p2 -= p1) << endl; // Test normal subtraction
      cout << "p2 -= p5 : " << (p2 -= p5) << endl << endl; // Test substraction with empty Polynomial
    
    
    return 0;
}

