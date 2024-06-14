#include<string>
#include <iostream>
using namespace std;

string reverseWords(string s)
{
	string reS;

	bool isWord = false;
	int sIndex = s.size() - 1;

	while (sIndex >= 0)
	{
		if (!isspace(s[sIndex]) && isWord == false)
		{
			isWord = true;

			int wordLen = 0;
			while (sIndex>=0 && !isspace(s[sIndex]))
			{
				wordLen++;
				sIndex--;
			}

			for (int i = sIndex + 1; i < sIndex + wordLen + 1; i++)
			{
				reS += s[i];
			}
		}
		else if (isspace(s[sIndex]) && isWord == true)
		{
			isWord = false;
			if (sIndex >= 0)
				reS += s[sIndex--];
		}
		else
		{
			sIndex--;
		}
	}

	if (reS[reS.size() - 1] == ' ')
		reS.resize(reS.size() - 1);

	return reS;
}

int main()
{
	string str = "EPY2giL";
	str = reverseWords(str);
	
	cout << str << endl;
	return 0; 
}