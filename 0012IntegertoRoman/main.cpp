#include<iostream>
#include<string>
#include<vector>
using namespace std;

string intToRoman(int num)
{
	int n = 13;
	vector<string> romanStr = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	vector<int> romanNum = { 1,4,5,	9,10,40,50,90,100,400,500,900,1000 };
	string numStr;
	
	for (int i = 0; i < n; i++)
	{
		int subN = n - i - 1;
		int times = num / romanNum[subN];
		num -= romanNum[subN] * times;

		while (times)
		{
			numStr += romanStr[subN];
			times--;
		}

	}

	return numStr;
}

int main()
{
	int num = 0;
	cin >> num;
	
	string numRoman = intToRoman(num);
	cout << numRoman << endl;

}