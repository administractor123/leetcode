#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{

	if (strs.empty())
	{
		return "";
	}

	if (strs.size()==1)
	{
		return strs[0];
	}

	string strBefore;
	vector<int> strBeforeN;
	string str = strs[0];
	int n = 0;

	for (int i = 1; i < strs.size(); i++)
	{
		n = 0;
		for (int j = 0; j < strs[i].size(); j++)
		{
			if (strs[i][j] == str[j])
			{
				n++;
			}
			else
			{
				break;
			}
		}
		strBeforeN.push_back(n);
	}

	auto itMin = min_element(strBeforeN.begin(), strBeforeN.end());

	for (int i = 0; i < *itMin; i++)
	{
		strBefore += strs[0][i];
	}

	return strBefore;
}

int main()
{
	vector<string> strs = { "a","ab"};
	string str = longestCommonPrefix(strs);
	cout << str << endl;
}