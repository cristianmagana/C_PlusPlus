#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n)
{
    int i, x = 1;
    for (i = 1; i <= n; i++)
    {
        x *= i;
    }
    return x;
}

int main()
{
	int a_CAPACITY = 1;
	cout << "Enter a number (n) to print a sequence of permuations\n";
	cin >> a_CAPACITY;

	int a[a_CAPACITY];

	cout << "Permutation table: " << endl;
	
	for(int i = 0; i < a_CAPACITY; ++i)
		{
			a[i] = i+1;
		}
		
	for(int i = 0; i < a_CAPACITY; ++i)
		{
			cout << a[i] << " ";
		}
	
	for (int i = 0; i < factorial(a_CAPACITY) - 1; ++i)
	{
	
		cout << endl;
		
		next_permutation(a,a+a_CAPACITY);
		
		for (int i = 0; i < a_CAPACITY; ++i)
			{
				cout << a[i] << " ";
			}
		
	}
	
	
	return 0;
}
