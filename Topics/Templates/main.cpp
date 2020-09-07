// main.cpp
//
// ICS 65 
// Code Example
//
// This source demonstrates calling template functions in a few ways.

#include <iostream>
#include <string>
using namespace std;

#include "Functions.h"



// This is a meaningless little test class whose important feature is the
// inability of its objects to be copied, because we've made both the
// copy constructor and the assignment operator private.  We'll use this
// class a little later in the example.
class X
{
public:
	X() { }

private:
	X(const X&);
	X& operator=(const X&);
};



void swapDemo()
{
	cout << "swapDemo" << endl;


	int i = 3;
	int j = 5;

	// One way to call a template function is to be specific about which
	// version of it you want.  Here, we're saying "Instantiate the
	// template function myswap(), putting int in place of T; compile
	// that function for me and call it here."  The compiler, of course,
	// checks the argument types to make sure they match, emitting an
	// error if they don't.  For example, if I tried to call
	// myswap<string>(i, j), I would get an error that i and j are not
	// strings.
	myswap<int>(i, j);
	printTwo<int, int>(cout, i, j);
	cout << endl;


	// The other way to call a template function -- and, in fact, this is
	// the preferred way, when you can do it (which is most of the time,
	// if the template is designed well) -- is to let the compiler deduce
	// the template's arguments for you.  In this example, the compiler
	// will discover that T could be set to "double" and it would work,
	// so it will automatically generate myswap<double> here and then
	// call it.  Similarly, it will deduce that both T1 and T2 in the
	// call to printTwo could be double, generate that and compile it,
	// as well.
	double d = 3.5;
	double e = 4.7;

	myswap(d, e);
	printTwo(cout, d, e);
	cout << endl;


	// In this case, though, the compiler will fail to be able to generate
	// a version of myswap that makes sense, because there is no one type
	// T that will be compatible with both a string and a double.  Try
	// uncommenting this and take a look at the error you get back from
	// the compiler.
	string s = "Boo";

//	myswap(s, d);
//	printTwo(cout, s, d);
//	cout << endl;


	// Finally, consider this example, where the compiler can indeed deduce
	// a type parameter for myswap (namely, our class X that's declared
	// above), but it cannot successfully compile a version of the template
	// function for X, because the template function requires the ability
	// to copy (both with a copy constructor and an assignment operator)
	// objects of whatever type its arguments are.  Try uncommenting the
	// call to myswap here and check out the error message; in particular,
	// notice that the error message points into the template function
	// itself (i.e., "When I tried to compile the template function with
	// T = X, the attempt to copy an X on this line was problematic!").
	// This is very common when you misuse templates; error messages most
	// often point right back into the templates themselves, because that's
	// where the symptom of the disconnect is.
	X x1;
	X x2;
//	myswap(x1, x2);
}



int main()
{
	swapDemo();

	return 0;
}
