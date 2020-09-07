#include <iostream>
#include <vector>

using namespace std; 

double reverseVector(vector<double> a)
{
	for(int i= a.size()-1; i >= 0; i--){
	
		cout << a[i] << endl; 
		
}

	for (vector<>::reverse_iterator i = a.rbegin();
		i!=a.end(); ++i)
		{
			cout  << a[i];
		}
	
}

int main() 
{
	vector<double> a = {1.0,2.0,3.0,4.0,5.0};
	
	cout << reverseVector(a) << endl;
	
}
