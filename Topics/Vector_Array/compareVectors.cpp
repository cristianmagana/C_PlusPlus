#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_in(int element, vector<int> set)
{
	vector<int>::iterator iter;
	
	for(iter = set.begin(); iter != set.end(); ++iter)
	{
		
		if (*iter == element)

			return true;
	}
	return false;
} 

bool is_subset(vector<int> subset, vector<int> set)
{
	vector<int>::iterator iter;

	for (iter = subset.begin(); iter < subset.end(); iter++)
	{
		if (!is_in(*iter, set))
			return false;
	}
	
	return true;
}

bool same_set(vector<int> a, vector<int> b)
{
	if (!is_subset(a,b))
		return false;
	if (!is_subset(b,a))
		return false;
	return true;
}

int main()
{
	vector<int> b = {1,4,1,1,1,1,4};
	vector<int> a = {1,4};
	
	if(same_set(a,b)==true)
		cout << "True";
	else
		cout << "False";
	return 0;
}
