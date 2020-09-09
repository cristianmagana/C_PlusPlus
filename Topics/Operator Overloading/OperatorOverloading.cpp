

/********************************************/
#ifndef COMPLEXNUMBER_H_
#define COMPLEXNUMBER_H_
#include <iostream>
#include <string>
using namespace std;

class ComplexNumber {
private:
	int realPart;
	int imaginaryPart;
public:
	ComplexNumber(); //Default constructor (Initialize your class variables with default values for variables not already initialized)
	ComplexNumber(int realPart, int imaginaryPart); //A constructor that takes two integers and set them equal to the private members (realPart and imaginary part)
	void setRealPart(int realPart); //Setter for the real part of the complex number.
	int getRealPart(); //Getter for the real part of the complex number.
	void setImaginaryPart(int imaginaryPart); //Setter for the imaginary part of the complex number.
	int getImaginaryPart(); //Getter for the imaginary part of the complex number.
	
	/*When adding two complex numbers, the real part of the first one gets added to the real part of the second one. The same goes for the imaginary part 
	(1 + 2i)+(2 + 4i) = 3 + 6i. Remember you have already one of the complex number passed through the operator, the other one is your class that you're in 
	and you have to RETURN the result. */
	ComplexNumber operator+(const ComplexNumber& secondNumber);

	/*When subtracting two complex number, the real part of the second one gets subtracted from the real part of the first one (normal subtraction). The same 
	goes for the imaginary part (1 + 2i)-(2 + 4i) = -1 - 2i. Remember you have already one of the complex number passed through the operator, the other one is your 
	class that you're in and you have to RETURN the result.*/
	ComplexNumber operator-(const ComplexNumber& secondNumber);

	/*When multiplying two complex number, you must distribute them. For example, (1+2i)*(2+4i) = 1*2 + 1*4i + 2i*2 + 2i*4i = 2 + 4i + 4i + 8i^2 but because i^2 = -1 
	then the result becomes 2 + 4i + 4i + 8(-1) = 2 + 4i + 4i - 8 = -6 + 8i. Remember you have already one of the complex number passed through the operator, the other 
	one is your class that you're in and you have to RETURN the result.
	*/
	ComplexNumber operator*(const ComplexNumber& secondNumber); 

	friend ostream& operator<<(ostream& os, const ComplexNumber& cn); //Already done for you in ComplexNumber.cpp
};

#endif

/*****************************************************************************/
/*****************************************************************************/

include "ComplexNumber.h"

ComplexNumber::ComplexNumber()
{
	this->realPart = 0; 
	this->imaginaryPart = 0;
}

ComplexNumber::ComplexNumber(int realPart, int imaginaryPart)
{
	this->realPart = realPart;
	this->imaginaryPart = imaginaryPart;
}

void ComplexNumber::setRealPart(int realPart)
{
	this->realPart = realPart;
}

int ComplexNumber::getRealPart()
{
	return realPart;
}

void ComplexNumber::setImaginaryPart(int imaginaryPart)
{
	this->imaginaryPart = imaginaryPart;
}

int ComplexNumber::getImaginaryPart()
{
	return imaginaryPart;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& secondNumber)
{
	return ComplexNumber (realPart + secondNumber.realPart, getImaginaryPart() + secondNumber.imaginaryPart);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& secondNumber)
{
	return ComplexNumber(realPart - secondNumber.realPart, imaginaryPart - secondNumber.imaginaryPart);

}


/*When multiplying two complex number, you must distribute them. For example, (1+2i)*(2+4i) = 1*2 + 1*4i + 2i*2 + 2i*4i = 2 + 4i + 4i + 8i^2 but because i^2 = -1 
	then the result becomes 2 + 4i + 4i + 8(-1) = 2 + 4i + 4i - 8 = -6 + 8i. Remember you have already one of the complex number passed through the operator, the other 
	one is your class that you're in and you have to RETURN the result.
	*/

ComplexNumber ComplexNumber::operator*(const ComplexNumber& secondNumber)
{
	ComplexNumber mult;

	mult.realPart = (realPart * secondNumber.realPart) - (imaginaryPart * secondNumber.imaginaryPart);
	mult.imaginaryPart = (realPart * secondNumber.imaginaryPart) + (imaginaryPart + secondNumber.realPart);
	return mult;
}

ostream& operator<<(ostream& os, const ComplexNumber& cn)
{
	os << "The complex number is: ";
	if (cn.imaginaryPart > -1)
	{
		os << cn.realPart << "+" << cn.imaginaryPart << "i" << endl;
	}
	else
	{
		os << cn.realPart << cn.imaginaryPart << "i" << endl;
	}
	return os;
}
/**************************************************************************************/
/**************************************************************************************/

#include "ComplexNumber.h"

int main()
{

	ComplexNumber num1(1, 2);
	ComplexNumber num2(2, 4);
	ComplexNumber num3;
	ComplexNumber num4;
	ComplexNumber num5;
	num3 = num1 + num2;
	num4 = num1 - num2;
	num5 = num1 * num2;
	cout << num3;
	cout << "The complex number SHOULD BE: 3+6i" << endl;
	cout << num4;
	cout << "The complex number SHOULD BE: -1-2i" << endl;
	cout << num5;
	cout << "The complex number SHOULD BE: -6+8i" << endl;
	return 0;
}