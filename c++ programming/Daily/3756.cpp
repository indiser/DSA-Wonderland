// Date: 08/07/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

// Time Complexity: O(N +  Q)
// Space Complexity: O(N +  Q)
class Solution
{
    public:
        vector<int> sumAndMultiply(string str, vector<vector<int>> &queries)
        {
            if(str.empty()) return {};
            
            int n = str.length();
            long long MOD = 1e9 + 7;
            
            vector<int> cnt(n, 0);
            vector<long long> pref_sum;
            vector<long long> pref_val;
            vector<long long> p10;
            
            pref_sum.push_back(0);
            pref_val.push_back(0);
            p10.push_back(1);
            
            int non_zero_count = 0;
            for (int i = 0; i < n; i++)
            {
                if (str[i] != '0')
                {
                    non_zero_count++;
                    long long digit = str[i] - '0';
                    pref_sum.push_back((pref_sum.back() + digit) % MOD);
                    pref_val.push_back((pref_val.back() * 10 + digit) % MOD);
                    p10.push_back((p10.back() * 10) % MOD);
                }
                cnt[i] = non_zero_count;
            }
            
            vector<int> ans;
            ans.reserve(queries.size());
            
            for (int i = 0; i < queries.size(); i++)
            {
                int start = queries[i][0];
                int end = queries[i][1];
                
                int l_idx = (start == 0) ? 0 : cnt[start - 1];
                int r_idx = cnt[end];
                
                if (l_idx == r_idx)
                {
                    ans.push_back(0);
                    continue;
                }
                
                long long cur_sum = (pref_sum[r_idx] - pref_sum[l_idx] + MOD) % MOD;
                long long cur_val = (pref_val[r_idx] - (pref_val[l_idx] * p10[r_idx - l_idx]) % MOD + MOD) % MOD;
                
                ans.push_back((cur_val * cur_sum) % MOD);
            }
            
            return ans;
        }
};

int main()
{
    string str = "10203004";
    vector<vector<int>> queries ={
        {0, 7},
        {1, 3},
        {4, 6}
    };

    Solution s;
    vector<int> result = s.sumAndMultiply(str, queries);

    for(int val: result)
    {
        cout<< val <<" ";
    }

    return 0;
}