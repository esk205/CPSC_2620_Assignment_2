// ********************************************************************
// CPSC2620 Spring 2016
// File Name: geometricSequence.cc
// Purpose: Implementation of the geometric sequence class
// Created on: Feb 8, 2016
// Author: Michael Wynnychuk
// Notes:
// ********************************************************************
// preprocessor directives
#include <iostream>
#include "geometricSequence.h" // class definition
#include <assert.h>
using namespace std;

//*********************************************************************
// Purpose: Accepts a; r; and n as parameters and constructs an n-sized geometric
// sequence with a scale factor of a and a common ratio of r. Uses the default
// values a = r = n = 1. Store the values of the sequence in an array.
//*********************************************************************
geometricSequence::geometricSequence(int A, int R, int N){
   a = A; 
   r = R;
   n = N;
   array = new int[n]; // Creates an array of integers
   generateValues();  // generates sequence terms and inserts into array.
}
//*********************************************************************
// Purpose: Generate the terms of the sequence
//*********************************************************************
void geometricSequence::generateValues(){ // Generates sequence terms
   array[0] = a; // First term of the sequence is always the a value
   for(int i=1; i<n; i++)
      array[i] = array[i-1] * r; // Loads array with terms
}
//**************************************************************
// Method: Writes the sequence to cout with a single space between terms.
//**************************************************************
void geometricSequence::write() const{
   for (int i=0; i<n; i++){
      cout << array[i] << " "; // Displays the array terms
   }
}
//*******************************************************************
// constructor 
// parameter usage : returns the characteristics of the sequence.
//*******************************************************************
void geometricSequence::getCharacteristics(int &x, int &y, int &z) const {
   x = a; // Retrieve a value
   y = r; // Retrieve r value
   z = n; // Retrieve n value
}
//**********************************************************************
// changes the value of either a; r, or n. Note that the sequence is
// updated after each change.
//**********************************************************************
void geometricSequence::setA(int x){
   a = x; // Changes a value
   generateValues(); // generates new sequence terms 
}
void geometricSequence::setR(int y){
   r = y; // Changes r value
   generateValues(); // generates new sequence terms 
}
void geometricSequence::setN(int z){
   n = z; // Changes n value
   generateValues();  // generates new sequence terms 
}
//**************************************************************
// reads the characteristics of a geometric sequence(a, r, n order) from
// cin, creates integer array, and calls generateValues to create terms.
//***************************************************************
void geometricSequence::read() {
   int x, y, z; // declare secondary sequence characteristic variables
   cin >> x >> y >> z; // Input sequence characteristics from user.
   a = x; // Used for retrieving characteristics of sequence
   r = y; // Used for retrieving characteristics of sequence
   n = z; // Used for retrieving characteristics of sequence
   array = new int[n]; // Creates array of integers
   generateValues(); // Creates sequence terms.
}
//*********************************************************************
//  Adds one term from one sequence to another term from
//  another sequence.
//*********************************************************************
void geometricSequence::add(const geometricSequence& add){
   assert (n == add.n); // Ensures that the two arrays are the same length
   for(int i = 0; i < n; i++)
      array[i] += add.array[i]; // adds one array terms into the other array
}
//*********************************************************************
//  Multiplys one term from one sequence to another term from
//  another sequence.
//*********************************************************************
void geometricSequence::multiply(const geometricSequence& mult){
   assert (n == mult.n); // Ensures that the two arrays are the same length
   for(int i = 0; i < n; i++)
      array[i] *= mult.array[i]; // multiplys one array terms into other array
}
//*********************************************************************
// Takes the index i and returns a reference to the element in the sequence.
// Also write a version that returns a constant(for constant GeometricSequences).
// Use assert to ensure that the index is within the valid range.
//*********************************************************************
int geometricSequence::element(int i){
   assert(i <= n  && i >= 0); // Ensures the asked element exists.
   return array[i]; // returns array at index[i]
}
int geometricSequence::ConstElement(int i) const{
   assert(i <= n && i >= 0); // Ensures the asked element exists.
   return array[i]; // returns array at index[i]
}
//*********************************************************************
// Returns the summation all the terms of one geometric sequence
//*********************************************************************
int geometricSequence::sum() const{
   int sum = array[0]; 
   for(int i = 1; i < n; i++){
      sum += array[i];
   }
   return sum; // Returns the sum of all the terms
}
//*********************************************************************
// Returns the product all the terms of one geometric sequence
//*********************************************************************
int geometricSequence::product() const{
   int product = 1; 
   for(int i = 0; i < n; i++){
      product *= array[i] ;
   }
   return product; // Returns the product of all the terms
}


