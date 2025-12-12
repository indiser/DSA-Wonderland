#include<iostream>
#include<vector>
using namespace std;

//Mathematical Formula:nCk
class Solution
{
    public:
        void findCombinations(int n, int k, int startNum, vector<int> &currentCombinations, vector<vector<int>> &ans)
        {
            if(currentCombinations.size()==k)
            {
                ans.push_back(currentCombinations);
                return;
            }

            for (int i = startNum; i <= n; i++)
            {
                currentCombinations.push_back(i);
                findCombinations(n,k,i+1,currentCombinations,ans);
                currentCombinations.pop_back();
            }
            
        }
        vector<vector<int>> generateCombinations(int n, int k)
        {
            vector<int> currentCombinations;
            vector<vector<int>> ans;

            findCombinations(n,k,1,currentCombinations,ans);

            return ans;
        }
};

int main()
{
    int n=7,k=3;
    Solution s;
    vector<vector<int>> ans=s.generateCombinations(n,k);

    for(const auto &val:ans)
    {
        for(auto v:val)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
}