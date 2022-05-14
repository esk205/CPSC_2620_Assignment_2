// ********************************************************************
// CPSC2620 Spring 2016
// File Name: geometricSequence.h
// Purpose: Defines geometricSequence class
// Created on: Feb,9 2016
// Author: Michael Wynnychuk
// Notes:
// ********************************************************************

#ifndef GEOMETRICSEQUENCE_H
#define GEOMETRICSEQUENCE_H
// * Use const class-name& object to
//   specify that formal parameter object cannot be changed by the
//   functions execution.
// * Accessor methods should be declared const 
class geometricSequence
{
  public: // public data members
   // default constructor
   geometricSequence (int = 1,int = 1,int = 1); // sets a,r, n all to 1

   // input/output methods
   void read(); // reads the characteristics of "geo" sequence
   void write() const; // displays the generated sequence
  
   // set methods (Modifier methods)
   void setA(int); // changes the value of a
   void setR(int); // changes the value of r
   void setN(int); // changes the value of n
   
   // get methods (Accessor methods)
   void getCharacteristics(int &a, int &r, int &n) const; // Retrieve characteristic of sequence
   int element(int); // Returns a reference to the element in a sequence
   int ConstElement(int) const; // Returns a reference to the element in a sequence
   int sum() const; // sum up all terms of the sequence
   int product() const; // multiply all terms of the sequence
   void add(const geometricSequence&); // add sequence term to a different sequence term.
   void multiply(const geometricSequence&); // multiply sequence to a different term
   
  private:  // private data members
   int a; // the 'a' characteristic of the sequence
   int r; // the 'r' characteristic of the sequence
   int n; // the 'n' characteristic of the sequence
   int* array = nullptr; // array that holds the terms for sequence
   void generateValues(); // generate sequence terms for array 
};                                  
#endif
