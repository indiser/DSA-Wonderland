#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        vector<int> plusOne(vector<int> &digits)
        {
            int len=digits.size();
            digits[len-1]+=1;
            if(digits[len-1]/10==1)
            {
                digits[len-1]=digits[len-1]/10;
                digits.push_back(0);
            }
            return digits;
        }
};

int main()
{
    // cout<<10%10<<endl; ans=0
    // cout<<10/10<<endl; ans=1
    vector<int> digits={9};

    Solution s;
    vector<int> ans=s.plusOne(digits);
    for(int val:ans)
    {
        cout<<val<<endl;
    }
    return 0;
}