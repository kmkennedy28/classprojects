// a Complex object holds one Complex number
//
#include "Complex.h"
#include <iostream>
#include <math.h>
using namespace std;

// default constructor: parameters are real and imaginary parts 
Complex::Complex(double re, double im)
{
	//set each input value to the object variables
	this->re = re;
	this->im = im;
}

// add 2 complex numbers, current object and parameter
//(a + bi) + (c + di) = (a + c) + (b + d)i
Complex Complex::add(const Complex& z)
{
	//create a complex number for the result
	Complex c;

	//add each operands real and imaginary number seperately
	c.re = re + z.re;
	c.im = im + z.im;
	return c;
}

// subtract complex numbers, current object and parameter
//(a + bi) – (c + di) = (a – c) + (b – d)i
Complex Complex::subtract(const Complex& z)
{
	//complex number for the result
	Complex c;

	//subtract each real and imaginary number
	c.re = re - z.re;
	c.im = im - z.im;
	return c;
}

// multiply complex numbers, current object and parameter
//(a + bi) × (c + di) = (ac – bd) + (ad + bc)i
Complex Complex::multiply(const Complex& z)
{
	//complex number for the result
	Complex c;

	//multiply each real and imaginary number
	c.re = re * z.re - im * z.im;  
	c.im = re * z.im + im * z.re;  
	return c;
}

// dividecomplex number, current object and parameter,
// (a + bi) / (c + di) = (ac + bd) / (c^2 + d^2) + (bc – ad) / (c^2 + d^2)i
Complex Complex::divide(const Complex& z)
{
	//result complex number
	Complex c;
	//create the denominator for both (c^2 + d^2)
	double denom = z.re * z.re + z.im * z.im; 

	//breaks in the attempt to divide by zero
	//avoids crashes
	if (denom == 0)
	{
		cout << "DIVIDE BY ZERO ERROR!!!\n";
		return c;  
	}

	//divide each numerator by the denominator
	c.re = (re * z.re + im * z.im) / denom;  
	c.im = (im * z.re - re * z.im) / denom;  
	return c;
}

// equality of 2 complex numbers, current object and parameter
//(a + bi) == (c + di) ⇒ (a == c) and (b == d)
bool Complex::equal(const Complex& z)
{
	const double epsilon = 1e-9;  // Tolerance for floating-point comparison
	if (abs(re - z.re) < epsilon) {
		if ((abs(im - z.im) < epsilon)) {
			return true;
		}
	}
	return false;
}

// modulus value of a complex number
// √𝑎2 + 𝑏2
double Complex::modulus()
{
	return sqrt(re * re + im * im);
}

// print the complex number with the format: a + bi (or a - bi)
// enclosed the complex number with parenthesis if is_parenthesis is true
void Complex::print(bool is_parenthesis)
{
	Complex c;
	//prints with parenthesis if true
	if (is_parenthesis == true) {
		if (im >= 0) {
			cout << "(" << re << " + " << im << "i)";
		}
		else {
			cout << "(" << re << " - " << im << "i)";
		}
	}
	//otherwise prints without parenthesis
	else {
		if (im >= 0) {
			cout << re << " + " << im << "i ";
		}
		else {
			cout << re << " - " << im << "i ";
		}
	}
	
}