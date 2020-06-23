//
//  poly.cpp
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

#include "poly.h"

#include <iostream>
using namespace std;


//--------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------
// Poly
// Default constructor for a Poly of size 1 (0x^0)
//
// @pre: none
// @post: Creates an array of size 1 with 0 as the value

Poly::Poly() : size(1) {
    this->polyArray = new int[this->size];
    this->polyArray[0] = 0;
} // end of Default constructor


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

Poly::Poly(int coeff) : size(1) {
    this->polyArray = new int[this->size];
    this->polyArray[0] = coeff;
} // end of single parameter Constructor


//--------------------------------------------------------------------------
// Constructor with two parameters
//--------------------------------------------------------------------------
// Poly
// Constructor with two int parameters to create Poly object with size
// determined by exponent.
//
// @param coeff: the Coefficient of the x^0 term
// @param power: the degree of the polynomial, and last index of the array
// @pre: power must be >= 0 or otherwise an empty Poly object is created
// @post: Creates an array of size set to power + 1 with coeff as value for last index

Poly::Poly(int coeff, int power) {
    if (power < 0) { // Power < 0 creates an empty Poly object
        this->size = 1;
        this->polyArray = new int[this->size];
        this->polyArray[0] = 0;
    } else {                                // otherwise creates creates new Poly
        this->size = power + 1;
        this->polyArray = new int[this->size];
        for (int i = 0; i < size - 1; i++) {// fills all values to 0
            this->polyArray[i] = 0;         // up to last index
        }
        this->polyArray[power] = coeff;     // sets last index to coefficient
    }
} // end of two-parameter Constructor


//--------------------------------------------------------------------------
// Copy Constructor
//--------------------------------------------------------------------------
// Poly
// Copy constructor for Poly object, creating a deep copy
//
// @param p: parameter Poly to be copied
// @pre: Input is a Poly
// @post: Provides a deep copy of the original Poly

Poly::Poly( const Poly& p) : size(p.size) {
    this->polyArray = new int[size];
    for (int i = 0; i < size; i++) {
        this->polyArray[i] = p.polyArray[i];
    }
} // end of Copy Constructor


//--------------------------------------------------------------------------
// Destructor
//--------------------------------------------------------------------------
// ~Poly
// Destructor for Poly object.  Takes care of de-allocating array to the system.
//
// @pre: none
// @post: Deallocates array and sets array pointer to NULL

Poly::~Poly() {
    delete[] polyArray;            // cleans up memory on heap
    polyArray = NULL;              // sets array pointer to NULL
} // end of Destructor


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

int Poly::getCoeff(const int power) const {
    if (power < 0 || power >= this->size) { // If power is negative or outside
        return 0;                           // bounds of array, returns 0
    } else {
        return this->polyArray[power];      // Otherwise returns coefficient of
    }                                       // x^power term from array
} // end of getCoeff


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

bool Poly::setCoeff( const int newCoefficient, const int power ) {
    if (power < 0) {                                // checks if index is in lower range
        return false;
    } else {
        if (power < this->size) {
            this->polyArray[power] = newCoefficient;
        } else {
            int* newArray = new int[power + 1];
            for (int i = 0; i < this->size; i++) {     // copies over every element from each
                newArray[i] = this->polyArray[i];      // index in this array to new Array
            }
            for (int k = this->size; k < power; k++) { // fills all remaining values to 0
                newArray[k] = 0;                 // except last element
            }
            newArray[power] = newCoefficient;   // sets final value to new Coefficient
            
            delete[] this->polyArray;           // deallocates old array
            this->polyArray = newArray;         // and replaces with new
            newArray = NULL;
            this->size = power + 1;
        }
        return true;
    }
} // end of setCoeff


//--------------------------------------------------------------------------
// operator+
//--------------------------------------------------------------------------
// overloaded +: addition of 2 Polys, current object and parameter
//
// @param p: Poly object to be added
// @pre: none
// @post: Input Poly objects remain unchanged and summation is returned
// @return: the Poly result of the summation

Poly Poly::operator+(const Poly& p) const {
    Poly newPoly;              // creates new empty Polynomial
    if (this->size < p.size) { // check if this Poly size is less than parameter
        newPoly = p;           // copies all values of parameter to new copy
        for (int i = 0; i < this->size; i++) {  // add this coeff to new copy coeff
            newPoly.polyArray[i] += this->polyArray[i];
        }
    } else {                   // this size is greater than parameter size
        newPoly = *this;        // copies all values of this to new copy
        for (int i = 0; i < p.size; i++) { // add parameter coeff to new copy coeff
            newPoly.polyArray[i] += p.polyArray[i];
        }
    }
    return newPoly;            // return new Poly as sum
} // end of operator+


//--------------------------------------------------------------------------
// operator-
//--------------------------------------------------------------------------
// overloaded -: subtraction of 2 Polys, parameter from the current object
//
// @param p: Poly object to be subtracted
// @pre: none
// @post: Input Poly objects remain unchanged and difference is returned
// @return: the Poly result of the subtraction

Poly Poly::operator-(const Poly& p) const {
    Poly diffPoly(*this);       // creates new Poly copy to hold difference
    
    if (this->size < p.size) {  // check if this Poly size is less than parameter
        diffPoly.setCoeff(0, p.size - 1); // then increases size if needed
    }
    for (int i = 0; i < p.size; i++) { // and subtracts each value
        diffPoly.polyArray[i] -= p.polyArray[i];
    }
    return diffPoly;
} // end of operator-


//--------------------------------------------------------------------------
// operator*
//--------------------------------------------------------------------------
// overloaded *: multiplation of 2 Polys, current object and parameter
//
// @param p: Poly object to be multiplied by this
// @pre: none
// @post: Input Poly objects remain unchanged and product is returned
// @return: the Poly result of the multiplication

Poly Poly::operator*(const Poly& p) const {
    Poly newPoly(0, (size + p.size - 2)); // extra -1 to account for Constructor
    
    for (int i = 0; i < this->size; i++) { // take every term from LHS poly
        for (int j = 0; j < p.size; j++) { // and multiply by each term in RHS
            // ignores multiplying coefficients if both are zero
            if (this->polyArray[i] != 0 && p.polyArray[j] != 0) {
                newPoly.polyArray[i + j] += polyArray[i] * p.polyArray[j] ;
            }
        }
    }
    
    return newPoly;
} // end of operator*


//--------------------------------------------------------------------------
// operator==
//--------------------------------------------------------------------------
// overloaded ==: true if this Poly == parameter Poly, false if not
//
// @param p: Poly object to be compared to this
// @pre: none
// @post: returns true if this Poly == parameter polynomial
// @return the value of equivalence

bool Poly::operator==(const Poly& p) const {
    if (this->size != p.size) {                      // sizes are not the same
        if (this->size < p.size) {                   // lhs array is smaller
            for (int i = 0; i < this->size; i++) {   // iterate through array
                if (this->polyArray[i] != p.polyArray[i]) { // and check each value
                    return false;
                }
            }
        } else {                                    // rhs array is smaller
            for (int i = 0; i < p.size; i++) {      // iterate through array
                if (this->polyArray[i] != p.polyArray[i]) { // and check each value
                    return false;
                }
            }
        }
    } else {                                        // sizes are same
        for (int i = 0; i < size; i++) {            // iterate through array
            if (this->polyArray[i] != p.polyArray[i]) {   // and check each value
                return false;
            }
        }
    }
    return true;                           // returns true after all other checks
} // end of operator==


//--------------------------------------------------------------------------
// operator!=
//--------------------------------------------------------------------------
// overloaded !=: true if this Poly != parameter Poly, false if not
//
// @param p: Poly object to be compared to this
// @pre: none
// Post:  returns true if this Poly != parameter polynomial
// @return the value of non-equivalence

bool Poly::operator!=(const Poly& p) const {
    return !(*this == p);                           // utilizing == operator
} // end of operator!=


//--------------------------------------------------------------------------
// operator=
//--------------------------------------------------------------------------
// overloaded =: true if this Poly != parameter Poly, false if not
//
// @param p: Poly object to be copied
// Pre: none
// Post: Provides a deep copy of the parameter Poly and sets to RHS of this
// @return: this reference to new Poly

Poly& Poly::operator=(const Poly& p) {
    if (this != &p) {               // avoid self-assignment
        delete[] polyArray;         // deallocates old array
        this->size = p.size;
        this->polyArray = new int[size];
        for (int i = 0; i < size; i++) {    // copies Parameter array to this
            this->polyArray[i] = p.polyArray[i];
        }
    }
    return *this;
} // end of operator=


//--------------------------------------------------------------------------
// operator+=
//--------------------------------------------------------------------------
// overloaded +=: current Poly = current Poly + parameter,
//
// @param p: Poly object to be added to this
// @pre: none
// @post: Parameter Poly object remains unchanged and ref to this is returned
// @return: reference to this, post summation

Poly& Poly::operator+=(const Poly& p) {
    *this = *this + p;
    return *this;
} // end of operator+=


//--------------------------------------------------------------------------
// operator-=
//--------------------------------------------------------------------------
// overloaded -=: current Poly = current Poly - parameter,
//
// @param p: Poly object to be subtracted from this
// @pre: none
// @post: Parameter Poly object remains unchanged and ref to this is returned
// @return: reference to this, post subtraction

Poly& Poly::operator-=(const Poly& p) {
    *this = *this - p;
    return *this;
} // end of operator-=


//--------------------------------------------------------------------------
// operator*=
// overloaded *=: current Poly = current Poly * parameter,
//
// @param p: Poly object to be multiplied by this
// @pre: none
// @post: Parameter Poly object remains unchanged and ref to this is returned
// @return: reference to this, post multiplication

Poly& Poly::operator*=(const Poly& p) {
    *this = *this * p;
    return *this;
} // end of operator*=


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

ostream& operator<<( ostream &output, const Poly& p ) {
    bool nonZeroArray = false;      // in case all terms have zero coefficient
    
    for (int i = p.size - 1; i >= 0; i--) { // iterates through array from end
        if (p.polyArray[i] != 0) {          // only reads nonzero Coefficients
            nonZeroArray = true;            // array does not only contain zeroes
            
            if (p.polyArray[i] > 0) {       // determines sign and updates
                output << " +" << p.polyArray[i];
            } else {
                output << " -" << abs(p.polyArray[i]);
            }
            
            if (i > 0) {                    // all terms with power >=1 have
                output << "x";              // an x variable
            }
            
            if (i > 1) {                    // all terms with power >1 have
                output << "^" << i;         // an exponent shown
            }
        }
    }
    
    if (nonZeroArray == false) {            // check in case array is all zeroes
        output << "0";
    }
    
    return output;
} // end of operator<<


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
       
istream& operator>>( istream &input, Poly &rhs ) {
    int inputCoeff, inputPower;                     // instantiating new coeff
                                                    // and power
    do {
        input >> inputCoeff >> inputPower;          // read in from user
        if (inputCoeff != -1 && inputPower >= 0) {  //nonneg Power
            rhs.setCoeff(inputCoeff, inputPower);
        }
    } while (inputCoeff != -1 && inputPower != -1); // terminates if -1 -1
    
    return input;
} // end of operator>>
