#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	int n = digits.size()-1;
	int mark = 0;
	do
	{
		mark = 1;
		digits[n] += 1;
		if (digits[n] >= 10)
		{
			digits[n] = 0;
			mark = 0;
		}
		n--;
	} while (n >= 0 && mark == 0);
	if (mark==0)
	{
		digits.insert(digits.begin(), 1);
	}
	return digits;
}

int main()
{
	vector<int> arr = { 9,9};
	plusOne(arr);
	for (auto it : arr)
	{
		cout << it << " ";
	}
}