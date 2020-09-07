#include <iostream>
#include <vector>

using std::cout;
using std::vector;

struct NotPrintable {
	int a;
	double x;
};

template<typename T>
class SimpleTemplateClass {
	T a; //private by default
	T b; //private by default
public:
	SimpleTemplateClass(const T& ai, const T& bi) :a(ai), b(bi) {}
	void printBoth() { cout << a << " " << b << "\n"; }
	T getTtype1() { return this->a; }
	T getTtype2() { return this->b; }
};

template<typename T>
T addTwo(const T& v1, const T& v2)
{
	return v1 + v2;
}

int main(int argc, char* argv[])
{
	SimpleTemplateClass<int> stc{10,3};
	stc.printBoth();
	cout << "Result: " << addTwo(10, 3) << "\n";

	SimpleTemplateClass<double> stc2{10.5,3};
	stc2.printBoth();
	cout << "Result: " << addTwo(10.5, 3.0) << "\n";

	SimpleTemplateClass<char> stc3{'x','y'};
	stc3.printBoth();
	cout << "Result: " << addTwo(stc3.getTtype1(), stc3.getTtype2()) << "\n";

	SimpleTemplateClass<std::string> stc4{ "This is","a test!" };
	stc4.printBoth();
	cout << "Result: " << addTwo(stc4.getTtype1(), stc4.getTtype2()) << "\n";
	
}
