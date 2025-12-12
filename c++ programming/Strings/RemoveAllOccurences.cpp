#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
    public:
        string removeOccurences(string str, string part)
        {
            while(str.length() > 0 && str.find(part) < str.length())
                str.erase(str.find(part),part.length());
            
            return str;
        }
};

int main()
{
    string str="daabcbaabcbc";
    string part="abc";
    Solution s;
    cout<<s.removeOccurences(str,part)<<endl;
    return 0;
}