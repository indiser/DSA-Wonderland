#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<ctype.h>
using namespace std;

class Solution
{
    public:
        vector<string> splitSentence(string str)
        {
            vector<string> ans;
            int len=str.length();
            int index=0;

            string word = "";
            for (int i = 0; i < len; i++)
            {
                if (isblank(str[i]))
                {
                    if (!word.empty())
                    {
                        ans.push_back(word);
                        word = "";
                    }
                }
                else
                {
                    word += str[i];
                }
            }
            if (!word.empty())
            {
                ans.push_back(word);
            }
            return ans;
        }
};

int main()
{
    string sentence="the cattle was rattled by the battery";
    Solution s;
    vector<string> ans=s.splitSentence(sentence);
    for(string s:ans)
    {
        cout<<s<<endl;
    }
}