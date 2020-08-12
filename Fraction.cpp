#include "Fraction.h"

Fraction::Fraction(int whole, int numerator, int denominator)
{
  if (denominator == 0) {
    cout << "ERROR: Attempt to divide by 0" << endl;
    cout << "Setting placeholder value to 1" << endl;
    this->whole = 0;
    this->numerator = 1;
    this->denominator = 1;
  }
  else {
    this->whole = whole;
    this->numerator = numerator;
    this->denominator = denominator;
    reduceAndSet();
  }
}

Fraction::Fraction(int numerator, int denominator)
{
  if (denominator == 0) {
    cout << "ERROR: Attempt to divide by 0" << endl;
    cout << "Setting placeholder value to 1" << endl;
    this->whole = 0;
    this->numerator = 1;
    this->denominator = 1;
  }
  else {
    this->whole = 0;
    this->numerator = numerator;
    this->denominator = denominator;
    reduceAndSet();
  }
}

bool Fraction::reduceAndSet()
{
  // for fractions like 100/2, 100/3
  if (this->numerator > this->denominator) {
    int wholes = 0;
    int remainder = 0;
    // fractions like 100/2
    if (this->numerator % this->denominator == 0) {
      wholes = this->numerator / this->denominator;
      this->numerator = 0;
      this->denominator = 1;
      this->whole += wholes;
      return true;
    }
    // fractions like 10/6
    else {
      wholes = this->numerator / this->denominator;
      remainder = this->numerator % this->denominator;
      this->whole += wholes;
      this->numerator = remainder;
      int gcf = 1;
      int index = 1;
      // find greatest common factor
      while (this->numerator >= index) {
        if (this->numerator % index == 0 && this->denominator % index == 0) {
          gcf = index;
        }
        index++;
      }
      this->numerator = this->numerator / gcf;
      this->denominator = this->denominator / gcf;
      return true;
    }
  }
  // fractions like 2/6 if numerator is less than denominator
  else {
    int gcf = 1;
    int index = 1;
    // find greatest common factor
    while (this->numerator >= index) {
      if (this->numerator % index == 0 && this->denominator % index == 0) {
        gcf = index;
      }
      index++;
    }
    this->numerator = this->numerator / gcf;
    this->denominator = this->denominator / gcf;
    // if the numerator and denominator are equal, add one to the whole and set the numerator to 0
    if (this->numerator == this->denominator) {
      this->whole = this->whole++;
      this->numerator = 0;
    }

    return true;
  }
}

// output overload for Fraction, prints Fraction in proper format
ostream& operator<<(ostream& os, const Fraction& theFraction)
{
  // check if the fraction is a mixed fraction
  if (theFraction.whole != 0) {
    if (theFraction.numerator == 0) {
      os << theFraction.whole;
    }
    else {
      os << theFraction.whole << "_" << theFraction.numerator << "/" << theFraction.denominator;
    }
  }
  // if the fraction does not have a whole number value, then print out in regular
  // fraction format, by this point the fraction has already been stored properly/reduced
  else {
    os << theFraction.numerator << "/" << theFraction.denominator;
  }
  return os;
}
