#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
	{
		int curGas = 0;
		int totalGas = 0;
		int start = 0;
		for (int i = 0; i < gas.size(); ++i)
		{
			curGas += gas[i] - cost[i];
			totalGas += gas[i] - cost[i];
			if(curGas < 0)
			{
				start = i + 1;
				curGas = 0;
			}
		}
		if(totalGas < 0)
			return -1;
		return start;		
	}
};

int main(int argc, char* argv[])
{
	return 0;
}