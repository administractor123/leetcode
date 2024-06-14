#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int romanToInt(string s)
{
	unordered_map<string, int> romanToInt{
		{"I",1},
		{"V",5},
		{"X",10},
		{"L",50},
		{"C",100},
		{"D",500},
		{"M",1000}
	};
	int num = 0;

	for (auto it = s.begin(); it != s.end(); it++)
	{
		string sub = { *it };
		string subNext = { *(it + 1) };
		if (romanToInt[sub] >= romanToInt[subNext])
		{
			num += romanToInt[sub];
		}
		else
		{
			num += romanToInt[subNext] - romanToInt[sub];
			it++;
		}
	}

	return num;
}

int main()
{
	string roman;
	cin >> roman;
	int romantoNum = romanToInt(roman);
	cout << romantoNum << endl;
}