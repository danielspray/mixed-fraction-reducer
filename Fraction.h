#pragma once

#include <iostream>

using namespace std;

// Fraction includes a numerator and a denominator and a whole number if necessary
class Fraction
{
public:
  // no default constructor needed, will not use this

  // contructor with whole, numerator, and denominator
  Fraction(int whole, int numerator, int denominator);
  // constructor with numerator and denominator
  Fraction(int numerator, int denominator);
  // no custom destructor necessary, no dynamic data
  // ~Fraction();

  // output stream operator overload, prints the fraction in the proper format
  friend ostream& operator<<(ostream& os, const Fraction& theFraction);

private:
  // data types
  int whole;
  int numerator;
  int denominator;

  // private function as it will not be used outside the class
  // function that reduces the fraction and returns true if the fraction is valid and false if trying to divide by 0
  bool reduceAndSet();
};

