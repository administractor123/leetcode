#include<iostream>
#include<string>
using namespace std;


bool isPalindrome(string s)
{
	string str = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]) || isalnum(s[i]))
		{
			str.push_back(tolower(s[i]));
		}
	}
	string strRe = str;
	reverse(strRe.begin(), strRe.end());
	return (str.compare(strRe) == 0) ? true : false;
}

int main()
{
	string str = "0p";
	bool a = isPalindrome(str);
	cout << a << endl;
}