//
//  poly.h
//
//  Created by Josiah Zacharias on  1/07/2020.
//  Last modified on 1/14/2020
//
//  Poly Object: represents a Polynomial as an array of terms. One term
//  is stored as an array element, with the index representing the power
//  and the int value stored as the coefficient. Constructors may receive
//  at most two values — the coefficient of the term and the largest
//  exponent currently expected. Later additions may be added or retrieved,
//  as well as using arithmetic operators to modify Polynomials separately
//  or together.

//  Assumptions:
//     -- All data is assumed to be correct as no exceptions are thrown
//     -- Only non-negative power allowed, and are ignored if entered

#ifndef POLY_H
#define POLY_H
#include <iostream>
using namespace std;

class Poly {
    
    
    
   //---------------------------------------------------------------------------
   // operator>>
   //--------------------------------------------------------------------------
   // overloaded >>: takes a series of pairs of int Coefficients and corresponding
   // Power from input in a loop, terminating when -1 -1 is entered.
   //
   // @param input: the istream input from which the pairs are read
   // @param rhs: reference to the Poly object to which the input Terms are added
   // @pre: Input must include corresponding pairs of integers (separated by space
   // or enter) ending with input of -1 -1
   // @post: the input numbers from the istream are removed and corresponding
   // terms of coefficient/power pairs added to the rhs Poly and returned
   // @return: reference to istream with integers removed except -1 -1
    
   friend istream &operator>>( istream &in, Poly &rhs );
    
   //--------------------------------------------------------------------------
   // operator<<
   //--------------------------------------------------------------------------
   // overloaded <<: prints out Poly with the form:
   // cnx^n + cn-1x^(n-1) + ... + c1x + c0
   // not printing any terms that have coefficient of 0
   //
   // @param output: the ostream to which the Polynomial will be written
   // @param p: the Poly object to be written
   // @pre: none
   // @post: Parameter Poly object remains unchanged, while ostream contains
   // a string representation of the Polynomial
   // @return: reference to ostream containing Poly String representation
    
   friend ostream& operator<<( ostream &output, const Poly& p );
    
 public:
// Member functions

//--------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------
// Poly
// Default constructor for a Poly of size 1 (0x^0)
//
// @pre: none
// @post: Creates an array of size 1 with 0 as the value
    
  Poly();
    
    
//--------------------------------------------------------------------------
// Constructor with single parameter
//--------------------------------------------------------------------------
// Poly
// Constructor for Poly of size 1 with first term coefficient (x^0) set
// to specified value.
//
// @param coeff: the Coefficient of the x^0 term
// @pre: none
// @post: Creates an array of size 1 with input used as coeff
    
  Poly(int coeff);
    
    
//--------------------------------------------------------------------------
// Constructor with two parameters
//--------------------------------------------------------------------------
// Poly
// Constructor with two int parameters to create Poly object with size
// determined by exponent.
//
// @param coeff: the Coefficient of the x^0 term
// @param power: the degree of the polynomial, and last index of the array
// @pre: none
// @post: Creates an array of size set to power + 1 with coeff as value for last index
    
  Poly(int coeff, int power);
    
    
//--------------------------------------------------------------------------
// Copy Constructor
//--------------------------------------------------------------------------
// Poly
// Copy constructor for Poly object, creating a deep copy
//
// @param p: parameter Poly to be copied
// @pre: Input is a Poly
// @post: Provides a deep copy of the original Poly
    
  Poly( const Poly& p );
    
    
//--------------------------------------------------------------------------
// Destructor
//--------------------------------------------------------------------------
// ~Poly
// Destructor for Poly object.  Takes care of de-allocating array to the system.
//
// @pre: none
// @post: Deallocates array and sets array pointer to NULL
    
  ~Poly( );
    
    
//--------------------------------------------------------------------------
// Get Coefficient
//--------------------------------------------------------------------------
// getCoeff
// returns the coefficient of the x^power term in the Poly
//
// @param power: the power of the term associated with the Coefficient to return
// @pre: int power must be a term of x^power in Poly, or
// or otherwise returns 0.
// @post: If Poly is not empty, returns the coefficient of the
// term with indicated power. Returns 0 if Poly is empty
// @return: the int coefficient of the Power term
    
  int getCoeff(const int power) const;
    
    
//--------------------------------------------------------------------------
// Set Coefficient
//--------------------------------------------------------------------------
// setCoeff
// Replaces the coefficient of the x^power term, returning the boolean value
// of success
//
// @param newCoefficient: the new int coefficient to be set
// @param power: the power of the term to be set, negatives are ignored and
// returns false
// Pre: if int power is not an x^power term in the Poly, adds new term
// Otherwise updates coefficient. newCoefficient must be nonzero to
// add a term. Power must be >= 0.
// Post: Updates the coefficient of the x^power term (or adds a term) and returns true. If Power is <0, it is ignored and returns false
// @return: the boolean value of success of setting the Coefficient

  bool setCoeff( const int newCoefficient, const int power );


// Arithmetic operators
    
//--------------------------------------------------------------------------
// operator+
//--------------------------------------------------------------------------
// overloaded +: addition of 2 Polys, current object and parameter
//
// @param p: Poly object to be added
// @pre: none
// @post: Input Poly objects remain unchanged and summation is returned
// @return: the Poly result of the summation
    
  Poly operator+(const Poly& p) const;
    
    
//--------------------------------------------------------------------------
// operator-
//--------------------------------------------------------------------------
// overloaded -: subtraction of 2 Polys, parameter from the current object
//
// @param p: Poly object to be subtracted
// @pre: none
// @post: Input Poly objects remain unchanged and difference is returned
// @return: the Poly result of the subtraction
    
  Poly operator-(const Poly& p) const;
    
    
//--------------------------------------------------------------------------
// operator*
//--------------------------------------------------------------------------
// overloaded *: multiplation of 2 Polys, current object and parameter
//
// @param p: Poly object to be multiplied by this
// @pre: none
// @post: Input Poly objects remain unchanged and product is returned
// @return: the Poly result of the multiplication
    
  Poly operator*(const Poly& p) const;

    
// Boolean comparison operators
    
    
//--------------------------------------------------------------------------
// operator==
//--------------------------------------------------------------------------
// overloaded ==: true if this Poly == parameter Poly, false if not
//
// @param p: Poly object to be compared to this
// @pre: none
// @post: returns true if this Poly == parameter polynomial
// @return the value of equivalence
    
  bool operator==(const Poly& p) const;
    
    
//--------------------------------------------------------------------------
// operator!=
//--------------------------------------------------------------------------
// overloaded !=: true if this Poly != parameter Poly, false if not
//
// @param p: Poly object to be compared to this
// @pre: none
// Post:  returns true if this Poly != parameter polynomial
// @return the value of non-equivalence
    
  bool operator!=(const Poly& p) const;

  // Assignment operators
    
//--------------------------------------------------------------------------
// operator=
//--------------------------------------------------------------------------
// overloaded =: true if this Poly != parameter Poly, false if not
//
// @param p: Poly object to be copied
// Pre: none
// Post: Provides a deep copy of the parameter Poly and sets to RHS of this
// @return: this reference to new Poly
    
  Poly& operator=( const Poly& p );
    
    
//--------------------------------------------------------------------------
// operator+=
//--------------------------------------------------------------------------
// overloaded +=: current Poly = current Poly + parameter,
//
// @param p: Poly object to be added to this
// @pre: none
// @post: Parameter Poly object remains unchanged and ref to this is returned
// @return: reference to this, post summation
    
  Poly& operator+=( const Poly& p );
    
    
//--------------------------------------------------------------------------
// operator-=
//--------------------------------------------------------------------------
// overloaded -=: current Poly = current Poly - parameter,
//
// @param p: Poly object to be subtracted from this
// @pre: none
// @post: Parameter Poly object remains unchanged and ref to this is returned
// @return: reference to this, post subtraction
    
  Poly& operator-=( const Poly& p );
    
    
//--------------------------------------------------------------------------
// operator*=
// overloaded *=: current Poly = current Poly * parameter,
//
// @param p: Poly object to be multiplied by this
// @pre: none
// @post: Parameter Poly object remains unchanged and ref to this is returned
// @return: reference to this, post multiplication
    
  Poly& operator*=( const Poly& p );
    
 private:
  int* polyArray;   // points to array
  int size;         // size of the array, or index of the power of the
                    // largest term in the array
};

#endif
