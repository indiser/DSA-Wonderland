#include<iostream>
#include<string>
using namespace std;

// leetcode-9: Palindrome Number

class Solution
{
    public:
        bool polindrom(int &x)
        {
            if(x<0)
            {
                return false;
            }
            int temp=x,n=0;
            long int rev=0;
            while(x>0)
            {
                n=x%10;
                rev=rev*10+n;
                x=x/10;
            }
            return temp==rev;
        }
};

int main()
{
    int x=121;

    Solution s;
    cout<<s.polindrom(x)<<endl;
    return 0;
}