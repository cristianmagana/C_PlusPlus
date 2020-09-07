
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> merge(vector<int>a, vector<int>b)
{
	auto m = min ( a.size(), b.size());
	
	vector<int> c;
	
	for (int i = 0; i < m; i++)
	{
		c.push_back(a[i]);
		c.push_back(b[i]);
		
	}
	if( m < a.size()) c.insert( c.end(), a.begin()+m, a.end());
	if( m < b.size()) c.insert( c.end(), b.begin()+m, b.end());
	
	sort(c.begin(), c.end());
	return c;
}

bool equals(vector<int>a, vector<int>b)
{
	
	bool d = equal( a.begin(), a.end(), b.begin());
	if(d)
		cout << "the vectors are equal" << endl;
	else
		cout << "the vectors are not equal" << endl;
	
}

int main()
{
	vector<int> b = {1,4,10,15};
	vector<int> a = {1,4,10,15};
	
	
	for( int v : merge(a,b) ) cout << v <<", ";
	
	equals(a,b);
	
	return 0;
}
