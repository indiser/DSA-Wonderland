#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;

class Solution
{
    public:
        vector<string> relativeRanks(vector<int> &scores)
        {
            int n = scores.size();
            vector<string> ans(n);
            
            priority_queue<pair<int, int>> pq;
            for(int i = 0; i < n; i++)
            {
                pq.push({scores[i], i});
            }
            
            int rank = 1;
            while(!pq.empty())
            {
                int originalIndex = pq.top().second;
                pq.pop();
                
                if(rank == 1)
                {
                    ans[originalIndex] = "Gold Medal";
                }
                else if(rank == 2)
                {
                    ans[originalIndex] = "Silver Medal";
                }
                else if(rank == 3)
                {
                    ans[originalIndex] = "Bronze Medal";
                }
                else
                {
                    ans[originalIndex] = to_string(rank);
                }
                rank++;
            }
            
            return ans;
        }
};

int main()
{
    vector<int> scores={5,4,3,2,1};
    Solution s;
    vector<string> ans=s.relativeRanks(scores);
    for(const string& val:ans)
    {
        cout<<val<<endl;
    }
}