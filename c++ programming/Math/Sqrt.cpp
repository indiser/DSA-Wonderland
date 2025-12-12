#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    int squareRoot(int x)
    {
        int l=1,r=x;

        while(l<=r)
        {
            int mid=(r+l)/2;
            int mid_squared=mid*mid;

            if(mid_squared==x)
            {
                return mid;
            }
            else if(mid_squared<x)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return r;
    }
};

int main()
{
    int x=18;
    Solution s;
    cout<<s.squareRoot(x)<<endl;
}