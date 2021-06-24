#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	vector<int> arr{10, 19, 6, 3, 5};
	int *ikk= find(arr.begin(), arr.end(), 5);
	// int t= 2;
	cout << ikk;
}