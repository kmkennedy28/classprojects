
// A Complex object holds one Complex number
#ifndef COMPLEX_H
#define COMPLEX_H
class Complex {
public:
	Complex(double re = 0.0, double im = 0.0); // default constructor
	
	bool equal(const Complex& z); //returns T/F if they are equal
	
	Complex add(const Complex& z); //adds complex numbers
	Complex subtract(const Complex& z); //subtracts complex numbers
	Complex multiply(const Complex& z); //multiplies complex numbers
	Complex divide(const Complex& z); //divides complex numbers

	double modulus(); //finds the modoulus of 2 complex numbers

	void print(bool is_parenthesis = false); //prints the complex number with correct notation
private:
	double re; // real part
	double im; // imaginary part
};
#endif