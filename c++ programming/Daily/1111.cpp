// Date: 30/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        vector<int> maxDepthAfterSplit(string seq)
        {
            vector<int> ans(seq.size());
            int depth = 0;
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] == '(') {
                    ++depth;
                    ans[i] = depth % 2;
                } else {
                    ans[i] = depth % 2;
                    --depth;
                }
            }
            return ans;
        }
};

int main()
{
    string seq = "(()())";

    Solution s;
    vector<int> result = s.maxDepthAfterSplit(seq);

    for(int val: result) cout<< val<< endl;


    return 0;
}