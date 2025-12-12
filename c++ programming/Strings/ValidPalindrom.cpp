#include<iostream>
#include<vector>
#include<string.h>
#include<ctype.h>
#include<algorithm>
using namespace std;

class Solution
{
    public:
        bool validPalindrom(string &str)
        {
            int len=str.length();
            
            for (int i = 0; i < len; ++i) {
                str[i] = tolower(str[i]);
            }
            string temp="";
            for (int i = 0; i < len; i++)
            {
                if(isalnum(str[i]))
                {
                    temp.push_back(str[i]);
                }
            }
            string rev = temp;
            reverse(rev.begin(), rev.end());
            
            return (temp == rev) ? true : false;
        }
};

int main()
{
    string str="A man, a plan, a canal: panama";
    Solution s;
    cout<<s.validPalindrom(str)<<endl;
    return 0;
}