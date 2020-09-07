#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <fstream>

using namespace std;


int get_mode(vector<float> &v)
{
    map<float, float> m;
    for(float i = 0; i < v.size(); ++i) m[v[i]] = 0;
    for(float i = 0; i < v.size(); ++i)
    {
        m[v[i]] += 1;
    }
    float mode = 0;
    float num_mode = 0;
    for(map<float,float>::iterator it=m.begin(); it!=m.end(); ++it)
    {
       if(it->second > mode) { mode = it->second; num_mode = it->first; }
    }
   return num_mode;
}




vector<float> myVector;

int main()
{ 
	cout << "Type in a list of 10 numbers " << endl;

	float input = 0;

	for (float i = 0; i < 10; i++) {
		cin >> input;
		myVector.push_back(input);	
	}
	cout << "You entered the numbers: " << endl;
	for (float i = 0; i < 10; i++) {
		cout << myVector[i] << " ";
		
	}
	cout << endl;
	cout << "The numbers are sorted as: " << endl;
	for (float i = 0; i < 10; i++) {
		sort(myVector.begin(), myVector.end());
		cout << myVector[i] << " ";
	}
	
	cout << endl;
	cout << "The mean value of the input is: " << endl;
	int average = accumulate( myVector.begin(), myVector.end(), 0.00)/myVector.size();
	cout << average << endl; 
	
	cout << "The median value of the input is: " << endl;
	int median = myVector[myVector.size() / 2];
	cout << median << endl;
	
	float mode;
	
	
	cout << "Searching for lucky number 3....\n";
		if (binary_search (myVector.begin(), myVector.end(), 3))
		cout << "found!\n";
			else cout << "lucky number 3 not found.\n";
			
	for(float i = 0; i < 10; ++i)
	mode = get_mode(myVector);
	cout << "The mode number is : " << mode;



    return 0;
}
	









