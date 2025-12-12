#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution
{
    public:
        unordered_map<int,int> memo;
        int countDecodings(string str,int index)
        {
            if(index==str.length())
            {
                return 1;
            }
            if(str[index]=='0')
            {
                return 0;
            }
            if(memo.count(index))
            {
                return memo[index];
            }
            int totalWays=countDecodings(str,index+1);
            if(index+1<str.length())
            {
                int twoDigitNum=stoi(str.substr(index,2));

                if(twoDigitNum<=26)
                {
                    totalWays+=countDecodings(str,index+2);
                }
                
            }
            return memo[index] = totalWays;
            return totalWays;
        }

        int solve(string s)
        {
            memo.clear();
            return countDecodings(s,0);
        }

};

int main()
{
    Solution s;
    string str1 = "12";
    cout << "Ways to decode \"" << str1 << "\": " << s.solve(str1) << endl; // Expected: 2

    string str2 = "226";
    cout << "Ways to decode \"" << str2 << "\": " << s.solve(str2) << endl; // Expected: 3
    
    return 0;
}