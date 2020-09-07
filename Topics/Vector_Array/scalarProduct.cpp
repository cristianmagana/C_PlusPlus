#include <iostream>
#include <vector>

using namespace std;

double scalar_product(vector<double> a, vector<double> b){
	
	double product =0;
	
	for (int i=0; i < a.size(); i++){
	
		for (int i=0; i < b.size(); i++)
			product +=  (a[i]*b[i]);
	return product;
	}
}

int main() {
	
	vector<double> a = {1.0, 2.0, 3.0, 4.0, 5.0};
	vector<double> b = {1.0, 2.0, 3.0, 4.0, 5.0};
	

	
	cout << "The scalar product of the two vectors is: "  <<scalar_product(a,b) << endl;
	
	return 0;
}
