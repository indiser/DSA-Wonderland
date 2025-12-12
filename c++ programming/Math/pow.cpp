#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        double myPow(double x, int n)
        {
            // Iterative solution
            // if(n==1)
            //     return 1.0;
            // if(x==0)
            //     return 0.0;
            // if(x==1)
            //     return 1.0;
            // if(x==-1 && n%2==0)
            //     return 1.0;
            // if(x==-1 && n%2!=0)
            //     return -1.0;
            // long binForm=n;
            // if(n<0)
            // {
            //     x=1/x;
            //     binForm=-binForm;
            // }
            // double ans=1;

            // while(binForm>0)
            // {
            //     if(binForm%2==1)
            //     {
            //         ans*=x;
            //     }
            //     x*=x;
            //     binForm /=2;
            // }
            // return ans;

            // Recursive solution
            if(n==0) 
                return 1;
            if(n<0) {
                n = abs(n);
                x = 1/x;
            }
            if(n%2==0)
                return myPow(x*x, n/2);
            else
                return x*myPow(x, n-1);
        }
};

int main()
{
    Solution s;
    cout<<s.myPow(2,10)<<endl;
    return 0;
}