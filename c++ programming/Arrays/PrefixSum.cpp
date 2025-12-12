#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    vector<int> prefixSum(vector<int> &arr)
    {
        int len=arr.size();
        vector<int> prefixSum(len,0);
        prefixSum[0]=arr[0];

        for (int i = 1; i < len; i++)
        {
            prefixSum[i]=prefixSum[i-1]+arr[i];
        }
        return prefixSum;
    }
};

int main()
{
    vector<int> arr={10,20,10,5,15};

    Solution s;

    for(int val : s.prefixSum(arr))
    {
        cout<<val<<endl;
    }
    return 0;
}