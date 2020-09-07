// main.cpp
//
// ICS 65 Fall 2012
// Code Example
//
// This file contains a few examples of the use (and misuse) of statically-
// and dynamically-allocated arrays.

#include <iostream>
using namespace std;



// Statically-allocated arrays are declared as local variables and are
// allocated on the run-time stack.
void usingStaticallyAllocatedArrays()
{
	cout << "Using statically-allocated arrays" << endl;

	// This is the syntax for declaring a statically-allocated array.  Note,
	// in particular, that the word "new" is not used here; instead, we simply
	// put a constant expression (i.e., an expression with a constant value)
	// in brackets after the name of the variable.
	//
	// a is allocated on the run-time stack, but its value is nonetheless,
	// technically, the address of the first element of the array.
	int a[10];

	// Accessing individual arrays cells is done with fairly unsurprising
	// syntax: following the name of the array with an expression (not
	// necessarily a constant expression) in brackets.
	a[3] = 4;
	cout << a[3] + 3 << endl;   // prints "7"
}



// This function is not necessarily portable, as its behavior depends
// explicitly on how the compiler lays out a stack frame -- which will
// differ not only from one compiler to another, but quite possibly from
// one *version* of a compiler to another, or even between different
// configurations of the *same* version of the *same* compiler.
// Your mileage may vary.
void arraysAreNotBoundsChecked_PartOne()
{
	cout << "Arrays are not bounds checked (part one)" << endl;

	// Here, we have an innocent-looking statically-allocated array of
	// 10 ints.
	int a[10];

	// And here we have an equally-innocent-looking int variable, also
	// located on the run-time stack (in the same stack frame as a).
	int b = 2;

	// And now it just gets weird... Assigning to the -3rd cell of a?
	// C++ says "No problem!"  You might get a warning from the compiler,
	// but not an error; C++ arrays are not bounds-checked at run-time,
	// so this program will run, warning or not.
	a[-3] = 14;

	// And now it gets a little weirder.  If your compiler is set up the
	// same way as mine, this will print out "14"!
	cout << b << endl;

	// But why?  Because that just happens to be, on my compiler configured
	// the way I have it configured, the location in this function's stack
	// frame where b is located: an three integers (12 bytes) lower than the
	// beginning of a.
	//
	// If this doesn't work for you, there's probably another screwy index
	// that will.  One way to figure it out is to print out the relative
	// addresses:
	cout << a << endl;
	cout << &b << endl;

	// or, better yet, to use pointer arithmetic:
	cout << (a - &b) << endl;
}



// Here are a couple of utility functions that we'll use going forward.
// One important thing to notice is that, while they accept an int pointer
// as a parameter, the pointer is actually intended to be a pointer to an
// *array* of integers.  There is no syntactic way for us to notice -- but
// the inclusion of a separate parameter that indicates a size is a clue,
// because nothing in the C++ language exposes the size of an array.
// Arrays are simply implemented as pointers to their first cells, and
// it's up to us to know whether a pointer is pointing to one value or
// an array of them; and if a pointer points to array, it's up to us to
// know that array's size, as there is no standard way to ask.
//
// Note, too, that this is true whether the array is allocated statically
// or dynamically.  So these functions can take either kind of array as an
// argument.
void zeroFill(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = 0;
	}
}


void printAll(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}



// Arrays can be passed as parameters to functions that expect pointers to the
// type of element stored in the array (e.g., an int array can be passed to a
// function expecting a pointer of type int*).
void passingArraysAsParameters()
{
	cout << "Passing arrays as parameters" << endl;

	int x[10];
	zeroFill(x, 10);
	printAll(x, 10);
}



// Pointers are memory addresses; memory addresses are numbers.  So it makes a
// certain amount of sense that we can do arithmetic with pointers.  There are
// limitations on what we're allowed to say, though.  Examples:
//
// * We can add an integer to a pointer of type T*, in which case we get a
//   new address that adds the integer *times* the size of a T to the original
//   address.  This is identical to the address calculation done when accessing
//   an array cell using the [] notation.
// * We can also subtract an integer from a pointer of type T*, which does a
//   similar address calculation -- subtracting the integer *times* the size of
//   a T from the original address.
// * We can subtract two pointers of type T* from one another, in which case we
//   get the difference in their addresses divided by the size of a T (i.e.,
//   "How many T's away from this pointer is that pointer?"
void pointerArithmeticExplained()
{
	cout << "Pointer arithmetic explained" << endl;

	int x[10];

	// Notice that the output in each case here is a memory address.  That's
	// because x is a pointer, so adding an integer to the pointer yields a
	// pointer.  On Visual Studio 2012, the size of an int is four bytes, so
	// the second output here should be four bytes greater than x, while the
	// third output should be 5*4 = 20 bytes greater than x, and the fourth
	// output should be 3*4 = 12 bytes less than x.
	cout << x << endl;
	cout << (x + 1) << endl;
	cout << (x + 5) << endl;
	cout << (x - 3) << endl;

	// Pointers can be dereferenced by preceding them with a *, so we can
	// access the individual array cells themselves like this:
	*(x + 1) = 13;
	*(x + 5) = 19;
	cout << x[1] << endl;
	cout << x[5] << endl;

	// Pointers of the same type can also be subtracted from each other.
	int* q = x + 5;
	int* r = x + 2;
	cout << (q - r) << endl;
	
	// I should point out that pointer arithmetic like this is not something
	// I find myself using very often.  It lends no advantage here, relative
	// to just using the [] operator, as the same code is going to be generated
	// either way.
}



// This is an alternative syntax for looping across an array, using pointer
// arithmetic instead of the [] notation.  The advantage here is speed --
// since the address calculation (a multiplication an addition) is avoided
// at every step, replaced by a single ++ operation at each step, which is
// significantly cheaper.
//
// Note that C++ compilers are often quite adept at recognizing the pattern
// seen in the zeroFill() function above and turning it into the pointer-
// arithmetic-based version you see below.  Optimizers can do some amazing
// things.
//
// Also, be aware that when we start talking about the collections built into
// the C++ standard library, such as vector, we'll learn about a concept
// called an "iterator".  Iterators behave just like pointers to array cells:
// you can get an iterator pointing to the beginning of a collection, test to
// see if it's reached the end, use operators like ++ and -- to move them
// around, and dereference them to access values inside the collection.
// So this pattern will show up again in that context, which is largely
// why I'm showing it to you now.
void zeroFillUsingPointerArithemtic(int* a, int size)
{
	for (int* p = a; p < a + size; p++)
	{
		*p = 0;
	}
}



void usingPointerArithmeticToLoopOverAnArray()
{
	cout << "Using pointer arithmetic to loop over an array" << endl;
	int a[10];
	zeroFillUsingPointerArithemtic(a, 10);
	printAll(a, 10);
}



// Arrays can be dynamically allocated, just as they can be statically
// allocated.  Dynamically-allocated arrays are created on the heap, as
// opposed to the run-time stack, so:
//
// (1) Their size does not have to known until run-time (i.e., a non-
//     constant expression can be used to determine their size when
//     you create one)
// (2) They live until they are explicitly destroyed using the "delete[]"
//     operator, which is the inverse of "new"ing an array.
//
// Note, also, that the result of "new"ing an array is a pointer to the
// first element of an array (e.g., int*).  Once again, pointers to
// individual objects are not distinguishable from pointers to arrays of
// objects, except from whatever other context you include (naming,
// design clues) to differentiate them yourself.
void usingDynamicallyAllocatedArrays()
{
	cout << "Using dynamically allocated arrays" << endl;

	// This is how you create a dynamically-allocated array.
	int* p = new int[10];

	// Using a dynamically-allocated array is no different from using its
	// statically-allocated cousin.  Once you've got one, the [] operator
	// or pointer arithmetic can be used.
	p[3] = 4;
	cout << (p[3] + 10) << endl;

	// When deleting an array pointed to by some pointer p, you use the
	// "delete[]" operator instead of "delete".  In general, deleting an
	// array using "delete" is undefined behavior -- it may or may not
	// work -- and deleting a single object using "delete[]" is also
	// undefined, so we have to exercise caution and be sure to use the
	// right operator, "delete" or "delete[]", in the appropriate
	// contexts.
	delete[] p;
}



int main()
{
	usingStaticallyAllocatedArrays();
	arraysAreNotBoundsChecked_PartOne();
	passingArraysAsParameters();
	pointerArithmeticExplained();
	usingPointerArithmeticToLoopOverAnArray();
	usingDynamicallyAllocatedArrays();

	return 0;
}
