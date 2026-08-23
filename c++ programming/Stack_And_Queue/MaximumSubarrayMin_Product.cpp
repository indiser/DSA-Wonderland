#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

// Time Complexity: O(n^3)
// Space Complexity: O(n)
class Solution
{
    public:
        int maxSumMinProduct(vector<int> &nums)
        {
            int len = nums.size();
            stack<vector<int>> s;
            vector<int> ans;

            for (int i = 0; i < len; i++)
            {
                for (int j = i; j < len; j++)
                {
                    ans.clear();
                    for (int k = i; k <= j; k++)
                    {
                        ans.push_back(nums[k]);
                    }
                    s.push(ans);
                }
            }

            int max_min_prod=INT_MIN;

            while(!s.empty())
            {
                vector<int> subarray = s.top();
                int min_val = subarray[0];
                for(auto &val:subarray)
                {
                    if(val < min_val)
                    {
                        min_val=val;
                    }
                }
                int sum = 0;
                for(auto &val: subarray)
                    sum+=val;
                max_min_prod = max(max_min_prod, min_val * sum);
                s.pop();
            }
            
            return max_min_prod;
        }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
class OptimizedSolution
{
    public:
        int maxSumMinProduct(vector<int> &nums)
        {
            const int MOD = 1e9+7;
            int n = nums.size();
            vector<long long> prefix(n + 1, 0);
            
            for (int i = 0; i < n; i++)
                prefix[i + 1] = prefix[i] + nums[i];
            
            vector<int> left(n), right(n);
            stack<int> st;
            
            for (int i = 0; i < n; i++)
            {
                while (!st.empty() && nums[st.top()] >= nums[i])
                    st.pop();
                left[i] = st.empty() ? 0 : st.top() + 1;
                st.push(i);
            }
            
            while (!st.empty()) st.pop();
            
            for (int i = n - 1; i >= 0; i--)
            {
                while (!st.empty() && nums[st.top()] >= nums[i])
                    st.pop();
                right[i] = st.empty() ? n - 1 : st.top() - 1;
                st.push(i);
            }
            
            long long maxProd = 0;
            for (int i = 0; i < n; i++)
            {
                long long sum = prefix[right[i] + 1] - prefix[left[i]];
                maxProd = max(maxProd, sum * nums[i]);
            }
            
            return maxProd%MOD;
        }
};

int main()
{
    vector<int> nums = {1, 2, 3, 2};

    Solution s;
    cout << "Brute Force: " << s.maxSumMinProduct(nums) << endl;
    
    OptimizedSolution opt;
    cout << "Optimized: " << opt.maxSumMinProduct(nums) << endl;
    
    return 0;
}