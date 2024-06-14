#include<iostream>
using namespace std;
#include<vector>

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int n = gas.size();
	int start = 0;
	while (start < n)
	{
		int sumGas = 0;
		int sumCost = 0;
		int cnt = 0;
		while (cnt < n)
		{
			int pos = (start + cnt) % n;
			sumGas += gas[pos];
			sumCost += cost[pos];
			if (sumGas < sumCost)
			{
				break;
			}
			cnt++;
		}
		if (cnt==n)
		{
			return start;
		}
		else
		{
			start = start + cnt + 1;
		}
	}
	return -1;
}

int main()
{
	vector<int> gas = { 4,0,1 };
	vector<int> cost = { 3,2,1 };
	int start;
	start = canCompleteCircuit(gas, cost);
	cout << start;
}