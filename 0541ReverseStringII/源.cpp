#include<string>
using namespace std;

string reverseStr(string s, int k)
{
	for (auto itS = s.begin(); itS < s.end(); )
	{
		if (itS + 2 * k <= s.end())
		{
			reverse(itS, itS + k);
			itS += 2 * k;
		}
		else if (itS + 2 * k > s.end() && itS + k <= s.end())
		{
			reverse(itS, itS + k);
			itS = s.end();
		}
		else
		{
			reverse(itS, s.end());
			itS = s.end();
		}
	}
	return s;
}