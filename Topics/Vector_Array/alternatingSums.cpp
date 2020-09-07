#include <iostream>
#include <vector>

using namespace std; 

double alternating_sum (vector<double> a)
{
	double evenSum;
	double oddSum;
	double altSum;

	for(int i= 0; i <= a.size(); i += 2) 
	{ 
		evenSum += a[i];
	}
	
	for(int i =1; i <= a.size(); i += 2) 
	{
		oddSum += a[i] * -1;
	}
	
	altSum = evenSum + oddSum;
	return altSum;
}

int main() 
{
	vector<double> a = {1.0,2.0,3.0,4.0,5.0};
	
	cout << "The alternating sum of the vector is: " << alternating_sum(a) << endl;
	
}
