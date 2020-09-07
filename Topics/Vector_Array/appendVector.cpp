#include <iostream>
#include <vector>

using namespace std; 


double append_vector(vector<double>a, vector<double>b)
{
	
	copy(b.begin(), b.end(), back_inserter(a));
	
	for(int i=0; i < a.size(); ++i)
	{
		cout << a[i];
	}
}

int main() 
{
	vector<double> a = {1.0,2.0,3.0,4.0,5.0};
	vector<double> b = {5.0,4.0,3.0,2.0,1.0};
	
	append_vector(a,b);
	
	return 0;
}
