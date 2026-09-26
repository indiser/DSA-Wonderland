// Date: 26/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
class Solution
{
    public:
        string evaluate(string s, vector<vector<string>> &knowledge)
        {
            unordered_map<string, string> mp;
            string result = "";

            for(const auto &val: knowledge)
            {
                mp[val[0]] = val[1];
            }

            for (int i = 0; i < s.size(); i++)
            {
                if(s[i] == '(')
                {
                    int j = s.find(")", i + 1);
                    auto temp = s.substr(i + 1, j - i - 1);
                    result += mp.count(temp) ? mp[temp] : "?";
                    i = j;
                }
                else
                {
                    result += s[i];
                }
            }
            
            return result;
        }
};

int main()
{
    string str = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = {{"name", "bob"}, {"age", "two"}};

    Solution s;
    cout << s.evaluate(str, knowledge)<< endl;

    return 0;
}