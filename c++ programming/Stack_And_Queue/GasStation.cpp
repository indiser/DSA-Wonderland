#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Compelxity:O(n)
// Space Complexity:O(1)
class Solution
{
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
        {
            int totalGas=0, totalCost=0, start=0, currGas=0;
            
            for (int i = 0, len=gas.size(); i < len; i++)
            {
                totalGas+=gas[i];
                totalCost+=cost[i];
                currGas+=(gas[i]-cost[i]);

                if(currGas < 0)
                {
                    start=i+1;
                    currGas=0;
                }
            }
            return totalGas < totalCost ? -1 : start;
        }
};

int main()
{
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    
    int result = sol.canCompleteCircuit(gas, cost);
    cout << "Starting station: " << result << endl;
    
    return 0;
}