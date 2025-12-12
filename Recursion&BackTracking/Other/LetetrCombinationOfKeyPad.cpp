#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

class Solution
{
    public:
        void findCombinations(const string &digits,int index, string &currentString, vector<string> &ans)
        {
            if(index==digits.length())
            {
                ans.push_back(currentString);
                return;
            }

            string letters=mapping[digits[index]-'0'];
            for (char letter:letters)
            {
                currentString.push_back(letter);
                findCombinations(digits,index+1,currentString,ans);
                currentString.pop_back();
            }
            
        }
        vector<string> generateCombinationLetters(string digits)
        {
            vector<string> ans;
            string currentString;
            findCombinations(digits,0,currentString,ans);
            return ans;
        }
};

int main()
{
    string digits="23";
    Solution s;
    vector<string> ans=s.generateCombinationLetters(digits);

    for(auto val:ans)
    {
        cout<<val<<endl;
    }
    return 0;
}