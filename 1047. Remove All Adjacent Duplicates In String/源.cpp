#include<stack>
#include<string>
using namespace std;

string removeDuplicates(string s)
{
	stack<char> st;
	for (auto itS = s.begin(); itS != s.end(); itS++)
	{
		if (st.empty() || st.top() != *itS)
			st.push(*itS);
		else
			st.pop();
	}

	string res;
	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}

	reverse(res.begin(),res.end());
	return res;
}